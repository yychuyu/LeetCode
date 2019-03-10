/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2019/03/08
*
***************************************************************/
/**************************************************************
Given a string, find the length of the longest substring without repeating characters.

Example 1:

    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3. 

Example 2:

    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

Example 3:

    Input: "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3. 
                 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
***************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = -1;
        int hash[256];
        std::fill_n(hash, 256, -1);
        for(int i = 0; i < s.size(); i++) {
            if(hash[s[i]] > start) {
                start = hash[s[i]];
            }
            hash[s[i]] = i;
            res = max(res, i - start);
        }
        return res;
    }
};

void test_case_1() {
    Solution s = Solution();
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
}

void test_case_2() {
    Solution s = Solution();
    assert(s.lengthOfLongestSubstring("bbbbb") == 1);
}

void test_case_3() {
    Solution s = Solution();
    assert(s.lengthOfLongestSubstring("pwwkew") == 3);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
