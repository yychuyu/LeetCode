/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/1
*
***************************************************************/
/**************************************************************
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.

Note: You may assume the string contain only lowercase letters. 
***************************************************************/
#include <stdio.h>
#include <string.h>

int firstUniqChar(char* s) {
    char *c = s;
    unsigned set1 = 0;
    unsigned set2 = 0;
    while(*c) {
        unsigned i = 1 << (*c - 'a');
        set2 |= set1 & i;
        set1 |= i;
        c++;
    }
    c = s;
    while(*c) {
        unsigned i = 1 << (*c - 'a');
        if((set2 & i) == 0) {
            return c - s;
        }
        c++;
    }
    return -1;
}

int main(void) {
    char *str = "leetcode";
    int res = firstUniqChar(str);
    printf("s = \"leetcode\"\nreturn %d\n",res);
    str = "loveleetcode";
    res = firstUniqChar(str);
    printf("s = \"loveleetcode\"\nreturn %d\n",res);
    return 0;
}


