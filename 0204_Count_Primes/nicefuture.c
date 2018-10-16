#include <stdio.h>

int countPrimes(int n) {
    int i, j, cnt = 0;
    
    for (i = 2; i < n; i++) {
        for (j = 2; j*j < i; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j*j > i) {
            printf("%d ", i);
            cnt++;
        }
    }

    return cnt;
}

//个人测试用例
int main(void)
{
    int num;
    scanf("%d", &num);

    int cnt = countPrimes(num);
    printf("\n%d\n", cnt);

    return 0;
}

