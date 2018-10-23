/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/23
*
***************************************************************/
/**************************************************************
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestSum = INT_MIN;
        int sum = 0;
        for(auto n : nums) {
            sum += n;
            if(sum > bestSum) bestSum = sum;
            if(sum < 0) sum = 0;
        }
        return bestSum;
    }
};

int main(void) {
    Solution s = Solution();
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    cout << "[-2,1,-3,4,-1,2,1,-5,4]: " << s.maxSubArray(nums) << endl;
    return 0;
}
