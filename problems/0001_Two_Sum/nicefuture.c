#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int i, j, tar, flag = 0;

    for (i = 0; i < numsSize; i++) {
        tar = target - nums[i];
        for (j = i+1; j < numsSize; j++) {
            if (nums[j] == tar) break;
        }
        if (j < numsSize) break;
    }

    int *result = (int*) malloc(sizeof(int)*2);
    result[0] = i;
    result[1] = j;

    return result;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int i, nums[n];
    for (i = 0; i < n; i++) scanf("%d", &nums[i]);

    int target;
    scanf("%d", &target);

    int *result = twoSum(nums, n, target);
    printf("%d %d\n", result[0], result[1]);

    return 0;
}
