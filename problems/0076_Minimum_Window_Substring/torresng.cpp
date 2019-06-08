/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/06/08
 *
 ***************************************************************/
/**************************************************************
Given a string S and a string T, find the minimum window in S which will contain
all the characters in T in complexity O(n).

Example:

    Input: S = "ADOBECODEBANC", T = "ABC"
    Output: "BANC"

Note:

    * If there is no such window in S that covers all characters in T, return
the empty string "".
    * If there is such window, you are guaranteed that there will always be only
one unique minimum window in S.
***************************************************************/

#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        string::size_type n = s.size(), m = t.size(), slow = 0, match_count = 0,
                          index = 0,
                          minLen = numeric_limits<string::size_type>::max();

        unordered_map<char, int> workDict = constructWorkDict(t);

        for (string::size_type fast = 0; fast < n; ++fast) {
            char c = s[fast];
            if (workDict.find(c) == workDict.end()) {
                continue;
            }
            if (--workDict[c] == 0)
                ++match_count;

            while (match_count == workDict.size() && slow <= fast) {
                if ((fast - slow + 1) < minLen) {
                    minLen = fast - slow + 1;
                    index = slow;
                }
                char c = s[slow];

                if (workDict.find(c) != workDict.end()) {
                    if (++workDict[c] == 1)
                        --match_count;
                }
                ++slow;
            }
        }

        return minLen == numeric_limits<string::size_type>::max()
                   ? ""
                   : s.substr(index, minLen);
    }

    unordered_map<char, int> constructWorkDict(const string &t) {
        unordered_map<char, int> workDict;
        for (char c : t) {
            ++workDict[c];
        }
        return workDict;
    }
};

void test_case_1() {
    assert(Solution().minWindow("ADOBECODEBANC", "ABC") == "BANC");
}

void test_case_2() { assert(Solution().minWindow("a", "a") == "a"); }

void test_case_3() { assert(Solution().minWindow("ab", "b") == "b"); }

void test_case_4() { assert(Solution().minWindow("aa", "aa") == "aa"); }

void test_case_5() { assert(Solution().minWindow("abc", "b") == "b"); }

void test_case_6() { assert(Solution().minWindow("a", "aa") == ""); }

void test_case_7() { assert(Solution().minWindow("a", "b") == ""); }

void test_case_8() { assert(Solution().minWindow("bba", "ab") == "ba"); }

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();
    test_case_7();
    test_case_8();
    return 0;
}
