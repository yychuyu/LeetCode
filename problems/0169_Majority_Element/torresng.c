/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/12
*
***************************************************************/
/**************************************************************
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

    Input: [3,2,3]
    Output: 3

Example 2:

    Input: [2,2,1,1,1,2,2]
    Output: 2
***************************************************************/
#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int res, count = 0;
    for(int i = 0; i < numsSize; i++) {
        if(count == 0) {
            res = nums[i];
            count = 1;
        } else {
            count += (res == nums[i]) ? 1 : -1;
        }
    }
    return res;
}

int main(void) {
    int nums1[] = {3,2,3};
    int numsSize = 3;
    printf("Input: [3,2,3]\nOutput: %d\n", majorityElement(nums1, numsSize));
    int nums2[] = {2,2,1,1,1,2,2};
    numsSize = 7;
    printf("Input: [2,2,1,1,1,2,2]\nOutput: %d\n", majorityElement(nums2, numsSize));
    return 0;
}


