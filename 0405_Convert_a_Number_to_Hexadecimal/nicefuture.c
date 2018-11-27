#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char* toHex(int num) {
    char* hex = (char*) malloc(sizeof(char*) * 8);

    long long num1 = (num < 0) ? ((long long)pow(2, 32) + num) : num;  //num1为补码

    int i = 0;
    while (num1 > 0) {
        int t = num1%16;
        hex[i] = (t < 10) ? ((char)(t+48)) : ((char)(t+87));
        num1 /= 16;
        i++;
    }
    if (i == 0) {  //为0时
        hex[i] = '0';
        i++;
    }
    hex[i] = '\0';

    int j;
    char t;
    for (j = 0; j < i/2; j++) {  //字符串反转
        if (hex[j] != hex[i-1-j]) {
            t = hex[j];
            hex[j] = hex[i-1-j];
            hex[i-1-j] = t;
        }
        
    }

    return hex;
}

int main(void)
{
    int num = 0;

    char* hex = toHex(num);

    printf("%s\n", hex);

    return 0;
}
