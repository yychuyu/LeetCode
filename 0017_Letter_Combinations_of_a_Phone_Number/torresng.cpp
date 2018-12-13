/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/13
*
***************************************************************/
/**************************************************************
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

Example:

    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
***************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> index {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int idx = digits[0] - '0';
        for(char letter : index[idx]) res.push_back(string(1,letter));
        for(int i = 1; i < digits.size(); i++) {
            idx = digits[i] - '0';
            vector<string> temp;
            for(char letter: index[idx]) {
                for(string t : res) {
                    temp.push_back(t + letter);
                }
            }
            res = temp;
            temp.clear();
        }
        return res;
    }
};

template<class T>
string join(const vector<T>& v, string c) {
    string s;
    for (typename vector<T>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += to_string(*p);
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

template<>
string join(const vector<string> &v, string c) {
    string s;
    for (vector<string>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += "\"" + *p + "\"";
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

int main(void) {
	Solution s = Solution();
    string digits = "23";
	cout << "\"23\": ";
    vector<string> res = s.letterCombinations(digits);
	cout << join(res, ",") << endl;
	return 0;
}


