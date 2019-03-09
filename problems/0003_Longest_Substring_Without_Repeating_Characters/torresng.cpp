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
#include <set>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int count = 0;
        std::set<char> set;
        auto iter1 = s.begin(), iter2 = s.begin();
        while(iter2 != s.end()) {
            if(set.find(*iter2) == set.end()) {
                set.insert(*iter2);
                count++;
                if(count > res) res = count;
                iter2++;
            } else {
                set.erase(*iter1);
                count--;
                iter1++;
            }
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
