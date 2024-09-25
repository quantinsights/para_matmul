#include<iostream>
#include <vector>
#include <random>
#include <assert.h>
#include <thread>
#include <chrono>

// Sequential matrix multiplication 
template <class T>
void matmul(std::vector<std::vector<T>>& a, std::vector<std::vector<T>>& b, std::vector<std::vector<T>>& c,
int resultBlockMatrixDim1Low, int resultBlockMatrixDim1Hi,  // resultBlockMatrixDim1Low <= i <= resultBlockMatrixDim1Hi
int resultBlockMatrixDim2Low, int resultBlockMatrixDim2Hi)  // resultBlockMatrixDim2Low <= j <= resultBlockMatrixDim2Hi
{
    int commonDim = a[0].size();
    for(int i{resultBlockMatrixDim1Low}; i<=resultBlockMatrixDim1Hi; ++i)
    {
        for(int k{0}; k<commonDim; ++k)
        {
            for(int j{resultBlockMatrixDim2Low};j<=resultBlockMatrixDim2Hi; ++j)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

template <class T>
void displayMatrix(std::vector<std::vector<T>>& x)
{
    int m = x.size();
    int n = x[0].size();

    std::cout.precision(4);
    for(int i{0}; i < m ; ++i)
    {
        for(int j{0}; j < n; ++j)
        {
            std::cout << x[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int main()
{
    //Generation of random numbers
    const double range_from {0.0};
    const double range_to {1.0};
    std::random_device random_dev;
    std::mt19937 generator {random_dev()};
    std::uniform_real_distribution<double> dist{range_from, range_to};
    int m, n1, n2, n, p;

    //Lambda function that returns a real random number in [0,1]
    auto gen = [&](){
        return dist(generator);
    };

    std::cout << "Enter the dimensions of the m x n matrix a = ";
    std::cin >> m >> n1;
    std::cout << "Enter the dimensions of the n x p matrix b = ";
    std::cin >> n2 >> p;
    assert(m > 0);
    assert(n1 == n2);
    assert(p > 0);

    n = n1;

    std::cout << "\nGenerating random real matrices a and b follows ...";
    
    std::vector<std::vector<double>> a(m); 
    for(int i{0};i<m;++i)
    {
        std::vector<double> row(n);
        std::generate(row.begin(),row.end(),gen);
        a[i] = row;
    }

    std::vector<std::vector<double>> b(n); 
    for(int i{0};i<n;++i)
    {
        std::vector<double> row(p);
        std::generate(row.begin(),row.end(),gen);
        b[i] = row;
    }

    //Sequential matrix multiplication
    std::cout << "\nSequential matrix multiplication follows...";
    std::vector<double> row(p, 0.0);
    std::vector<std::vector<double>> c(m, row);

    auto start = std::chrono::high_resolution_clock::now();
    matmul(a, b, c, 0, m-1, 0, p-1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_taken = end - start;
    std::cout << "\nWall clock time for single threaded matrix multiplication = " << time_taken.count();

    //Simple concurrent block matrix multiplication
    int u {m};
    int v {p};
    std::cout << "\n\nSimple concurrent block matrix multiplication follows...";
    std::cout << "\nEnter tile width and tile height = ";
    std::cin >> u >> v;

    /* The result matrix c is divided into tiles each of size u x v and the computation of
       tile(i,j) is sent to thread(i,j). The number of iterations = max_iter_x * max_iter_y where:
       
       max_iter_x = (floor(m / u) + (m % u == 0 ? 0 : 1)) 
       max_iter_y = (floor(p /v) + (n % v == 0 ? 0 : 1))

       So, we create a vector of vector of threads. 
    */
    int max_iter_x {static_cast<int>(floor(m / u) + (m % u == 0 ? 0 : 1))};
    int max_iter_y {static_cast<int>(floor(p /v) + (n % v == 0 ? 0 : 1))};

    std::vector<std::vector<std::thread>> threads;

    start = std::chrono::high_resolution_clock::now();

    for(int i{0};i< max_iter_x; ++i)
    {
        std::vector<std::thread> vectorOfThreads {};
        int max_row = (i == max_iter_x - 1) ? m - 1 : (i+1) * u - 1; 
        for(int j{0}; j<max_iter_y; ++j)
        {
            int max_col = (j == max_iter_y - 1) ? p - 1 : (j+1) * v - 1;
            std::cout << "\nSpawning thread t(" << i << "," << j << ")";
            //std::thread t(matmul<double>, std::ref(a), std::ref(b), std::ref(c), i * u, max_row, j * v, max_col);
            vectorOfThreads.push_back(std::thread(matmul<double>, std::ref(a), std::ref(b), std::ref(c), i * u, max_row, j * v, max_col));
        }
        threads.push_back(std::move(vectorOfThreads));
    }

    for(int i{0};i<max_iter_x;++i)
        for(int j{0};j<max_iter_y;++j)
            threads[i][j].join();

    end = std::chrono::high_resolution_clock::now();
    time_taken = end - start;
    std::cout << "\nWall clock time for multi threaded matrix multiplication = " << time_taken.count();

    //Display results
    // std::cout << "\nMatrix a =" << "\n";
    // displayMatrix(a);
    // std::cout << "\nMatrix b =" << "\n";
    // displayMatrix(b);
    // std::cout << "\nMatrix c =" << "\n";
    // displayMatrix(c);

    return 0;

}