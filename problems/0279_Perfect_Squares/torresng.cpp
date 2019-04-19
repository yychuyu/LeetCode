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

#include <complex>
#include <iostream>

using namespace std;

class Solution {
  public:
    int numSquares(int n) {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        for (int i = 0; i * i < n; ++i) {
            int j = sqrt(n - i * i);
            if (i * i + j * j == n) {
                return !!i + !!j;
            }
        }

        return 3;
    }
};

void test_case_1() { assert(Solution().numSquares(12) == 3); }

void test_case_2() { assert(Solution().numSquares(13) == 2); }

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
