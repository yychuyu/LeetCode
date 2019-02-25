/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/04
*
***************************************************************/
/**************************************************************
Given a non-negative index k where k ≤ 33, return the k^th index row of the Pascal's triangle.

Note that the row index starts from 0.

[](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

    Input: 3
    Output: [1,3,3,1]

Follow up:

Could you optimize your algorithm to use only O(k) extra space?
***************************************************************/
#include <stdio.h>
#include <string.h>

void reverseWord(char *s, int len) {
    char temp;
    for(int i = 0; i < len/2; i++) {
        temp = *(s - len + i);
        *(s - len + i) = *(s - i - 1);
        *(s - i - 1) = temp;
    }
}

void peekforspace(char *s) {
    if(*s == '\0') return;

    int sub = 0;
    while(*s != ' ' && *s != '\0') {
        s++;
        sub++;
    }
    reverseWord(s, sub);
    if(*s != '\0') s++;
    peekforspace(s);
}

char* reverseWords(char *s) {
    peekforspace(s);

    return s;
}

int main(void) {
    char str[] = "Let's take LeetCode contest";
    printf("Input: \"Let's take LeetCode contest\"\nOutput: %s\n", reverseWords(str));
    return 0;
}
