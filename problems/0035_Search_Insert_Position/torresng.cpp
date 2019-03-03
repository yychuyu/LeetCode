/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/2
*
***************************************************************/
/**************************************************************
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

    Input: [1,3,5,6], 5
    Output: 2

Example 2:

    Input: [1,3,5,6], 2
    Output: 1

Example 3:

    Input: [1,3,5,6], 7
    Output: 4

Example 4:

    Input: [1,3,5,6], 0
    Output: 0
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] > target) {
                r = mid;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return r; 
    }
};

int main(void) {
	Solution s = Solution();

    vector<int> nums {1,3,5,6};
    int target = 5;
	cout << "Input: [1,3,5,6], 5: " << s.searchInsert(nums, target) << endl;

    target = 2;
	cout << "Input: [1,3,5,6], 2: " << s.searchInsert(nums, target) << endl;

    target = 7;
	cout << "Input: [1,3,5,6], 7: " << s.searchInsert(nums, target) << endl;

    target = 0;
	cout << "Input: [1,3,5,6], 0: " << s.searchInsert(nums, target) << endl;
	return 0;
}



