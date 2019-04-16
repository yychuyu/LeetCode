/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/15
 *
 ***************************************************************/
/**************************************************************
Given a positive integer n, find the least number of perfect square numbers (for
example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
***************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);
            }
        }
        return dp[n];
    }
};

void test_case_1() { assert(Solution().numSquares(12) == 3); }

void test_case_2() { assert(Solution().numSquares(13) == 2); }

int main(void) {
    /*
     *test_case_1();
     */
    test_case_2();

    return 0;
}
