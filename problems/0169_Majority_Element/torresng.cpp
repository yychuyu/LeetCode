/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/12
*
***************************************************************/
/**************************************************************
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

    Input: [3,2,3]
    Output: 3

Example 2:

    Input: [2,2,1,1,1,2,2]
    Output: 2
***************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res, count = 0;
        for(int num : nums) {
            if(count == 0) {
                res = num;
                count = 1;
            } else {
                count += (res == num) ? 1 : -1;
            }

        }
        return res;
    }
};

int main(void) {
    Solution s = Solution();
    vector<int> nums {3,2,3};
    cout << "Input: [3,2,3]" << endl << "Output: " << s.majorityElement(nums) << endl;
    nums = {2,2,1,1,1,2,2};
    cout << "Input: [2,2,1,1,1,2,2]" << endl << "Output: " << s.majorityElement(nums) << endl;
    return 0;
}

