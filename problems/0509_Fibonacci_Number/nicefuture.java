// 循环
// Runtime: 0 ms
// Memory Usage: 6.7 MB
int fib(int N){
    if (N == 0) return 0;
    if (N == 1) return 1;
    int a = 0, b = 1, c = 0;
    for (int i=2; i<=N; i++) {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}
