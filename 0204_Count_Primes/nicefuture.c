#include <stdio.h>

/*
//改进前代码
int countPrimes(int n) {
    int i, j, cnt = 0;
    
    for (i = 2; i < n; i++) {
        for (j = 2; j*j < i; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j*j > i) {
            //printf("%d ", i);
            cnt++;
        }
    }

    return cnt;
}
*/

//改进后 "https://en.m.wikipedia.org/wiki/Sieve_of_Eratosthenes"
int countPrimes(int n) {
    int cnt = 0, i, j, notEnd = 1;

    int nums[n+2];
    for (i = 0; i < n+2; i++) nums[i] = 1;
    nums[0] = nums[1] = 0;

    for (i = 0; i < n; i++) {
        if (i*i >= n) notEnd = 0;
        if (nums[i] == 0) continue;
        for (j = i+i; notEnd && j < n; j += i) {
            nums[j] = 0;
        }
        cnt++;
        //printf("%d ", i);
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

