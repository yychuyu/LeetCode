/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/08
*
***************************************************************/
/**************************************************************
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

    Input: a = "11", b = "1"
    Output: "100"

Example 2:

    Input: a = "1010", b = "1011"
    Output: "10101"
***************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aIndx = a.size() - 1;
        int bIndx = b.size() - 1;
        int carry = 0;
        int aVal;
        int bVal;
        int add;
        string result;
        while(aIndx >= 0 || bIndx >= 0) {
            aVal = (aIndx >= 0) ? a[aIndx] - '0' : 0;
            bVal = (bIndx >= 0) ? b[bIndx] - '0' : 0;
            add = aVal + bVal + carry; 
            switch(aVal + bVal + carry) {
                case 3: 
                    result += '1';
                    carry = 1;
                    break;
                case 2:
                    result += '0';
                    carry = 1;
                    break;
                case 1:
                    result += '1';
                    carry = 0;
                    break;
                case 0:
                    result += '0';
                    carry = 0;
                    break;
            }
            --aIndx;
            --bIndx;
        }
        if(carry == 1) result += '1';
        reverse(result.begin(), result.end());

        return result;
    }
};

int main(void) {
    Solution s = Solution();
    string a = "11", b = "1";
    cout << "a = \"11\", b = \"1\": " << s.addBinary(a, b) << endl;
    a = "1010";
    b = "1011";
    cout << "a = \"1010\", b = \"1011\": " << s.addBinary(a, b) << endl;
    return 0;
}

