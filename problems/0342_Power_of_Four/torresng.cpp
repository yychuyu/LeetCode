/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/05/22
 *
 ***************************************************************/
/**************************************************************
Given an integer (signed 32 bits), write a function to check whether it is a
power of 4.

Example 1:

    Input: 16
    Output: true

Example 2:

    Input: 5
    Output: false

Follow up: Could you solve it without loops/recursion?
***************************************************************/

#include <cassert>
#include <cmath>

using namespace std;

class Solution {
  public:
    bool isPowerOfFour(int num) {
        return num > 0 &&
               int(log10(num) / log10(4)) - log10(num) / log10(4) == 0;
    }
};

void test_case_1() { assert(Solution().isPowerOfFour(16) == true); }

void test_case_2() { assert(Solution().isPowerOfFour(5) == false); }

void test_case_3() { assert(Solution().isPowerOfFour(1) == true); }

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
