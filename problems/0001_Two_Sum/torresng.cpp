/***************************************************************
 *   Copyright (C) 2019 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/06/10
 *
 ***************************************************************/
/**************************************************************
Given an array of integers, return indices of the two numbers such that they add
up to a specific target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
***************************************************************/

#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int>::iterator search = map.find(target - nums[i]);
            if(search != map.end()) {
                return {i, search->second};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

bool compare(vector<int> &v1, vector<int> &v2) {
    if (v1.size() != v2.size())
        return false;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

void test_case_1() {
    vector<int> nums{2, 7, 11, 15};
    vector<int> ans{0, 1};
    vector<int> res = Solution().twoSum(nums, 9);
    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();
    return 0;
}
