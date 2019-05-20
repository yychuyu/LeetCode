
/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *nums_ret;
    nums_ret = NULL;
    for(int i = 0; i < numsSize - 1 && nums_ret == NULL; ++i){
        for(int j = i + 1; j < numsSize && nums_ret == NULL; ++j){
            if(nums[i] + nums[j] == target){
                nums_ret = malloc(sizeof(int) * 2);
                nums_ret[0] = i;
                nums_ret[1] = j;
                *returnSize = 2;
            }
        }
    }
    return nums_ret;
}





