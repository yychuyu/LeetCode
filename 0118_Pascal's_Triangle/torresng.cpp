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
        int idx = 0, len = 1;
        for(int i = 0; i < numRows; i++) {
            vector<int> temp(len);
            temp[idx] = temp[len-1] = 1;
            idx++;
            while(idx < len-1) {
                temp[idx] = res[i-1][idx-1] + res[i-1][idx];
                idx++;
            }
            res.push_back(temp);
            len++;
            idx = 0;
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




