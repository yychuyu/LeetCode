/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/27
*
***************************************************************/
/**************************************************************
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:

All given inputs are in lowercase letters a-z.
***************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if(strs.size() == 0) return "";
		if(strs.size() == 1) return strs[0];

		string s1 = strs[0];
		size_t min_size = s1.size();
		for(int i = 1; i < strs.size(); i++) {
			string s2 = strs[i];
			if(s2.size() == 0) return "";
			size_t count = 0;
			size_t min = (min_size < s2.size()) ? min_size : s2.size();
			for(int j = 0; j < min_size; j++) {
				if(s1[j] == s2[j]) {
					count++;
				} else {
					break;
				}
			}
			min_size = count;
		}
		s1.resize(min_size);
		return s1;
    }
};

int main(void) {
	Solution s = Solution();
	vector<string> v {"flower","flow","flight"};
	cout << "[\"flower\",\"flow\",\"flight\"]: \"" << s.longestCommonPrefix(v) << "\"" << endl;
	v = {"dog","racecar","car"};
	cout << "[\"dog\",\"racecar\",\"car\"]: \"" << s.longestCommonPrefix(v) << "\"" << endl;
	return 0;
}

