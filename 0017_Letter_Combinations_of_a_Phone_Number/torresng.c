/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/13
*
***************************************************************/
/**************************************************************
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

Example:

    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
***************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *idx[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    size_t n = strlen(digits);
    size_t alloc_size = 1;
    for(int i = 0; i < n; i++) {
        alloc_size *= strlen(idx[digits[i] - '0']);
    }
    //char *res = (char*)malloc(alloc_size);
    char **res = (char**)malloc(sizeof(char*) * (alloc_size+1));

    
    return res;
}

char* join(char** arr, int numsSize, char sep) {
    size_t alloc_size = sizeof(char) * 128;
    char *str= (char*)malloc(alloc_size);
    int index = 0;
    index += sprintf(&str[index], "[");
    for (int i=0; i<numsSize; i++)
        index += sprintf(&str[index], "%s,", arr[i]);
    str[index-1] = ']';
    return str; 
}

int main(void) {
    char *digits = "23";
    int returnSize = 2;
    char **res = letterCombinations(digits, &returnSize);
    /*printf("Input: \"23\"\nOutput: %s\n", join(res, returnSize, ','));*/

    return 0;
}
