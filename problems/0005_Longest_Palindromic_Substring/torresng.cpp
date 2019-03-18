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
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int left = 0, right = 0, maxLength = 0;
        bool dp[s.size()][s.size()];
        memset(dp, false, s.size()*s.size()*sizeof(bool));
        for(int j = 0; j < s.size(); ++j) {
            for(int i = 0; i < j; ++i) {
                dp[i][j] = (s[i] == s[j]) && ((j - i) < 2 || dp[i+1][j-1]);;
                if(dp[i][j] && ((j - i + 1) > maxLength)) {
                    left = i;
                    right = j;
                    maxLength = j - i + 1;
                }
            }
            dp[j][j] = true;
        }
        return s.substr(left, right-left+1);
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


