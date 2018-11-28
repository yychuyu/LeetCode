/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/28
*
***************************************************************/
/**************************************************************
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

[](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

    Input: 5
    Output:
    [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
    ]
***************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows <= 0) return res;
        for(int n = 0; n < numRows; n++) {
            vector<int> temp(n+1);
            temp[0] = temp[n] = 1;
            for(int i = 1; i < n; i++) {
                temp[i] = res[n-1][i-1] + res[n-1][i];
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(void) {
    Solution s = Solution();
    // Example 1
    int numRows = 5;
    cout << "5: " << endl;
    auto res = s.generate(5);
    for(auto v : res) {
        for(auto i : v) {
            cout << i << " ";
        }   
        cout << endl;
    }

    return 0;
}




