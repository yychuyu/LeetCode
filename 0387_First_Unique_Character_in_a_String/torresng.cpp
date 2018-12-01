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
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0) return -1;
        int res = -1;
        unordered_set<int> set1;
        unordered_set<int> set2;
        for(int c : s) {
            if(set2.find(c) == set2.end()) {
                unordered_set<int>::iterator it = set1.find(c);
                if(it == set1.end()) {
                    set1.insert(c);
                } else {
                    set1.erase(it);
                    set2.insert(c);
                }
            }
        }
        if(!set1.empty()) {
            for(int i = 0; i < s.size(); i++) {
                if(set1.find(s[i]) != set1.end())
                    return i;
            }
        }
        return res;
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

