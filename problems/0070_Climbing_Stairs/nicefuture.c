//即斐波那契数列
int climbStairs(int n) {
    int a = 0, b = 1, i = 0;
    while (i < n) {
        int s = a + b;
        a = b;
        b = s;
        i++;
        printf("%d ", s);
    }
    return b;
}
