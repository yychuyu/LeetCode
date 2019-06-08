/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/05/27
 *
 ***************************************************************/
/**************************************************************
A message containing letters from A-Z is being encoded to numbers using the
following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26

Given a non-empty string containing only digits, determine the total number of
ways to decode it.

Example 1:

    Input: "12"
    Output: 2
    Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

    Input: "226"
    Output: 3
    Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
6).
***************************************************************/

#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    // Dynamic Programming O(1) space{
    int numDecodings(string s) {
        if (!s.empty() && s[0] == '0')
            return 0;
        int a = 1, b = 1;
        for (string::size_type i = 1; i < s.size(); ++i) {
            int pre_a = a;
            if (s[i] == '0')
                a = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                a = a + b;
                b = pre_a;
            } else {
                b = a;
            }
        }
        return a;
    }

    // Dynamic Programming
    /*
    int numDecodings(string s) {
        int res = 0;
        vector<int> dp(s.size(), 0);
        for (string::size_type i = 0; i < s.size(); ++i) {
            dp[i] = (s[i] == '0') ? 0 : ((i == 0) ? 1 : dp[i - 1]);
            if (i > 0) {
                dp[i] += (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                             ? ((i > 1) ? dp[i - 2] : 1)
                             : 0;
            }
        }
        return dp.back();
    }
    */
};

void test_case_1() {
    string s = "12";
    assert(Solution().numDecodings(s) == 2);
}

void test_case_2() {
    string s = "226";
    assert(Solution().numDecodings(s) == 3);
}

void test_case_3() {
    string s = "0";
    assert(Solution().numDecodings(s) == 0);
}

void test_case_4() {
    string s = "01";
    assert(Solution().numDecodings(s) == 0);
}

void test_case_5() {
    string s = "1010";
    assert(Solution().numDecodings(s) == 1);
}

void test_case_6() {
    string s = "24726";
    assert(Solution().numDecodings(s) == 4);
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
