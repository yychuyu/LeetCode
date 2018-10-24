/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/20
*
***************************************************************/
/**************************************************************
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 ? 3

Example 2:

Input: 8
Output: true
Explanation: 8 = 2 ? 2 ? 2

Example 3:

Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.

Note:

    1. 1 is typically treated as an ugly number.
    2. Input is within the 32-bit signed integer range: [-2^31,  2^31 - 1].
***************************************************************/


#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) {
            return false;
        }
        while(num % 5 == 0) {
            num /= 5;
        }
        while(num % 3 == 0) {
            num /= 3;
        }
        while(num % 2 == 0) {
            num /= 2;
        }
        return num == 1;
    }
};

int main(void)
{
    Solution s = Solution();
    cout << "isUgly(4): " << boolalpha << s.isUgly(4) << endl;
    cout << "isUgly(8): " << boolalpha << s.isUgly(8) << endl;
    cout << "isUgly(14): " << boolalpha << s.isUgly(14) << endl;
    
    return 0;
}
