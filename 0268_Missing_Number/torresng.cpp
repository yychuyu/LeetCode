/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/22
*
***************************************************************/
/**************************************************************
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2

Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
***************************************************************/
#include <iostream>
#include <vector>

using namespace std;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto find_num = nums.size();
        for(auto i = 0; i < nums.size(); i++) {
            find_num ^= nums[i] ^ i;
        }
        return find_num;
    }
};

int main(void) {
    Solution s = Solution();
    vector<int> v1 {3,0,1};
    cout << "[3,0,1] : " << s.missingNumber(v1) << endl;
    vector<int> v2 {9,6,4,2,3,5,7,0,1};
    cout << "[9,6,4,2,2,3,5,7,0,1] : " << s.missingNumber(v2) << endl;
    return 0;
}
