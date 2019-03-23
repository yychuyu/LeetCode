/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/03/23
 *
 ***************************************************************/
/**************************************************************
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the
first non-whitespace character is found. Then, starting from this character,
takes an optional initial plus or minus sign followed by as many numerical
digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral
number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid
integral number, or if no such sequence exists because either str is empty or it
contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

    * Only the space character ' ' is considered as whitespace character.
    * Assume we are dealing with an environment which could only store integers
within the 32-bit signed integer range: [?231,  231 ? 1]. If the numerical value
is out of the range of representable values, INT_MAX (231 ? 1) or INT_MIN (?231)
is returned.

Example 1:

    Input: "42"
    Output: 42

Example 2:

    Input: "   -42"
    Output: -42
    Explanation: The first non-whitespace character is '-', which is the minus
sign. Then take as many numerical digits as possible, which gets 42.

Example 3:

    Input: "4193 with words"
    Output: 4193
    Explanation: Conversion stops at digit '3' as the next character is not a
numerical digit.

Example 4:

    Input: "words and 987"
    Output: 0
    Explanation: The first non-whitespace character is 'w', which is not a
numerical digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

    Input: "-91283472332"
    Output: -2147483648
    Explanation: The number "-91283472332" is out of the range of a 32-bit
signed integer. Thefore INT_MIN (?231) is returned.
***************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    if (str.empty()) {
      return 0;
    }

    int sign = 1;
    long base = 0, i = 0;

    // skip all the preceding whitespaces
    while (i < str.size() && str[i] == ' ') {
      ++i;
    }

    // check if first char is sign
    // if it is, skip one char
    if (str[i] == '-') {
      sign = -1;
      ++i;
    } else if (str[i] == '+') {
      ++i;
    }

    // convert number one by one
    // if encounter letter, break
    while (i < str.size() && isdigit(str[i])) {
      base = 10 * base + (str[i] - '0');
      ++i;
      // small optimization to stop processing
      // if hitting the limit
      if (base > INT_MAX) {
        break;
      }
    }

    // check if base has exceeded maximum
    if (base > INT_MAX) {
      return (sign == 1) ? INT_MAX : INT_MIN;
    }

    return base * sign;
  }
};

void test_case_1() {
  Solution s = Solution();
  assert(s.myAtoi("42") == 42);
}

void test_case_2() {
  Solution s = Solution();
  assert(s.myAtoi("   -42") == -42);
}

void test_case_3() {
  Solution s = Solution();
  assert(s.myAtoi("4193 with words") == 4193);
}

void test_case_4() {
  Solution s = Solution();
  assert(s.myAtoi("words and 987") == 0);
}

void test_case_5() {
  Solution s = Solution();
  assert(s.myAtoi("-91283472332") == -2147483648);
}

int main(void) {
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();
  test_case_5();

  return 0;
}
