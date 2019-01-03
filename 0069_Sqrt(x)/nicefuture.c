//牛顿迭代法
int mySqrt(int x) {
    double xnn = x, xn = x;
    if (x == 0) return 0;
    do {
        xn = xnn;
        xnn = 1.0/2*xn + (x*xn)/(2*xn*xn);
    } while (xn-xnn > 0.00001);
    
    return (int)xnn;
}

//"皮一皮"法
/*
 *int mySqrt(int x) {
 *    return (int)sqrt(x);
 *}
 */
