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
    int n = nums1.size() + nums2.size();
    int k = (n + 1) / 2;
    if (n % 2 == 0) {
      double r1 = findKSortedArrays(nums1, 0, nums2, 0, k);
      double r2 = findKSortedArrays(nums1, 0, nums2, 0, k + 1);
      return (findKSortedArrays(nums1, 0, nums2, 0, k) +
              findKSortedArrays(nums1, 0, nums2, 0, k + 1)) /
             2;
    }
    return findKSortedArrays(nums1, 0, nums2, 0, k);
  }

  double findKSortedArrays(vector<int> &nums1, int s1, vector<int> &nums2,
                           int s2, int k) {
    if (nums1.size() - s1 > nums2.size() - s2) {
      return findKSortedArrays(nums2, s2, nums1, s1, k);
    } else if (nums1.size() == s1) {
      return nums2[s2 + k - 1];
    } else if (k == 1) {
      return min(nums1[s1], nums2[s2]);
    }

    int tmp = k / 2;
    int pa = (tmp < (nums1.size() - s1)) ? tmp : (nums1.size() - s1);
    int pb = k - pa;
    if (nums1[s1 + pa - 1] < nums2[s2 + pb - 1]) {
      return findKSortedArrays(nums1, s1 + pa, nums2, s2, k - pa);
    } else if (nums2[s2 + pb - 1] < nums1[s1 + pa - 1]) {
      return findKSortedArrays(nums1, s1, nums2, s2 + pb, k - pb);
    } else {
      return nums1[s1 + pa - 1];
    }
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

void test_case_3() {
  Solution s = Solution();
  vector<int> nums1 = {100001};
  vector<int> nums2 = {100000};
  assert(s.findMedianSortedArrays(nums1, nums2) == 100000.5);
}

void test_case_4() {
  Solution s = Solution();
  vector<int> nums1 = {1, 4};
  vector<int> nums2 = {2, 3};
  assert(s.findMedianSortedArrays(nums1, nums2) == 2.5);
}

int main(void) {
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();

  return 0;
}
