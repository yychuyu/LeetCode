#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numsSize) {
    int i;
    int a[10000] = {0};
    for (i = 0; i < numsSize; i++) {
        a[nums[i]] = 1;
    }
    for (i = 0; i < numsSize + 1; i++) {
        if (a[i] != 1)
            return i;
    }
    return -1;
}

int main()
{
    int a[10] = {0, 2, 3, 1, 5, 6, 4, 7, 8, 9};
    printf("%d", missingNumber(a, 10));
    return 0;
}
