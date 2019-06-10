/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/06/06
 *
 ***************************************************************/
/**************************************************************
The demons had captured the princess (P) and imprisoned her in the bottom-right
corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid.
Our valiant knight (K) was initially positioned in the top-left room and must
fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at
any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative
integers) upon entering these rooms; other rooms are either empty (0's) or
contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to
move only rightward or downward in each step.



Write a function to determine the knight's minimum initial health so that he is
able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be
at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

+--------+--------+---------+
| -2 (K) |   -3   |    3    |
|--------+--------+---------+
|   -5 	 |  -10   |    1    |
+--------+--------+---------+
|   10   |   30   | -5 (P)  |
+--------+--------+---------+

Note:

    * The knight's health has no upper bound.
    * Any room can contain threats or power-ups, even the first room the knight
enters and the bottom-right room where the princess is imprisoned.
***************************************************************/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
                } else if (j == m - 1) {
                    dp[i][j] = (dp[i + 1][j] - dungeon[i][j]) > 0
                                   ? (dp[i + 1][j] - dungeon[i][j])
                                   : 1;
                } else if (i == n - 1) {
                    dp[i][j] = (dp[i][j + 1] - dungeon[i][j]) > 0
                                   ? (dp[i][j + 1] - dungeon[i][j])
                                   : 1;
                } else {
                    int a = (dp[i + 1][j] - dungeon[i][j]) > 0
                                ? (dp[i + 1][j] - dungeon[i][j])
                                : 1;

                    int b = (dp[i][j + 1] - dungeon[i][j]) > 0
                                ? (dp[i][j + 1] - dungeon[i][j])
                                : 1;
                    dp[i][j] = min(a, b);
                }
            }
        }

        return dp[0][0];
    }
};

void test_case_1() {
    vector<vector<int>> dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    assert(Solution().calculateMinimumHP(dungeon) == 7);
}

void test_case_2() {
    vector<vector<int>> dungeon{{100}};
    assert(Solution().calculateMinimumHP(dungeon) == 1);
}

void test_case_3() {
    vector<vector<int>> dungeon{{-200}};
    assert(Solution().calculateMinimumHP(dungeon) == 201);
}

void test_case_4() {
    vector<vector<int>> dungeon{{-3, 5}};
    assert(Solution().calculateMinimumHP(dungeon) == 4);
}

void test_case_5() {
    vector<vector<int>> dungeon{{2, 1}};
    assert(Solution().calculateMinimumHP(dungeon) == 1);
}

void test_case_6() {
    vector<vector<int>> dungeon{{0, 5}, {-2, -3}};
    assert(Solution().calculateMinimumHP(dungeon) == 1);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();
    return 0;
}
