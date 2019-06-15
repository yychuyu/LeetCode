/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/06/09
 *
 ***************************************************************/
/**************************************************************
Given an array with n objects colored red, white or blue, sort them in-place so
that objects of the same color are adjacent, with the colors in the order red,
white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white,
and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

    Input: [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

Follow up:

    * A rather straight forward solution is a two-pass algorithm using counting
sort. First, iterate the array counting number of 0's, 1's, and 2's, then
overwrite array with total number of 0's, then 1's and followed by 2's.
    * Could you come up with a one-pass algorithm using only constant space?
***************************************************************/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int i = 0, j = nums.size() - 1, k = 0;
        while(k <= j) {
            if (nums[k] == 0) {
                swap(nums[k++], nums[i++]);
            } else if (nums[k] == 2) {
                swap(nums[k], nums[j--]);
            } else {
                ++k;
            }
        }
    }
};

bool compare(vector<int> &v1, vector<int> &v2) {
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

void test_case_1() {
    vector<int> nums{2, 0, 2, 1, 1, 0};
    Solution().sortColors(nums);
    vector<int> ans{
        0, 0, 1, 1, 2, 2,
    };
    assert(compare(nums, ans) == true);
}

void test_case_2() {
    vector<int> nums{2, 0, 1};
    Solution().sortColors(nums);
    vector<int> ans{0, 1, 2};
    assert(compare(nums, ans) == true);
}

void test_case_3() {
    vector<int> nums{2, 0};
    Solution().sortColors(nums);
    vector<int> ans{0, 2};
    assert(compare(nums, ans) == true);
}

void test_case_4() {
    vector<int> nums{1, 2, 0};
    Solution().sortColors(nums);
    vector<int> ans{0, 1, 2};
    assert(compare(nums, ans) == true);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    return 0;
}
