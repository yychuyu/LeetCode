#include <stdio.h>
#include <limits.h>

int myAtoi(char* str) {
    char c;
    int i=0, s=0, minus=0, front=1;
     
    while ((c=str[i])!= '\0') {
        if (front && c == ' ');  //去除空格前缀
        else if (front && c == '+') {  //区分正负，且判断形如 "+-2" 的形式为非法
            front = 0;
        }
        else if (front && c == '-') {
            minus = 1;
            front = 0;
        }
        else if (c >= '0' && c <= '9') {  //检查是否将要溢出
            if (!minus && (s > INT_MAX/10 || (s == INT_MAX/10 && (c-'0') >= INT_MAX%10))) {
                return INT_MAX;
            }   
            else if (minus && ((-1)*s < INT_MIN/10 || ((-1)*s == INT_MIN/10 && (-1)*(c-'0') <= INT_MIN%10))) {
                return INT_MIN;
            }   
            s = s*10 + (c-'0');
            front = 0;
        }   
        else break;
        i++;
    }          
    s *= minus ? -1 : 1;
    return s;
}
