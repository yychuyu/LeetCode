/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/31
*
***************************************************************/
/**************************************************************
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 2^31).

Example 1:

    Input:
    3

    Output:
    3

Example 2:

    Input:
    11

    Output:
    0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
***************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long count = 9;
        int i = 1;
        int start = 1;
        while(n > count*i) {
            start += count;
            n -= count*i;
            count *= 10;
            i++;
        }
        int posInRange = (n-1)/i;
        int posInNum = (n-1)%i;
        int realNum = start + posInRange;
        string s = to_string(realNum);
        return s[posInNum] - '0';
    }
};

int main(void) {
    Solution s = Solution();
    cout << "5th: " << s.findNthDigit(5) << endl;
    cout << "11th: " << s.findNthDigit(11) << endl;
    cout << "12th: " << s.findNthDigit(12) << endl;
    cout << "1000000000th: " << s.findNthDigit(1000000000) << endl;
    return 0;
}

