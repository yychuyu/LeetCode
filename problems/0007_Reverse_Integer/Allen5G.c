/*
 * Reverse Integer.c
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
#include <limits.h>


static int reverse(int x)
{
    int y = 0;
    while (x != 0) {
        int n = x % 10;
        // Checking the over/underflow.
        // Actually, it should be y>(INT_MAX-n)/10, but n/10 is 0, so omit it.
        if (y > INT_MAX / 10 || y < INT_MIN / 10) {
            return 0;
        }
        y = y * 10 + n;
        x /= 10;
    }
    return y;
}


#define TEST(n, e)  printf("%12d  =>  %-12d  %s!\n",  n, reverse(n),  e == reverse(n)?"passed":"failed")


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
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test i\n");
        return 0;
    }
    printf("\n");
    int n = atoi(argv[1]);
    printf("%12d  =>  %-12d  %s!\n",  n, reverse(n), reverse(reverse(n))==n ? "passed":"failed");
    return 0;
}