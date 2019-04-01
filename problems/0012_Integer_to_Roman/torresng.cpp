/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/01
 *
 ***************************************************************/
/**************************************************************
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and
M.

  Symbol       Value
  I             1
  V             5
  X             10
  L             50
  C             100
  D             500
  M             1000

For example, two is written as II in Roman numeral, just two one's added
together. Twelve is written as, XII, which is simply X + II. The number twenty
seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

  * I can be placed before V (5) and X (10) to make 4 and 9.
  * X can be placed before L (50) and C (100) to make 40 and 90.
  * C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral. Input is guaranteed to be
within the range from 1 to 3999.

Example 1:

  Input: 3
  Output: "III"

Example 2:

  Input: 4
  Output: "IV"

Example 3:

  Input: 9
  Output: "IX"

Example 4:

  Input: 58
  Output: "LVIII"
  Explanation: L = 50, V = 5, III = 3.

Example 5:

  Input: 1994
  Output: "MCMXCIV"
  Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
***************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string res;
    int n_1000 = num / 1000;
    int n_m_1000 = num % 1000;
    for (int i = 0; i < n_1000; i++) {
      res += 'M';
    }

    int n_100 = n_m_1000 / 100;
    int n_m_100 = n_m_1000 % 100;
    switch (n_100) {
    case 9:
      res += "CM";
      break;
    case 8:
      res += "DCCC";
      break;
    case 7:
      res += "DCC";
      break;
    case 6:
      res += "DC";
      break;
    case 5:
      res += "D";
      break;
    case 4:
      res += "CD";
      break;
    case 3:
      res += "CCC";
      break;
    case 2:
      res += "CC";
      break;
    case 1:
      res += "C";
      break;
    }

    int n_10 = n_m_100 / 10;
    int n_m_10 = n_m_100 % 10;
    switch (n_10) {
    case 9:
      res += "XC";
      break;
    case 8:
      res += "LXXX";
      break;
    case 7:
      res += "LXX";
      break;
    case 6:
      res += "LX";
      break;
    case 5:
      res += "L";
      break;
    case 4:
      res += "XL";
      break;
    case 3:
      res += "XXX";
      break;
    case 2:
      res += "XX";
      break;
    case 1:
      res += "X";
      break;
    };

    int n_1 = n_m_10;
    switch (n_1) {
    case 9:
      res += "IX";
      break;
    case 8:
      res += "VIII";
      break;
    case 7:
      res += "VII";
      break;
    case 6:
      res += "VI";
      break;
    case 5:
      res += "V";
      break;
    case 4:
      res += "IV";
      break;
    case 3:
      res += "III";
      break;
    case 2:
      res += "II";
      break;
    case 1:
      res += "I";
      break;
    };

    return res;
  }
};

void test_case_1() {
  Solution s = Solution();
  int num = 3;
  string ans = "III";
  assert(s.intToRoman(num) == ans);
}

void test_case_2() {
  Solution s = Solution();
  int num = 4;
  string ans = "IV";
  assert(s.intToRoman(num) == ans);
}

void test_case_3() {
  Solution s = Solution();
  int num = 9;
  string ans = "IX";
  assert(s.intToRoman(num) == ans);
}

void test_case_4() {
  Solution s = Solution();
  int num = 58;
  string ans = "LVIII";
  assert(s.intToRoman(num) == ans);
}

void test_case_5() {
  Solution s = Solution();
  int num = 1994;
  string ans = "MCMXCIV";
  assert(s.intToRoman(num) == ans);
}

int main(void) {
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();
  test_case_5();

  return 0;
}
