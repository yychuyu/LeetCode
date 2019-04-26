/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/22
 *
 ***************************************************************/
/**************************************************************
Given a non-empty string s and a dictionary wordDict containing a list of
non-empty words, determine if s can be segmented into a space-separated sequence
of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the
segmentation. You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen
apple". Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
***************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (unsigned long i = 0; i < s.size(); ++i) {
            for (unsigned long j = i + 1; j <= s.size(); ++j) {
                if (dp[i] && set.count(s.substr(i, j - i))) {
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

void test_case_1() {
    vector<string> wordDict = {"leet", "code"};
    assert(Solution().wordBreak("leetcode", wordDict) == true);
}

void test_case_2() {
    vector<string> wordDict = {"apple", "pen"};
    assert(Solution().wordBreak("applepenapple", wordDict) == true);
}

void test_case_3() {
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    assert(Solution().wordBreak("catsandog", wordDict) == false);
}

void test_case_4() {
    vector<string> wordDict = {"a",         "aa",        "aaa",     "aaaa",
                               "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                               "aaaaaaaaa", "aaaaaaaaaa"};
    assert(Solution().wordBreak(
               "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
               "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
               "aaaaaaaaaaaaaaaaaaaaaaaab",
               wordDict) == false);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
