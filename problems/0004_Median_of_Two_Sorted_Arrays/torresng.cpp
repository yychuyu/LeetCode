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
      return (findKSortedArrays(nums1, nums2, k) +
              findKSortedArrays(nums1, nums2, k + 1)) /
             2;
    }
    return findKSortedArrays(nums1, nums2, k);
  }

  double findKSortedArrays(vector<int> &nums1, vector<int> &nums2, int k) {
    if (nums1.size() > nums2.size()) {
      return findKSortedArrays(nums2, nums1, k);
    } else if (nums1.size() == 0) {
      return nums2[k - 1];
    } else if (k == 1) {
      return min(nums1[0], nums2[0]);
    }

    int tmp = k / 2;
    int pa = (tmp < nums1.size()) ? tmp : nums1.size();
    int pb = k - pa;
    if (nums1[pa - 1] < nums2[pb - 1]) {
      vector<int> a(nums1.begin() + pa, nums1.end());
      return findKSortedArrays(a, nums2, k - pa);
    } else if (nums2[pb - 1] < nums1[pa - 1]) {
      vector<int> a(nums2.begin() + pb, nums2.end());
      return findKSortedArrays(nums1, a, k - pb);
    } else {
      return nums1[pa - 1];
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

int main(void) {
  test_case_1();
  test_case_2();

  return 0;
}
