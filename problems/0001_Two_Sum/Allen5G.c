/*
 * two_sum.c
 *
 * july 22,2009 
 *
 * Author:lkk789@aliyun.com
 *
 */
 
 /*
 
  Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 */
 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int subNum = 0;
    static int p[2]={0};

    for(i=0;i<numsSize-1;i++){
        subNum = target - nums[i];
        for(j=i+1;j<numsSize;j++)
        if(nums[j] == subNum){
            p[0]=i;
            p[1]=j;
            return p;
        }
    }
    return 0;
}

 