/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     Torres Ng
*   Create Time 2018/12/10
*
***************************************************************/
/**************************************************************
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

Example 1:

    Input: 1
    Output: "A"

Example 2:

    Input: 28
    Output: "AB"

Example 3:

    Input: 701
    Output: "ZY"
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*, int, int);

char* convertToTitle(int n) {
    int mallocSize = 2;
    int size = 0;
    char *res = (char*)malloc(sizeof(char) * mallocSize + 1);
    while(n > 0) {
        size++;
        if(size > mallocSize) {
            mallocSize *= 2;
            res = realloc(res, sizeof(char) * mallocSize + 1);
        }
        res[size - 1] = 'A' + (n - 1) % 26;
        n = (n - 1) / 26;
        res[size] = '\0';
    }
    reverse(res, 0, size);
    return res;
}

void reverse(char *str, int begin, int end) {
    if(begin > end) {
        return;
    }

    char c;
    while(begin < end - 1) {
        c = str[begin];
        str[begin] = str[end - 1];
        str[end-1] = c;
        begin++;
        end--;
    }
}

int main(void) {
    int n = 1;
	printf("Input: %d\nOutput: %s\n", n, convertToTitle(n));
    n = 28;
	printf("Input: %d\nOutput: %s\n", n, convertToTitle(n));
    n = 701;
	printf("Input: %d\nOutput: %s\n", n, convertToTitle(n));
	return 0;
}
