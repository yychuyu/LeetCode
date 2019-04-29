/*
 * ZigZag Conversion.c
 *
 * April 29,2019 
 *
 * Author:lkk789@aliyun.com
 *
 */
 
 /*
 将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P A H N
A P L S I I G
Y I R

之后从左往右，逐行读取字符： "PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);

示例 1:

输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"

示例 2:

输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P I N
A L S I G
Y A H R
P I
 */


/**
* ZigZag Conversion
* Z字形变换
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char* convert(char* s, int numRows)
{
    if (numRows <= 1) return s;


    int len = strlen(s);
    char *new_str = malloc(len + 1);    
    char *p = new_str;
    int row = 0;
    for (row = 0; row < numRows; row++) {
        int interval1 = numRows + (numRows - 2) - row * 2;
        int interval2 = 2 * row;
        int flag = 0;
        int i = row;
        while (i < len) {
            *p++ = s[i];
            int delta = 0;
            do {
                delta = flag == 0 ? interval1 : interval2;
                flag = !flag;
            } while (delta == 0);
            i += delta;
        }
    }


    new_str[len] = '\0';
    return new_str;
}


int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "./test string num\n");
        exit(-1);
    }


    printf("%s\n", convert(argv[1], atoi(argv[2])));
    return 0;
}
