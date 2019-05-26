/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/05/23
 *
 ***************************************************************/
/**************************************************************
Given a 2D binary matrix filled with 0's and 1's, find the largest square
containing only 1's and return its area.

Example:

    Input:

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0

    Output: 4
***************************************************************/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // Dynamic Programming
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty())
            return 0;
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    dp[i][j] =
                        min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) +
                        1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }

    /*
     *    // brute force
     *    int maximalSquare(vector<vector<char>> &matrix) {
     *        if (matrix.size() == 0)
     *            return 0;
     *        int res = 0;
     *        vector<char>::size_type n = matrix.size();
     *        vector<vector<char>>::size_type m = matrix[0].size();
     *        for (vector<char>::size_type i = 0; i < n; ++i) {
     *            vector<int> v(m, 0);
     *            for (vector<char>::size_type j = i; j < n; ++j) {
     *                for (vector<char>::size_type k = 0; k < m; ++k) {
     *                    if (matrix[j][k] == '1') {
     *                        ++v[k];
     *                    }
     *                }
     *                int area = getSquareArea(v, j - i + 1);
     *                if (area == 0) {
     *                    break;
     *                }
     *                res = max(res, area);
     *            }
     *        }
     *        return res;
     *    }
     *
     *    int getSquareArea(vector<int> &v, int k) {
     *        if (k > v.size()) {
     *            return 0;
     *        };
     *        int count = 0;
     *        for (vector<int>::value_type val : v) {
     *            if (val != k) {
     *                count = 0;
     *            } else {
     *                ++count;
     *            }
     *            if (count == k)
     *                return k * k;
     *        }
     *        return 0;
     *    }
     */
};

void test_case_1() {
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
    assert(Solution().maximalSquare(matrix) == 4);
}

void test_case_2() {
    vector<vector<char>> matrix{};
    assert(Solution().maximalSquare(matrix) == 0);
}

void test_case_3() {
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
    assert(Solution().maximalSquare(matrix) == 4);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    return 0;
}
