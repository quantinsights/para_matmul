## Concurrent Matrix Multiplication
---

This exercise is meant to be a small exploration of the speed-up factor attained by simple parallel matrix multiplication. The below is one of the sample outputs.

```
  main.cpp
  para_matmul.vcxproj -> C:\Data\dev\repo\para_matmul\build\Debug\para_matmul.exe
PS C:\Data\dev\repo\para_matmul\build> ./Debug/para_matmul.exe
Enter the dimensions of the m x n matrix a = 3 3
Enter the dimensions of the n x p matrix b = 3 3

Generating random real matrices a and b follows ...
Sequential matrix multiplication follows...
Wall clock time for single threaded matrix multiplication = 1.8e-06
Simple concurrent block matrix multiplication follows...
Enter tile width and tile height = 1 1

Spawning thread t(0,0)
Spawning thread t(0,1)
Spawning thread t(0,2)
Spawning thread t(1,0)
Spawning thread t(1,1)
Spawning thread t(1,2)
Spawning thread t(2,0)
Spawning thread t(2,1)
Spawning thread t(2,2)
PS C:\Data\dev\repo\para_matmul\build> cmake --build .        
MSBuild version 17.8.3+195e7f5a3 for .NET Framework

  main.cpp
C:\Data\dev\repo\para_matmul\src\main.cpp(118,10): error C2371: 'start': redefinition; different basic types [C:\Data\dev\repo\para_matmul\build\para_matmul.vcxproj]
  C:\Data\dev\repo\para_matmul\src\main.cpp(92,10):
  see declaration of 'start'

C:\Data\dev\repo\para_matmul\src\main.cpp(138,10): error C2371: 'end': redefinition; different basic types [C:\Data\dev\repo\para_matmul\build\para_matmul.vcxproj]
  C:\Data\dev\repo\para_matmul\src\main.cpp(94,10):
  see declaration of 'end'

C:\Data\dev\repo\para_matmul\src\main.cpp(139,35): error C2374: 'time_taken': redefinition; multiple initialization [C:\Data\dev\repo\para_matmul\build\para_matmul.vcxproj]
  C:\Data\dev\repo\para_matmul\src\main.cpp(95,35):
  see declaration of 'time_taken'

C:\Data\dev\repo\para_matmul\src\main.cpp(139,52): error C2088: '-': illegal for class [C:\Data\dev\repo\para_matmul\build\para_matmul.vcxproj]
PS C:\Data\dev\repo\para_matmul\build> cmake --build .
MSBuild version 17.8.3+195e7f5a3 for .NET Framework

  main.cpp
  para_matmul.vcxproj -> C:\Data\dev\repo\para_matmul\build\Debug\para_matmul.exe
PS C:\Data\dev\repo\para_matmul\build> ./Debug/para_matmul.exe
Enter the dimensions of the m x n matrix a = 3 3
Enter the dimensions of the n x p matrix b = 3 3

Generating random real matrices a and b follows ...
Sequential matrix multiplication follows...
Wall clock time for single threaded matrix multiplication = 1.1e-06

Simple concurrent block matrix multiplication follows...
Enter tile width and tile height = 1 1

Spawning thread t(0,0)
Spawning thread t(0,1)
Spawning thread t(0,2)
Spawning thread t(1,0)
Spawning thread t(1,1)
Spawning thread t(1,2)
Spawning thread t(2,0)
Spawning thread t(2,1)
Spawning thread t(2,2)
Wall clock time for multi threaded matrix multiplication = 0.0050031
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