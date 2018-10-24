/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/24
*
***************************************************************/
/**************************************************************
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
***************************************************************/

/***************************************************************
題解: 
http://blog.torresng.com/2018/10/24/LeetCode-No-198-House-Robber/#more
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int count = nums.size();
        if(count == 0) return 0;
        vector<int> money(count);
        if(count > 0) money[0] = nums[0];
        if(count > 1) money[1] = max(nums[0], nums[1]);
        if(count > 2) money[2] = max(nums[0]+nums[2], nums[1]);
        for(int i = 3; i < count ; i++) {
            money[i] = max(money[i-3]+nums[i-1], money[i-2]+nums[i]);
        }
        return money[count - 1];
    }
};

int main(void) {
    Solution s = Solution();
    vector<int> v {1,2,3,1};
    cout << "[1,2,3,1]: " << s.rob(v) << endl;
    v = {2,7,9,3,1};
    cout << "[2,7,9,3,1]: " << s.rob(v) << endl;

    return 0;
}
