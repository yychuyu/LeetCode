/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/05/21
 *
 ***************************************************************/
/**************************************************************
Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

    Input:
    [
      [1,3,1],
      [1,5,1],
      [4,2,1]
    ]
    Output: 7
    Explanation: Because the path 1?3?1?1?1 minimizes the sum.
***************************************************************/

#include <vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty())
            return 0;
        vector<int>::size_type n = grid.size(), m = grid[0].size();
        vector<int> dp(m);
        dp[0] = grid[0][0];
        for (vector<int>::size_type i = 1; i < m; ++i) {
            dp[i] = dp[i - 1] + grid[0][i];
        }
        for (vector<int>::size_type i = 1; i < n; ++i) {
            dp[0] = dp[0] + grid[i][0];
            for (vector<int>::size_type j = 1; j < m; ++j) {
                dp[j] = grid[i][j] + min(dp[j - 1], dp[j]);
            }
        }
        return dp[m - 1];
    }
};

void test_case_1() {
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    assert(Solution().minPathSum(grid) == 7);
}

int main(void) {
    test_case_1();
    return 0;
}
