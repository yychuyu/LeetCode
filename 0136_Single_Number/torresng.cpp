/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/23
*
***************************************************************/
/**************************************************************
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

static int fast = []() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int n : nums) {
            result ^= n;
        }
        return result;
    }
};

int main(void) {
    Solution s = Solution();
    vector<int> v {2,2,1};
    cout << "[2,2,1]: " << s.singleNumber(v) << endl;
    v = {4,1,2,1,2};
    cout << "[4,1,2,1,2]: " << s.singleNumber(v) << endl;
    return 0;
}
