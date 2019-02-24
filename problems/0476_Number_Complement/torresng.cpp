/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/25
*
***************************************************************/
/**************************************************************
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:

    1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
    2. You could assume no leading zero bit in the integer’s binary representation.

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
***************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned high = ~0;
        while(high & num) {
            high <<= 1;
        }
        return ~high & ~num;
    }
};

int main(void) {
    Solution s = Solution();
    cout << "5: " << s.findComplement(5) << endl;
    cout << "1: " << s.findComplement(1) << endl;
    return 0;
}

