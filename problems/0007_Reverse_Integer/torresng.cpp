/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/26
*
***************************************************************/
/**************************************************************
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [?231,  231 ? 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31. 
***************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool neg = (x < 0);
		x = abs(x);
		long result = 0, mod = 0;
		while(x) {
			result = (result*10 + x%10);
			x = x / 10;
            if(result != (int)result) return 0; // return 0 if overflow
		}
		return neg ? -result : result;
	}
};

int main(void) {
	Solution s = Solution();
	cout << "123: " << s.reverse(123) << endl;
	cout << "-123: " << s.reverse(-123) << endl;
	cout << "120: " << s.reverse(120) << endl;
	cout << "1056389759: " << s.reverse(1056389759) << endl;
	return 0;
}
