/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/25
*
***************************************************************/
/**************************************************************
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31. 
***************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int result = 0;
        x ^= y;
        while(x) {
            result += x & 1;
            x = x >> 1;
        }
        return result;
    }
};

int main(void) {
    Solution s = Solution();
    cout << "x = 1, y = 4: " << s.hammingDistance(1, 4) << endl;
    return 0;
}
