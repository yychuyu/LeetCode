/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/05/17
 *
 ***************************************************************/
/**************************************************************
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher
or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x.
You win the game when you guess the number I picked.

Example:

```
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
```

Given a particular n >= 1, find out how much money you need to have to guarantee
a win.
***************************************************************/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int j = 2; j <= n; ++j) {
            for (int i = j - 1; i > 0; --i) {
                int global_min = INT_MAX;
                for (int k = j - 1; k > i; --k) {
                    int local_max = k + max(dp[i][k - 1], dp[k + 1][j]);
                    global_min = min(global_min, local_max);
                }
                dp[i][j] = (i + 1 == j) ? i : global_min;
            }
        }
        return dp[1][n];
    }
};

void test_case_1() { assert(Solution().getMoneyAmount(10) == 16); }

void test_case_2() { assert(Solution().getMoneyAmount(2) == 1); }

int main(void) {
    test_case_1();
    test_case_2();
    return 0;
}
