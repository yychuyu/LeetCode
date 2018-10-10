/*
 * author: NICE-FUTURE
 * time: 2018.10.10 18:27
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
    int i = 0;

    while (i < numsSize-1){
        if (nums[i] == nums[i+1]) {
            delete(nums, &numsSize, i+1);
        } else {
            i++;
        }
    }

    return numsSize;
}


//以下为个人测试用例
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
