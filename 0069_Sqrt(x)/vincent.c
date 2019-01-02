/********************************************************
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 方法：使用牛顿迭代法。
*********************************************************/

#include<stdio.h>

int mySqrt(int x);

int main(int argc, char const *argv[])
{
    int result = mySqrt(4);
    printf("%d",result);
    return 0;
}

int mySqrt(int x) {
    if(x <= 1) return x;
    long long int r = x;
    while (r > x / r)
    {
        r = (r + x / r) /2;
    }
    return r;
}
