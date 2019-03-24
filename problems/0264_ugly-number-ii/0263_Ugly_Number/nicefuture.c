#include <stdio.h>
#include <stdbool.h>

bool isUgly(int num) {
    while (num != 1) {
        if ( num < 1 || (num % 2 != 0 && num % 3 != 0 && num % 5 != 0)) {
            return false;
        }
        if (num % 2 == 0) {
            num /= 2;
        }
        if (num % 3 == 0) {
            num /= 3;
        }
        if (num % 5 == 0) {
            num /= 5;
        }
    }
    return true;
}

//¸öÈË²âÊÔÓÃÀý
int main(void)
{
    int num;
    scanf("%d", &num);

    char *flag = ( isUgly(num)==true ) ? "true" : "false";
    printf("%s \n", flag);

    return 0;
}
