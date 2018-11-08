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
        if(a.size() < b.size()) {
            swap(a, b);
        }
        bool carry = false;
        int a_end = a.size() - b.size();
        for(int i = b.size() - 1; i >= 0; i--) {
            if(a[a_end + i] == '1' && b[i] == '1') {
                if(carry == true) {
                    a[a_end + i] = '1';
                } else {
                    a[a_end + i] = '0';
                }
                carry = true;
            } else if(a[a_end + i] == '1' || b[i] == '1') {
                if(carry == true) {
                    a[a_end + i] = '0';
                    carry = true;
                } else {
                    a[a_end + i] = '1';
                    carry = false;
                }
            } else {
                if(carry == true) {
                    a[a_end + i] = '1';
                }
                carry = false;
            }
        }
        a_end--;
        while(a_end >= 0) {
            if(a[a_end] == '1' && carry == true) {
                a[a_end] = '0';
                carry = true;
            } else if(a[a_end] == '1' || carry == true) {
                a[a_end] = '1';
                carry = false;
            } else {
                carry = false;
            }
            a_end--;
        }
        if(carry) a = "1" + a;
        return a;
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

