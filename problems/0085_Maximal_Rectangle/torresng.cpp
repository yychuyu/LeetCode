/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/06/18
 *
 ***************************************************************/
/**************************************************************
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
containing only 1's and return its area.

Example:

    Input:
    [
      ["1","0","1","0","0"],
      ["1","0","1","1","1"],
      ["1","1","1","1","1"],
      ["1","0","0","1","0"]
    ]
    Output: 6
***************************************************************/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> grid(rows, vector<int>(cols + 1, 0));
        buildHistogram(matrix, grid);

        int res = 0;

        for (int i = 0; i < grid.size(); ++i) {
            res = max(res, maxRec(grid, i));
        }
        return res;
    }

  private:
    void buildHistogram(const vector<vector<char>> &matrix,
                        vector<vector<int>> &grid) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            grid[0][j] = matrix[0][j] == '1' ? 1 : 0;
        }

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                grid[i][j] = matrix[i][j] == '1' ? grid[i - 1][j] + 1 : 0;
            }
        }
    }


    // 這𥚃用了 No. 0084 的思路，可以看看 No. 0084 怎求最大長方面積
    int maxRec(vector<vector<int>> &grid, int bottom) {
        int maxVal = 0;
        stack<int> s;
        s.push(-1);

        for(int i = 0; i < grid[0].size(); ++i) {
            while(s.top() != -1 && grid[bottom][s.top()] > grid[bottom][i]) {
                int x = s.top();
                s.pop();
                maxVal = max(maxVal, grid[bottom][x] * (i - s.top() - 1));
            }
            s.push(i);
        }

        return maxVal;
    }
};

void test_case_1() {
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};

    assert(Solution().maximalRectangle(matrix) == 6);
}

void test_case_2() {
    vector<vector<char>> matrix{{'1', '0'}, {'1', '0'}};

    assert(Solution().maximalRectangle(matrix) == 2);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
