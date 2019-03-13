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
        int start = 0, maxLength = 0;
        for(int i = 0; i < s.size(); i++) {
            searchPalindrome(s, i, i, start, maxLength);
            searchPalindrome(s, i, i+1, start, maxLength);
        }
        return s.substr(start, maxLength);
    }

    void searchPalindrome(const string &s, int left, int right, int &start, int &maxLength) {
        while(left >= 0 && right < s.size() && (s[left] == s[right])) {
            left--;
            right++;
        }
        if((right - left - 1) > maxLength) {
            maxLength = right - left - 1;
            start = left + 1;
        }
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


