/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/03/22
 *
 ***************************************************************/
/**************************************************************
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

    string convert(string s, int numRows);

Example 1:

    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"

Example 2:

    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:

    P     I    N
    A   L S  I G
    Y A   H R
    P     I
***************************************************************/

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    string mp[numRows];
    int period = numRows * 2 - 2;
    for (int i = 0; i < s.size(); i++) {
      int pos = i % period;
      if (i % period >= numRows) {
        pos = period - pos;
      }
      mp[pos] += s[i];
    }
    string res;
    for (int i = 0; i < numRows; i++) {
      res += mp[i];
    }
    return res;
  }
};

void test_case_1() {
  Solution s = Solution();
  assert(s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
}

void test_case_2() {
  Solution s = Solution();
  assert(s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
}

void test_case_3() {
  Solution s = Solution();
  assert(s.convert("A", 1) == "A");
}

void test_case_4() {
  Solution s = Solution();
  assert(s.convert("AB", 1) == "AB");
}

void test_case_5() {
  Solution s = Solution();
  assert(s.convert("ABC", 1) == "ABC");
}

int main(void) {
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();
  test_case_5();

  return 0;
}
