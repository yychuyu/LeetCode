/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/27
*
***************************************************************/
/**************************************************************
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true


***************************************************************/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> sk;
		for(char c : s) {
			switch(c) {
				case ')':
					if(sk.size() != 0 && sk.top() == '(') {
						sk.pop();
					} else {
						return false;
					}
					break;
				case '}':
					if(sk.size() != 0 && sk.top() == '{') {
						sk.pop();
					} else {
						return false;
					}
					break;
				case ']':
					if(sk.size() != 0 && sk.top() == '[') {
						sk.pop();
					} else {
						return false;
					}
					break;
				default:
					sk.push(c);
					break;
			}
		}
		if(sk.size() == 0) {
			return true;
		} else {
			return false;
		}
	}
};

int main(void) {
	Solution s = Solution();
	cout << "\"()\": " << boolalpha << s.isValid("()") << endl;
	cout << "\"()[]{}\": " << boolalpha << s.isValid("()[]{}") << endl;
	cout << "\"(]\": " << boolalpha << s.isValid("(]") << endl;
	cout << "\"([)]\": " << boolalpha << s.isValid("([)]") << endl;
	cout << "\"{[]}\": " << boolalpha << s.isValid("{[]}") << endl;
	return 0;
}

