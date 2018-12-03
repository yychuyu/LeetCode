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
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        int temp = 1, add = 1, k = 0;
        while(k <= rowIndex) {
            res[0] = res[k] = 1;
            for(int i = 1; i < k; i++) {
                temp = res[i];
                res[i] += add;
                add = temp;
            }
            k++;
        }
        return res;
    }
};

template<class T>
string join(const vector<T>& v, string c) {
    string s;
    for (typename vector<T>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += to_string(*p);
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

int main(void) {
    Solution s = Solution();
    // Example 1
    int k = 3;
    cout << "Input: 3" << endl << "Output: " << join(s.getRow(k), ",") << endl;

    k = 5;
    cout << "Input: 5" << endl << "Output: " << join(s.getRow(k), ",") << endl;

    k = 0;
    cout << "Input: 0" << endl << "Output: " << join(s.getRow(k), ",") << endl;

    k = 6;
    cout << "Input: 6" << endl << "Output: " << join(s.getRow(k), ",") << endl;
    return 0;
}
