
/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/08
*
***************************************************************/
/**************************************************************
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

    Input: [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.

Example 2:

    Input: [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: The array represents the integer 4321.
***************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::reverse_iterator rit = digits.rbegin();
        vector<int> result;
        int carry = 1;
        for(vector<int>::reverse_iterator rit = digits.rbegin();
                rit != digits.rend(); rit++) {
            *rit += carry;
            if(*rit == 10) {
                *rit = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            result.push_back(*rit);
        }
        int size = result.size();
        if(result[size-1] == 0) {
            result.push_back(1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

string join(const vector<int>& v, string c) {
    string s;
    for (vector<int>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += to_string(*p);
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

int main(void) {
    Solution s = Solution();
    vector<int> digits {1,2,3};
    cout << "[1,2,3]: " << join(s.plusOne(digits), ",") << endl;
    digits = {4,3,2,1};
    cout << "[4,3,2,1]: " << join(s.plusOne(digits), ",") << endl;
    digits = {9,9};
    cout << "[9,9]: " << join(s.plusOne(digits), ",") << endl;
    digits = {9};
    cout << "[9]: " << join(s.plusOne(digits), ",") << endl;
    return 0;
}
