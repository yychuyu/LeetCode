/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/06/06
 *
 ***************************************************************/
/**************************************************************
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    Output: true

Example 2:

    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
    Output: false
***************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        string::size_type n1 = s1.size();
        string::size_type n2 = s2.size();
        if (n1 + n2 != s3.size()) {
            return false;
        }
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (string::size_type i = 0; i <= n1; ++i) {
            for (string::size_type j = 0; j <= n2; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[j - 1]);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i - 1]);
                } else {
                    dp[i][j] =
                        ((dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) ||
                         (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])));
                }
            }
        }
        return dp[n1][n2] == 1;
    }
};

void test_case_1() {
    assert(Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac") == true);
}

void test_case_2() {
    assert(Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc") == false);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
