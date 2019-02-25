/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     Torres Ng
*   Create Time 2018/12/10
*
***************************************************************/
/**************************************************************
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

    Your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution and you may not use the same element twice.

Example:

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *res = (int*)malloc(sizeof(int) * 2);
    int i = 0, j = numbersSize - 1;
    while(numbers[i] + numbers[j] != target) {
        if(numbers[i] + numbers[j] > target) {
            j--;
        } else {
            i++;
        }
    }
    *returnSize = 2;
    res[0] = i + 1;
    res[1] = j + 1;
    return res;
}

int main(void) {
    int numbers[] = {2,7,11,15};
    int numbersSize = 4;
    int target = 9;
	printf("Input: numbers = [2,7,11,15], target = 9\nOutput: ");
    int returnSize;
    int *res = twoSum(numbers, numbersSize, target, &returnSize);
    printf("[%d,%d]\n", res[0], res[1]);
    free(res);
	return 0;
}


