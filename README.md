## Concurrent Matrix Multiplication
---

This exercise is meant to be a small exploration of the speed-up factor attained by simple parallel matrix multiplication. The below is one of the sample outputs.

```
PS C:\Data\dev\repo\para_matmul\build> ./Debug/para_matmul.exe
Enter the dimensions of the m x n matrix a = 1000 1000
Enter the dimensions of the n x p matrix b = 1000 1000

Generating random real matrices a and b follows ...
Sequential matrix multiplication follows...
Wall clock time for single threaded matrix multiplication = 14.3709

Simple concurrent block matrix multiplication follows...
Enter tile width and tile height = 100 100

Wall clock time for multi threaded matrix multiplication = 5.12784
PS C:\Data\dev\repo\para_matmul\build>
```