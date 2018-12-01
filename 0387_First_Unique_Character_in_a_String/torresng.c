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
    int arr[27] = {0};
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        arr[s[i] - 'a']++;
    }
    for(int i = 0; i < len; i++) {
        if(arr[s[i] - 'a'] == 1) return i;
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


