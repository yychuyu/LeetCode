/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/05/27
 *
 ***************************************************************/
/**************************************************************
A message containing letters from A-Z is being encoded to numbers using the
following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26

Given a non-empty string containing only digits, determine the total number of
ways to decode it.

Example 1:

    Input: "12"
    Output: 2
    Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

    Input: "226"
    Output: 3
    Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
6).
***************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int numDecodings(string s) {
        int res = 0;
        vector<int> dp(s.size(), 0);
        for (string::size_type i = 0; i < s.size(); ++i) {
            dp[i] = (s[i] == '0') ? 0 : ((i == 0) ? 1 : dp[i - 1]);
            if (i > 0) {
                dp[i] += (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                             ? ((i > 1) ? dp[i - 2] : 1)
                             : 0;
            }
        }
        return dp.back();
    }
};

void test_case_1() {
    string s = "12";
    assert(Solution().numDecodings(s) == 2);
}

void test_case_2() {
    string s = "226";
    assert(Solution().numDecodings(s) == 3);
}

int main(void) {
    test_case_1();
    test_case_2();
    return 0;
}
