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
        if(digits.size() > 0) {
            vector<string> temp = letterCombinations(digits.substr(1, digits.size() - 1));
            if(temp.size() == 0) temp.push_back("");
            for(char c : index[digits[0] - '0']) {
                for(string str : temp) {
                    res.push_back(c + str);
                }
            }
        }
        return res;
    }
private:
    const vector<string> index {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
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


