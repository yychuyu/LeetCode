/*************************************************************************
 * 给定一个 32 位有符号整数，将整数中的数字进行反转。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。
 * 根据这个假设，如果反转后的整数溢出，则返回 0。
**************************************************************************/


#include<stdio.h>
#include<limits.h>

int reverse(int x) {
    int pop;
    int result = 0;
    while(x!=0)
    {
        pop = x%10;
        if(result > INT_MAX/10 || (result == INT_MAX/10 && pop>7)) return 0 ;
        if(result < INT_MIN/10 || (result == INT_MIN/10 && pop < -8)) return 0;
        result = result * 10 + pop;
        x = x / 10;
    }
    return result;
    
    
    
}

int main()
{
    int output = reverse(123);
    printf("%d",output);
}