/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/06
 *
 ***************************************************************/
/**************************************************************
Given an array nums of n integers and an integer target, find three integers in
nums such that the sum is closest to target. Return the sum of the three
integers. You may assume that each input would have exactly one solution.

Example:

    Given array nums = [-1, 2, 1, -4], and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = 0x3f3f3f3f;
        for (unsigned long k = 0; k < nums.size() - 1; ++k) {
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    ++i;
                } else {
                    --j;
                }
                if (abs(sum - target) < abs(ret - target)) {
                    ret = sum;
                }
            }
        }
        return ret;
    }
};

void test_case_1() {
    Solution s = Solution();
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    int ans = 2;
    assert(s.threeSumClosest(nums, target) == ans);
}

void test_case_2() {
    Solution s = Solution();
    vector<int> nums{1, 1, 1, 1};
    int target = -100;
    int ans = 3;
    assert(s.threeSumClosest(nums, target) == ans);
}

void test_case_3() {
    Solution s = Solution();
    vector<int> nums{1, 1, 1, 0};
    int target = -100;
    int ans = 2;
    assert(s.threeSumClosest(nums, target) == ans);
}

void test_case_4() {
    Solution s = Solution();
    vector<int> nums{-1,2,1,-4};
    int target = 1;
    int ans = 2;
    assert(s.threeSumClosest(nums, target) == ans);
}

void test_case_5() {
    Solution s = Solution();
    vector<int> nums{13,  2,   0,   -14, -20, 19,  8,   -5,  -13, -3,  20,  15,
                     20,  5,   13,  14,  -17, -7,  12,  -6,  0,   20,  -19, -1,
                     -15, -2,  8,   -2,  -9,  13,  0,   -3,  -18, -9,  -9,  -19,
                     17,  -14, -19, -4,  -16, 2,   0,   9,   5,   -7,  -4,  20,
                     18,  9,   0,   12,  -1,  10,  -17, -11, 16,  -13, -14, -3,
                     0,   2,   -18, 2,   8,   20,  -15, 3,   -13, -12, -2,  -19,
                     11,  11,  -10, 1,   1,   -10, -2,  12,  0,   17,  -19, -7,
                     8,   -19, -17, 5,   -5,  -10, 8,   0,   -12, 4,   19,  2,
                     0,   12,  14,  -9,  15,  7,   0,   -16, -5,  16,  -12, 0,
                     2,   -16, 14,  18,  12,  13,  5,   0,   5,   6

    };
    int target = -59;
    int ans = -58;
    assert(s.threeSumClosest(nums, target) == ans);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    return 0;
}
