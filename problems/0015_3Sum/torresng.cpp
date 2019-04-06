/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/02
 *
 ***************************************************************/
/**************************************************************
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:

The solution set must not contain duplicate triplets.

Example:

  Given array nums = [-1, 0, 1, 2, -1, -4],

  A solution set is:
  [
    [-1, 0, 1],
    [-1, -1, 2]
  ]
***************************************************************/

#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for (unsigned long k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0)
                break;
            while (k < nums.size() && k > 0 && nums[k] == nums[k - 1])
                ++k;
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ret.push_back({nums[k], nums[i], nums[j]});
                    while (++i < j && nums[i] == nums[i - 1])
                        ;
                    while (i < --j && nums[j] == nums[j + 1])
                        ;
                } else if (sum < 0) {
                    ++i;
                } else {
                    --j;
                }
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
        }
    }
    if (n2.size() != 0)
        return false;

    return true;
}

void test_case_1() {
    Solution s = Solution();
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans{{-1, 0, 1}, {-1, -1, 2}};
    vector<vector<int>> res = s.threeSum(nums);
    assert(compare(res, ans) == true);
}

void test_case_2() {
    Solution s = Solution();
    vector<int> nums{};
    vector<vector<int>> ans{};
    vector<vector<int>> res = s.threeSum(nums);
    assert(compare(res, ans) == true);
}

void test_case_3() {
    Solution s = Solution();
    vector<int> nums{0, 0, 0};
    vector<vector<int>> ans{{0, 0, 0}};
    vector<vector<int>> res = s.threeSum(nums);
    assert(compare(res, ans) == true);
}

void test_case_4() {
    Solution s = Solution();
    vector<int> nums{-2, 0, 0, 2, 2};
    vector<vector<int>> ans{{-2, 0, 2}};
    vector<vector<int>> res = s.threeSum(nums);
    assert(compare(res, ans) == true);
}

void test_case_5() {
    Solution s = Solution();
    vector<int> nums{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    vector<vector<int>> ans{{-4, -2, 6}, {-4, 0, 4},  {-4, 1, 3},
                            {-4, 2, 2},  {-2, -2, 4}, {-2, 0, 2}};
    vector<vector<int>> res = s.threeSum(nums);
    assert(compare(res, ans) == true);
}

void test_case_6() {
    Solution s = Solution();
    vector<int> nums{0, 0};
    vector<vector<int>> ans{};
    vector<vector<int>> res = s.threeSum(nums);
    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();

    return 0;
}
