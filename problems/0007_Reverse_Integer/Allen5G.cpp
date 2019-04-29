/*
 * Reverse Integer.cpp
 *
 * April 29,2019 
 *
 * Author:lkk789@aliyun.com
 *
 */
 
 /*
 给定一个 32 位有符号整数，将整数中的数字进行反转。
示例 1:

输入: 123
输出: 321
示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2 31 ,  2 31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
 */


/**
* Reverse Integer
* 反转整数
*/


#include <stdio.h>
#include <stdlib.h>
#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)
int reverse(int x) {
    int y=0;
    int n;
    while( x != 0){
        n = x%10;
        if (y > INT_MAX/10 || y < INT_MIN/10){
             return 0;
        }
        y = y*10 + n;
        x /= 10;
    }
    return y;
}
#define TEST(n, e)  printf("%12d  =>  %-12d    %s!\n",  n, reverse(n),  e == reverse(n)?"passed":"failed")
int main(int argc, char**argv)
{
    //basic cases
    TEST(  123,  321);
    TEST( -123, -321);
    TEST( -100,   -1);
    TEST( 1002, 2001);
    //big integer
    TEST( 1463847412,  2147483641);
    TEST(-2147447412, -2147447412);
    TEST( 2147447412,  2147447412);
    //overflow
    TEST( 1000000003, 0);
    TEST( 2147483647, 0);
    TEST(-2147483648, 0);
    //customized cases
    if (argc<2){
        return 0;
    }
    printf("\n");
    for (int i=1; i<argc; i++) {
        int n = atoi(argv[i]);
        printf("%12d  =>  %-12d    %s!\n",  n, reverse(n), reverse(reverse(n))==n ? "passed":"failed");
    }
    return 0;
}