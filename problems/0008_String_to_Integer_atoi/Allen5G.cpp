/*
 * Reverse Integer.cpp
 *
 * May,5 2019 
 *
 * Author:lkk789@aliyun.com
 *
 */
 
 /*
实现 atoi ，将字符串转为整数。
在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。
当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
若函数不能执行有效的转换，返回 0。
说明：
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2 31 ,  2 31 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (2 31 − 1) 或 INT_MIN (−2 31 ) 。
示例 1:

输入: "42"
输出: 42

示例 2:

输入: " -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
  我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

示例 3:

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。

示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
  因此返回 INT_MIN (−231) 。

 */


/**
* String to Integer (atoi)
* 字符串转整数 (atoi)
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define INT_MIN     (-2147483647 - 1)
#define INT_MAX      2147483647
int atoi(const char *str) {
    if (str==NULL || *str=='\0'){
        return 0;
    }
    
    int ret=0;
    
    for(;isspace(*str); str++);
    
    bool neg=false;
    if (*str=='-' || *str=='+') {
        neg = (*str=='-') ;
        str++;
    }
    
    for(; isdigit(*str); str++) {
        int digit = (*str-'0');
        if(neg){
            if( -ret < (INT_MIN + digit)/10 ) {
                return INT_MIN;
            }
        }else{
            if( ret > (INT_MAX - digit) /10 ) {
                return INT_MAX;
            }
        }
        ret = 10*ret + digit ;
    }
    
    return neg?-ret:ret;
}
int main()
{
    printf("\"%s\" = %d\n", "123", atoi("123"));
    printf("\"%s\" = %d\n", "   123", atoi("    123"));
    printf("\"%s\" = %d\n", "+123", atoi("+123"));
    printf("\"%s\" = %d\n", " -123", atoi(" -123"));
    printf("\"%s\" = %d\n", "123ABC", atoi("123ABC"));
    printf("\"%s\" = %d\n", " abc123ABC", atoi(" abc123ABC"));
    printf("\"%s\" = %d\n", "2147483647", atoi("2147483647"));
    printf("\"%s\" = %d\n", "-2147483648", atoi("-2147483648"));
    printf("\"%s\" = %d\n", "2147483648", atoi("2147483648"));
    printf("\"%s\" = %d\n", "-2147483649", atoi("-2147483649"));
    return 0;
}