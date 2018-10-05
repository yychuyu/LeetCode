/***************************************************************
*   Copyright (C) 2017 All rights reserved.
*
*   文件名称：344_Reverse_String.c
*   创 建 者：hyb
*   创建日期：2017年08月03日
*   描    述：
*
***************************************************************/
/**************************************************************
344 Reverse String
题目：
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
释义：
字符串翻转
分析
头尾对应位置的字符位置调换
***************************************************************/
char* reverseString(char* s)
{
    unsigned  int len = strlen((const char*)s);
    char result[len+1];
    memset(result,0,len);
     int loop = 0;
     printf("the len:%d\n",len);
     printf("the src:%s\n",s);
    for(loop = len-1; loop >= 0;loop--)
    {
        *(result+(len-loop-1)) = *(s+loop);
    }
    result[len] = '\0';
    printf("result:%s\n",result);
    memcpy(s,result,len);
    return s;
}
