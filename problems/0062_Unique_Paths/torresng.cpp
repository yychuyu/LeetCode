/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/11
 *
 ***************************************************************/
/**************************************************************
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the
diagram below).

The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid (marked 'Finish' in the
diagram below).

How many possible unique paths are there?

![](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

    Input: m = 3, n = 2
    Output: 3
    Explanation:
    From the top-left corner, there are a total of 3 ways to reach the
bottom-right corner:
    1. Right -> Right -> Down
    2. Right -> Down -> Right
    3. Down -> Right -> Right

Example 2:

    Input: m = 7, n = 3
    Output: 28
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1)
            return 1;
        int dp[m];
        for (int i = 0; i < m; ++i) {
            dp[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[m-1];
    }


    //Permutations 
    /*
     *int uniquePaths(int m, int n) {
     *    int cm = m + n - 2;
     *    // get small one, because C(m+n-2,m-1) == C(m+n-2,n-1)
     *    int cn = m < n ? m - 1 : n - 1;
     *    long num = 1, denom = 1;
     *    for (int i = 1; i <= cn; ++i) {
     *        num *= cm--;
     *        denom *= i;
     *    }
     *    return num / denom;
     *}
     */
};

void test_case_1() { assert(Solution().uniquePaths(3, 2) == 3); }

void test_case_2() { assert(Solution().uniquePaths(7, 3) == 28); }

void test_case_3() { assert(Solution().uniquePaths(1, 1) == 1); }

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
