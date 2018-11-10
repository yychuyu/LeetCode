#include <stdio.h>
#include <limits.h>

/*
//解法１，两个循环
int reverse(int x) {
    int num[10], cnt = 0;
    while (x != 0) {
        num[cnt] = x % 10;
        x /= 10;
        cnt++;
    }
    int i;
    long result = 0;
    for (i = 0, cnt--; i <= cnt; i++) {
        result += num[i] * pow(10, cnt-i);
    }
    
    return (result > INT_MAX || result < INT_MIN) ? 0 : (int)result;
}
*/

//解法二，一个循环
int reverse(int x) {
    long result = 0;
    
    while (x != 0) {
        result = (result*10) + (x % 10);
        x /= 10;
        if (result > INT_MAX || result < INT_MIN) {
            result = 0;
            break;
        }
    }
    
    return result;
}

int main(void)
{
    printf("123 --> %d\n", reverse(123));

    return 0;
}
