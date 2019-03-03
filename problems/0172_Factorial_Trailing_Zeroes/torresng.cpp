/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2019/02/26
*
***************************************************************/
/**************************************************************
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

    Input: 3
    Output: 0
    Explanation: 3! = 6, no trailing zero.

Example 2:

    Input: 5
    Output: 1
    Explanation: 5! = 120, one trailing zero.

Note: Your solution should be in logarithmic time complexity.
***************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
    }
};

int main(void) {
    Solution s;
    int n = 3;
    cout << "3! = " << s.trailingZeroes(n) << endl;
    
    n = 5;
    cout << "5! = " << s.trailingZeroes(n) << endl;

    n = 30;
    cout << "30! = " << s.trailingZeroes(n) << endl;
    return 0;
}
