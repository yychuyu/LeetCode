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
#include <string.h>

#define MAX_COL_LEN (100)
#define BASE (26)

char* convertToTitle(int n) {
    char col[MAX_COL_LEN];
    int i = MAX_COL_LEN - 1;

    if(n <= 0)
        return strdup("");
    
    col[i--] = '\0';
    while(n > 0) {
        col[i--] = (n - 1) % BASE + 'A';
        n = (n - 1) / BASE;
    }
    return strdup(&col[i + 1]);
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
