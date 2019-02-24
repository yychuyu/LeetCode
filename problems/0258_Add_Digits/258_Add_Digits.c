/***************************************************************
*   Copyright (C) 2017 All rights reserved.
*
*   文件名称：258_Add_Digits.c
*   创 建 者：hyb
*   创建日期：2017年08月04日
*   描    述：
*
***************************************************************/
/*************************************************************
题目：
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

释义：
计算各位数之和，直到最后只有一位。

分析：
计算各位数之和，采用递归，计算一次后，再次调用，直到结果位各位数。
*************************************************************/
int addDigits(int num)
{
    int temp = num;
    if(0 == num/10)
    {
        return num;
    }
    else
    {
        num =0;
        while(0 != temp/10)
        {
            num +=temp%10;
            temp = temp/10;
        }
        num = num+temp;
       return  addDigits(num);
    }
}
