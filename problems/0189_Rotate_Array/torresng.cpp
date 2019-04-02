/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/03/31
 *
 ***************************************************************/
/**************************************************************
Given an array, rotate the array to the right by k steps, where k is
non-negative.

Example 1:

  Input: [1,2,3,4,5,6,7] and k = 3
  Output: [5,6,7,1,2,3,4]
  Explanation:
  rotate 1 steps to the right: [7,1,2,3,4,5,6]
  rotate 2 steps to the right: [6,7,1,2,3,4,5]
  rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

  Input: [-1,-100,3,99] and k = 2
  Output: [3,99,-1,-100]
  Explanation:
  rotate 1 steps to the right: [99,-1,-100,3]
  rotate 2 steps to the right: [3,99,-1,-100]

Note:

  * Try to come up as many solutions as you can, there are at least 3 different
ways to solve this problem.
  * Could you do it in-place with O(1) extra space?

***************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    if(nums.size() <= 1) return;
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

void test_case_1() {
  Solution s = Solution();
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  s.rotate(nums, k);
  vector<int> ans = {5, 6, 7, 1, 2, 3, 4};
  for (int i = 0; i < nums.size(); i++) {
    assert(nums[i] == ans[i]);
  }
}

void test_case_2() {
  Solution s = Solution();
  vector<int> nums = {-1, -100, 3, 99};
  int k = 2;
  s.rotate(nums, k);
  vector<int> ans = {3, 99, -1, -100};
  for (int i = 0; i < nums.size(); i++) {
    assert(nums[i] == ans[i]);
  }
}

void test_case_3() {
  Solution s = Solution();
  vector<int> nums = {1,2};
  int k = 3;
  s.rotate(nums, k);
  vector<int> ans = {2,1};
  for (int i = 0; i < nums.size(); i++) {
    assert(nums[i] == ans[i]);
  }
}

void test_case_4() {
  Solution s = Solution();
  vector<int> nums = {-1};
  int k = 2;
  s.rotate(nums, k);
  vector<int> ans = {-1};
  for (int i = 0; i < nums.size(); i++) {
    assert(nums[i] == ans[i]);
  }
}

int main(void) {
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();

  return 0;
}
