/***************************************************************
*   Copyright (C) 2019 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2019/03/13
*
***************************************************************/
/**************************************************************
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

Example 2:

    Input: "cbbd"
    Output: "bb"
***************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for(auto c : s) {
            t += c;
            t += '#';
        }
        vector<int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for(int i = 1; i < t.size(); i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while(t[i + p[i]] == t[i - p[i]]) ++p[i];
            if(mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if(resLen < p[i]) {
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }

};

void test_case_1() {
    Solution s = Solution();
    assert((s.longestPalindrome("babad") == "bab") ||
            (s.longestPalindrome("babad") == "aba"));
    assert(s.longestPalindrome("cbbd") == "bb");
}

int main(void) {
    test_case_1();
    
    return 0;
}


