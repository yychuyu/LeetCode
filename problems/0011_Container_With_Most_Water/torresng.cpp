/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/01
 *
 ***************************************************************/
/**************************************************************
Given n non-negative integers a1, a2, ..., an , where each represents a point at
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

![image](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this
case, the max area of water (blue section) the container can contain is 49.



Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1;
    int res = (j - i) * min(height[i], height[j]);
    while (i < j) {
      if (height[i] > height[j]) {
        j -= 1;
      } else {
        i += 1;
      }
      int c = (j - i) * min(height[i], height[j]);
      if (c > res) {
        res = c;
      }
    }
    return res;
  }
};

void test_case_1() {
  Solution s = Solution();
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  int ans = 49;
  assert(s.maxArea(height) == ans);
}

int main(void) {
  test_case_1();

  return 0;
}
