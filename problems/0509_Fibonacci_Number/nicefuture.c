// 递归
// Runtime: 12 ms
// Memory Usage: 6.9 MB
int fib(int N){
    if (N == 0) return 0;
    if (N == 1) return 1;
    return fib(N-1)+fib(N-2);
}
