/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/03
*
***************************************************************/
/**************************************************************
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

    Input: "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string. 
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


