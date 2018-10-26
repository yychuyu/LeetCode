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
		string result = "";

		sort(strs.begin(), strs.end());
		
		bool has_diff = false;
		size_t i = 0;
		while(!has_diff && i < strs[0].size()) {
			char c = strs[0][i];
			for(int j = 1; j < strs.size(); j++) {
				has_diff = strs[j][i] != c;
				if(has_diff) break;
			}
			if(!has_diff) result += c;
			i++;
		}
		return result;
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

