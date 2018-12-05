/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/1
*
***************************************************************/
/**************************************************************
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.

Note: You may assume the string contain only lowercase letters. 
***************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(27, 0);
        for(char c : s) {
            vec[c-'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(vec[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};

int main(void) {
    Solution s = Solution();
    string str = "leetcode";
    cout << "s = \"leetcode\"" << endl << "return " << s.firstUniqChar(str) << endl;
    str = "loveleetcode";
    cout << "s = \"loveleetcode\"" << endl << "return " << s.firstUniqChar(str) << endl;
    return 0;
}

