/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/09
 *
 ***************************************************************/
/**************************************************************
Given an array nums of n integers and an integer target, are there elements a,
b, c, and d in nums such that a + b + c + d = target? Find all unique
quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

    Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

    A solution set is:
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums, unsigned long start,
                                 int target) {
        vector<vector<int>> ret;

        for (unsigned long k = start; k < nums.size(); ++k) {
            while (k < nums.size() && k > start && nums[k] == nums[k - 1])
                ++k;
            unsigned long l = k + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[k] + nums[l] + nums[r];
                if (sum == target) {
                    ret.push_back({nums[k], nums[l], nums[r]});
                    while (++l < r && nums[l] == nums[l - 1])
                        ;
                    while (l < --r && nums[r] == nums[r + 1])
                        ;
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ret;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        if (nums.empty())
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for (unsigned long i = 0; i < nums.size() - 1; ++i) {
            vector<vector<int>> three = threeSum(nums, i + 1, target - nums[i]);
            for (auto v : three) {
                v.push_back(nums[i]);
                sort(v.begin(), v.end());
                ret.push_back(v);
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return ret;
    }
};

bool compare(const vector<vector<int>> &res, const vector<vector<int>> &ans) {
    if (res.size() != ans.size())
        return false;
    vector<vector<int>> n1 = res, n2 = ans;
    for (vector<int> v : n1) {
        sort(v.begin(), v.end());
    }
    for (vector<int> v : n2) {
        sort(v.begin(), v.end());
    }
    for (vector<int> v : n1) {
        auto iter = n2.begin();
        while (iter != n2.end()) {
            if (v.size() != iter->size()) {
                return false;
            }
            if (v[0] == (*iter)[0] || v[1] == (*iter)[1] ||
                v[2] == (*iter)[2]) {
                n2.erase(iter);
                break;
            }
            ++iter;
        }
    }
    if (n2.size() != 0)
        return false;

    return true;
}

void test_case_1() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans{{-1, 0, 0, 1}, {-2, -1, 1, 2}, {-2, 0, 0, 2}};
    vector<vector<int>> res = Solution().fourSum(nums, 0);
    assert(compare(res, ans) == true);
}

void test_case_2() {
    vector<int> nums{};
    vector<vector<int>> ans{};
    vector<vector<int>> res = Solution().fourSum(nums, 0);
    assert(compare(res, ans) == true);
}

void test_case_3() {
    vector<int> nums{1, -2, -5, -4, -3, 3, 3, 5};
    vector<vector<int>> ans{{-5, -4, -3, 1}};
    vector<vector<int>> res = Solution().fourSum(nums, -11);
    assert(compare(res, ans) == true);
}

void test_case_4() {
    vector<int> nums{-1, -5, -5, -3, 2, 5, 0, 4};
    vector<vector<int>> ans{{-5, -5, -1, 4}, {-5, -3, -1, 2}};
    vector<vector<int>> res = Solution().fourSum(nums, -7);
    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
