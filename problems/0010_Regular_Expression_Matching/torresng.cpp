/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/05/27
 *
 ***************************************************************/
/**************************************************************
Given an input string (s) and a pattern (p), implement regular expression
matching with support for '.' and '*'.

    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

    * s could be empty and contains only lowercase letters a-z.
    * p could be empty and contains only lowercase letters a-z, and characters
like . or *.

Example 1:

    Input:
    s = "aa"
    p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".

Example 2:

    Input:
    s = "aa"
    p = "a*"
    Output: true
    Explanation: '*' means zero or more of the precedeng element, 'a'.
Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

    Input:
    s = "ab"
    p = ".*"
    Output: true
    Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

    Input:
    s = "aab"
    p = "c*a*b"
    Output: true
    Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
it matches "aab".

Example 5:

    Input:
    s = "mississippi"
    p = "mis*is*p*."
    Output: false
***************************************************************/

#include <cassert>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
  public:
    // Recursive
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        if (p.size() == 1) {
            return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
        }
        if (p[1] != '*') {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') &&
                   isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2)))
                return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};

void test_case_1() {
    string s = "aa", p = "a";
    assert(Solution().isMatch(s, p) == false);
}

void test_case_2() {
    string s = "aa", p = "a*";
    assert(Solution().isMatch(s, p) == true);
}

void test_case_3() {
    string s = "ab", p = ".*";
    assert(Solution().isMatch(s, p) == true);
}

void test_case_4() {
    string s = "aab", p = "c*a*b";
    assert(Solution().isMatch(s, p) == true);
}

void test_case_5() {
    string s = "mississippi", p = "mis*is*p*.";
    assert(Solution().isMatch(s, p) == false);
}

void test_case_6() {
    string s = "aaa", p = "a.a";
    assert(Solution().isMatch(s, p) == true);
}

void test_case_7() {
    string s = "a", p = ".*..a*";
    assert(Solution().isMatch(s, p) == false);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();
    test_case_7();
    return 0;
}
