/*
author: NiceFuture
time  : 2018.10.10
*/

#include <stdio.h>

void delete(int* nums, int* numsSize, int index) 
{
    int i;

    for (i = index; i < (*numsSize)-1; i++) {
        nums[i] = nums[i+1];
    }
    (*numsSize)--;
}

int removeDuplicates(int* nums, int numsSize) {
    int i, cur = nums[0];

    for (i = 1; i < numsSize; i++) {
        if (nums[i] == cur) {
            delete(nums, &numsSize, i);
            i--;
        } else {
            cur = nums[i];
        }
    }

    return numsSize;
}

//----------------------------------------------
//个人测试用例
int main(void)
{
    int n;
    scanf("%d", &n);

    int i, nums[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int len = removeDuplicates(nums, n);

    for (i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n%d\n", len);

    return 0;
}
