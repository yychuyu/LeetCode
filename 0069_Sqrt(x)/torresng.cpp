/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/10
*
***************************************************************/
/**************************************************************
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

    Input: 4
    Output: 2

Example 2:

    Input: 8
    Output: 2
    Explanation: The square root of 8 is 2.82842..., and since 
                 the decimal part is truncated, 2 is returned.
***************************************************************/
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int i = 0, j = x;
        while(i <= j) {
            int mid = (i + j)/2; // i + (j - i)/2 = (2i + j - i)/2 = (i + j)/2
            if(mid == x/mid) {
                return mid;
            } else if(mid > x/mid) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return j;
    }
};

int main(void) {
    Solution s = Solution();
    cout << "4: " << s.mySqrt(4) << endl;
    cout << "6: " << s.mySqrt(6) << endl;
    cout << "8: " << s.mySqrt(8) << endl;
    cout << "2147395600: " << s.mySqrt(2147395600) << endl;
    return 0;
}
