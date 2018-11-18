/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/18
*
***************************************************************/
/**************************************************************
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

    Input: 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

Example 2:

    Input: 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
***************************************************************/
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        static map<int, int> step {{1,1},{2,2},{3,3}};
        auto it = step.find(n);
        if(it != step.end()) {
            return it->second;
        }
        int result = climbStairs(n-1) + climbStairs(n-2);
        step[n] = result;
        return result; 
    }
};

int main(void) {
    Solution s = Solution();
    cout << "2: " << s.climbStairs(2) << endl;
    cout << "3: " << s.climbStairs(3) << endl;
    cout << "5: " << s.climbStairs(5) << endl;

    return 0;
}
