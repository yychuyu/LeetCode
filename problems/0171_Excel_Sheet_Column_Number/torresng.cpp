/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2019/02/25
*
***************************************************************/
/**************************************************************
题目：
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

Example 1:

    Input: "A"
    Output: 1

Example 2:

    Input: "AB"
    Output: 28

Example 3:

    Input: "ZY"
    Output: 701

***************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(auto it = s.begin(); it != s.end(); ++it) {
            res = res * 26 + (*it - 'A' + 1);
        }
        return res;
    }
};

int main(void) {
    Solution soluation;
    string s = "A";
    cout << "A -> " << soluation.titleToNumber(s) << endl;
    s = "Z";
    cout << "Z -> " << soluation.titleToNumber(s) << endl;
    s = "AB";
    cout << "AB -> " << soluation.titleToNumber(s) << endl;
    s = "ZY";
    cout << "ZY -> " << soluation.titleToNumber(s) << endl;


    return 0;
}
