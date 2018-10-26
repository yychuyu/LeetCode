/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/26
*
***************************************************************/
/**************************************************************
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:

Coud you solve it without converting the integer to a string?
***************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		long result = 0, mod = 0;
		while(x) {
			mod = x % 10;
			x = x / 10;
			result = (result * 10 + mod);
		}
		return result;
	}
    bool isPalindrome(int x) {
        if(x < 0) return false; 
        if(reverse(x) == x) return true;
        return false;
    }
};

int main(void) {
	Solution s = Solution();
    cout << "121: " << boolalpha << s.isPalindrome(121) << endl;
    cout << "-121: " << boolalpha << s.isPalindrome(-121) << endl;
    cout << "10: " << boolalpha << s.isPalindrome(10) << endl;

	return 0;
}
