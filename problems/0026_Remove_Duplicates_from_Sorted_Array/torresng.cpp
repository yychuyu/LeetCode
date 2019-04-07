/***************************************************************
 *   Copyright (C) 2018 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2018/10/08
 *
 ***************************************************************/
/**************************************************************
Given a sorted array nums, remove the duplicates in-place such that each element
appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the
input array in-place with O(1) extra memory.

Example 1:

    Given nums = [1,1,2],

    Your function should return length = 2, with the first two elements of nums
being 1 and 2 respectively.

    It doesn't matter what you leave beyond the returned length.

Example 2:

    Given nums = [0,0,1,1,1,2,2,3,3,4],

    Your function should return length = 5, with the first five elements of nums
being modified to 0, 1, 2, 3, and 4 respectively.

    It doesn't matter what values are set beyond the returned length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to
the input array will be known to the caller as well.

Internally you can think of this:

    // nums is passed in by reference. (i.e., without making a copy)
    int len = removeDuplicates(nums);

    // any modification to nums in your function would be known by the caller.
    // using the length returned by your function, it prints the first len
elements. for (int i = 0; i < len; i++) { print(nums[i]);
    }
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int k = 0, len = 1;
        for (unsigned long i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i];
                ++len;
            }
        }
        return len;
    }
};

void test_case_1() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ans = 5;
    vector<int> ansNums = {0, 1, 2, 3, 4};
    assert(Solution().removeDuplicates(nums) == ans);
    for (int i = 0; i < ans; i++) {
        assert(nums[i] == ansNums[i]);
    }
}

void test_case_2() {
    vector<int> nums = {1, 1, 2};
    int ans = 2;
    vector<int> ansNums = {1, 2};
    assert(Solution().removeDuplicates(nums) == ans);
    for (int i = 0; i < ans; i++) {
        assert(nums[i] == ansNums[i]);
    }
}

int main(void) {
    test_case_1();
    test_case_2();
    return 0;
}
