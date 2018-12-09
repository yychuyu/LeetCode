/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/1
*
***************************************************************/
/**************************************************************
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    1. You must do this in-place without making a copy of the array.
    2. Minimize the total number of operations.
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) {
    size_t zero_num = 0;
    for(int idx = 0, i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[idx] = nums[i];
            idx++;
        } else {
            zero_num++;
        }
    }
    while(zero_num) {
        nums[numsSize - zero_num] = 0;
        zero_num--;
    }
}

char* join(int* nums, int numsSize, char sep) {
    size_t alloc_size = sizeof(char) * 128;
    char *str= (char*)malloc(alloc_size);
    int i=0;
    int index = 0;
    index += sprintf(&str[index], "[");
    for (i=0; i<numsSize; i++)
        index += sprintf(&str[index], "%d,", nums[i]);
    str[index-1] = ']';
    return str; 
}

int main(void) {
    int nums[] = {0,1,0,3,12};
    size_t size = 5;
    moveZeroes(nums, size);
    char* str = join(nums, size, ',');
    printf("Input: [0,1,0,3,12]\nOutput: %s\n", str);

    return 0;
}
