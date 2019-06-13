/***************************************************************
 *   Copyright (C) 2018 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2018/11/10
 *
 ***************************************************************/
/**************************************************************
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a
non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only
the integer part of the result is returned.

Example 1:

    Input: 4
    Output: 2

Example 2:

    Input: 8
    Output: 2
    Explanation: The square root of 8 is 2.82842..., and since
                 the decimal part is truncated, 2 is returned.
***************************************************************/

#include <cassert>
#include <iostream>

using namespace std;

class Solution {
  public:
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }
        double l = 0, r = x;
        while (r - l > 1e-8) {
            double mid = (l + r) / 2;
            if (mid * mid >= x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};

void test_case_1() { assert(Solution().mySqrt(4) == 2); }

void test_case_2() { assert(Solution().mySqrt(8) == 2); }

void test_case_3() { assert(Solution().mySqrt(1) == 1); }

void test_case_4() { assert(Solution().mySqrt(9) == 3); }

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
