/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/06/03
 *
 ***************************************************************/
/**************************************************************
Given two words word1 and word2, find the minimum number of operations required
to convert word1 to word2.

You have the following 3 operations permitted on a word:

    1. Insert a character
    2. Delete a character
    3. Replace a character

Example 1:

    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation:
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')

Example 2:

    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation:
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
***************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return helper(word1, 0, word2, 0, dp);
    }

    int helper(string &word1, int i, string &word2, int j,
               vector<vector<int>> &dp) {
        if (i == word1.size())
            return word2.size() - j;
        if (j == word2.size())
            return word1.size() - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        if (word1[i] == word2[j]) {
            return helper(word1, i + 1, word2, j + 1, dp);
        } else {
            int insertOp = helper(word1, i, word2, j + 1, dp);
            int deleteOp = helper(word1, i + 1, word2, j, dp);
            int replaceOp = helper(word1, i + 1, word2, j + 1, dp);
            res = res + min(insertOp, min(deleteOp, replaceOp)) + 1;
        }
        return dp[i][j] = res;
    }
};

void test_case_1() { assert(Solution().minDistance("horse", "ros") == 3); }

void test_case_2() {
    assert(Solution().minDistance("intention", "execution") == 5);
}

void test_case_3() {
    assert(Solution().minDistance("dinitrophenylhydrazine",
                                  "acetylphenylhydrazine") == 6);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
}
