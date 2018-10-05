/***************************************************************
*   Copyright (C) 2017 All rights reserved.
*
*   文件名称：476_number_complement.c
*   创 建 者：hyb
*   创建日期：2017年08月02日
*   描    述：
*
***************************************************************/
/*************************************************************
题目：
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

释义：
给定一个正整数，输出它的补全整数。补全策略是翻转它的每个比特位，得到补全整数。

分析：

对于补全，以5为例，101，每一位翻转得到，010，即结果为2，那么，010+101 = 111，2的3次方。再以35为例，10 0011，翻转得到011100，即有100011+011100=111111,2的6次方，那么不难得到，其实补全数，就是用2的n次方，减去该数，其中，n为该数二进制表示的位数。
**************************************************************/
int findComplement(int num) {

    int temp = num;
    int i = 0;
    for(i=0;temp!=0;temp/=2,i++)
    {}
    return pow(2,i)-num-1;
}
