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
        vector<int> memo(s.size(), -1);
        return check(s, 0, set, memo);
    }

    bool check(string &s, int start, unordered_set<string> &set,
               vector<int> &memo) {
        if ((unsigned long)start >= s.size())
            return true;
        if (memo[start] != -1)
            return memo[start];

        for (unsigned long i = start + 1; i <= s.size(); ++i) {
            if (set.count(s.substr(start, i - start)) &&
                check(s, i, set, memo)) {
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
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
