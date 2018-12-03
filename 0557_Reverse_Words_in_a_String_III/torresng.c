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

char* reverseWords(char* s) {
    unsigned start = 0, end = 0, len = strlen(s);
    char temp;
    while(end < len) {
        while(end < len && s[end] != ' ') end++;
        for(int i = start, j = end - 1; i < j; i++, j--) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        start = ++end;
    }
    return s;
}

int main(void) {
    char* str = "Let's take LeetCode contest";
    println("Input: \"Let's take LeetCode contest\"\nOutput: %s", reverseWords(str));
    return 0;
}


