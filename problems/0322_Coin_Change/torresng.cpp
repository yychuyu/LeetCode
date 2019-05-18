/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/05/17
 *
 ***************************************************************/
/**************************************************************
You are given coins of different denominations and a total amount of money
amount. Write a function to compute the fewest number of coins that you need to
make up that amount. If that amount of money cannot be made up by any
combination of the coins, return -1.

Example 1:

    Input: coins = [1, 2, 5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1

Example 2:

    Input: coins = [2], amount = 3
    Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.
***************************************************************/

#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> memo(amount + 1, numeric_limits<int>::max());
        memo[0] = 0;
        return coinChangeDFS(coins, amount, memo);
    }

    int coinChangeDFS(vector<int> &coins, int target, vector<int> &memo) {
        if (target < 0) {
        }
        if (memo[target] != numeric_limits<int>::max()) {
            return memo[target];
        }
        for (vector<int>::size_type i = 0; i < coins.size(); ++i) {
            if (coins[i] > target) {
                break;
            }
            int tmp = coinChangeDFS(coins, target - coins[i], memo);
            if (tmp != -1) {
                memo[target] = min(memo[target], tmp + 1);
            }
        }
        return memo[target] = (memo[target] == numeric_limits<int>::max())
                                  ? -1
                                  : memo[target];
    }
};

void test_case_1() {
    vector<int> coins{1, 2, 5};
    int amount = 11;
    assert(Solution().coinChange(coins, amount) == 3);
}

void test_case_2() {
    vector<int> coins{2};
    int amount = 3;
    assert(Solution().coinChange(coins, amount) == -1);
}

void test_case_3() {
    vector<int> coins{474, 83, 404, 3};
    int amount = 264;
    assert(Solution().coinChange(coins, amount) == 8);
}

void test_case_4() {
    vector<int> coins{186, 419, 83, 408};
    int amount = 6249;
    assert(Solution().coinChange(coins, amount) == 20);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    return 0;
}
