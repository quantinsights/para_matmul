## Concurrent Matrix Multiplication
---

This exercise is meant to be a small exploration of the speed-up factor attained by simple parallel matrix multiplication. The below is one of the sample outputs.

```
PS C:\Data\dev\repo\para_matmul\build> ./Debug/para_matmul.exe
Enter the dimensions of the m x n matrix a = 1000 1000
Enter the dimensions of the n x p matrix b = 1000 1000

Generating random real matrices a and b follows ...
Sequential matrix multiplication follows...
Wall clock time for single threaded matrix multiplication = 14.3062

Simple concurrent block matrix multiplication follows...

The default behavior is to divide the total work of computing 1000000 elements into8 blocks/tiles, with each tile of size  u * v, where u = 125, v = 1000
Enter Y, if you want to override the default behavior, else enter N = N

Spawning thread t(0,0)
Spawning thread t(1,0)
Spawning thread t(2,0)
Spawning thread t(3,0)
Spawning thread t(4,0)
Spawning thread t(5,0)
Spawning thread t(6,0)
Spawning thread t(7,0)
Wall clock time for multi threaded matrix multiplication = 4.72149
```