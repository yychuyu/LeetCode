/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/06/13
 *
 ***************************************************************/
/**************************************************************
Given an array of integers nums sorted in ascending order, find the starting and
ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

Example 2:

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if(nums.empty()) {
            return {-1, -1};
        }
        vector<int> res;

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] != target) {
            res.push_back(-1);
            res.push_back(-1);
        } else {
            res.push_back(l);
            r = nums.size() - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (nums[mid] <= target) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            res.push_back(l);
        }

        return res;
    }
};

bool compare(vector<int> &v1, vector<int> &v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    return true;
}

void test_case_1() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    vector<int> ans{3, 4};
    vector<int> res = Solution().searchRange(nums, 8);
    assert(compare(res, ans) == true);
}

void test_case_2() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    vector<int> ans{-1, -1};
    vector<int> res = Solution().searchRange(nums, 6);
    assert(compare(res, ans) == true);
}

void test_case_3() {
    vector<int> nums{};
    vector<int> ans{-1, -1};
    vector<int> res = Solution().searchRange(nums, 0);
    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
