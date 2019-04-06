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
        if (nums.size() < 3)
            return {};
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size() - 1; ++k) {
            if (nums[k] > 0)
                break;
            while (k < nums.size() && k > 0 && nums[k] == nums[k - 1])
                ++k;
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    ++i;
                } else if (sum > 0) {
                    --j;
                } else {
                    ret.push_back({nums[k], nums[i], nums[j]});
                    while (++i < j && nums[i] == nums[i - 1])
                        ;
                    while (i < --j && nums[j] == nums[j + 1])
                        ;
                }
            }
        }
        return ret;
    }
};

void test_case_1() {
    cout << endl;
    cout << "test_case_1" << endl;
    Solution s = Solution();
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans{{-1, 0, 1}, {-1, -1, 2}};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto vec : res) {
        for (int val : vec) {
            cout << val << ", ";
        }
        cout << endl;
    }
}

void test_case_2() {
    cout << endl;
    cout << "test_case_2" << endl;
    Solution s = Solution();
    vector<int> nums{};
    vector<vector<int>> ans{};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto vec : res) {
        for (int val : vec) {
            cout << val << ", ";
        }
        cout << endl;
    }
}

void test_case_3() {
    cout << endl;
    cout << "test_case_3" << endl;
    Solution s = Solution();
    vector<int> nums{0, 0, 0};
    vector<vector<int>> ans{{0, 0, 0}};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto vec : res) {
        for (int val : vec) {
            cout << val << ", ";
        }
        cout << endl;
    }
}

void test_case_4() {
    cout << endl;
    cout << "test_case_4" << endl;
    Solution s = Solution();
    vector<int> nums{-2, 0, 0, 2, 2};
    vector<vector<int>> ans{{-2, 0, 2}};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto vec : res) {
        for (int val : vec) {
            cout << val << ", ";
        }
        cout << endl;
    }
}

void test_case_5() {
    cout << endl;
    cout << "test_case_5" << endl;
    Solution s = Solution();
    vector<int> nums{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    vector<vector<int>> ans{{-4, -2, 6}, {-4, 0, 4},  {-4, 1, 3},
                            {-4, 2, 2},  {-2, -2, 4}, {-2, 0, 2}};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto vec : res) {
        for (int val : vec) {
            cout << val << ", ";
        }
        cout << endl;
    }
}

void test_case_6() {
    cout << endl;
    cout << "test_case_6" << endl;
    Solution s = Solution();
    vector<int> nums{0, 0};
    vector<vector<int>> ans{};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto vec : res) {
        for (int val : vec) {
            cout << val << ", ";
        }
        cout << endl;
    }
}

int main(void) {
    /*
     *test_case_1();
     *test_case_2();
     */
    test_case_3();
    /*
     *test_case_4();
     *test_case_5();
     *test_case_6();
     */

    return 0;
}
