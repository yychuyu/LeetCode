/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/24
*
***************************************************************/
/**************************************************************
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
***************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (num-1) % 9 + 1;        
    }
};

int main(void) {
    Solution s = Solution();
    cout << "38: " << s.addDigits(38) << endl;
    

    return 0;
}
