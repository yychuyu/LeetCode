/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/03/22
 *
 ***************************************************************/
/**************************************************************
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should
be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

  nums1 = [1, 3]
  nums2 = [2]

  The median is 2.0

Example 2:

  nums1 = [1, 2]
  nums2 = [3, 4]

  The median is (2 + 3)/2 = 2.5
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> sum;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] <= nums2[j]) {
        sum.push_back(nums1[i]);
        i += 1;
      } else {
        sum.push_back(nums2[j]);
        j += 1;
      }
    }
    while (i < nums1.size()) {
      sum.push_back(nums1[i]);
      i += 1;
    }
    while (j < nums2.size()) {
      sum.push_back(nums2[j]);
      j += 1;
    }
    float res = 0;
    if (sum.size() % 2 == 0) {
      res = sum[sum.size() / 2] + sum[sum.size() / 2 - 1];
      res /= 2;
    } else {
      res = sum[sum.size() / 2];
    }
    return res;
  }
};

void test_case_1() {
  Solution s = Solution();
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  assert(s.findMedianSortedArrays(nums1, nums2) == 2.0);
}

void test_case_2() {
  Solution s = Solution();
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  assert(s.findMedianSortedArrays(nums1, nums2) == 2.5);
}

int main(void) {
  test_case_1();
  test_case_2();

  return 0;
}
