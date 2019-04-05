/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/01
 *
 ***************************************************************/
/**************************************************************
You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed. All houses at this place are arranged in
a circle. That means the first house is the neighbor of the last one. Meanwhile,
adjacent houses have security system connected and it will automatically contact
the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each
house, determine the maximum amount of money you can rob tonight without
alerting the police.

Example 1:

  Input: [2,3,2]
  Output: 3
  Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money =
2), because they are adjacent houses.

Example 2:

  Input: [1,2,3,1]
  Output: 4
  Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
               Total amount you can rob = 1 + 3 = 4.
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    return max(robRange(nums, 0, nums.size() - 1),
               robRange(nums, 1, nums.size()));
  }

  int robRange(vector<int> &nums, int s, int e) {
    int s1 = 0, s2 = 0, res = 0;
    for (int i = s; i < e; i++) {
      if (s1 + nums[i] > s2) {
        res = s1 + nums[i];
      } else {
        res = s2;
      }
      s1 = s2;
      s2 = res;
    }
    return res;
  }
};

void test_case_1() {
  Solution s = Solution();
  vector<int> nums = {2, 3, 2};
  int ans = 3;
  assert(s.rob(nums) == ans);
}

void test_case_2() {
  Solution s = Solution();
  vector<int> nums = {1, 2, 3, 1};
  int ans = 4;
  assert(s.rob(nums) == ans);
}

void test_case_3() {
  Solution s = Solution();
  vector<int> nums = {};
  int ans = 0;
  assert(s.rob(nums) == ans);
}

int main(void) {
  test_case_1();
  test_case_2();
  return 0;
}
