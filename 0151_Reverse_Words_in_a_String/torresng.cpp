/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/03
*
***************************************************************/
/**************************************************************
Given an input string, reverse the string word by word.

Example:  

    Input: "the sky is blue",
    Output: "blue is sky the".

Note:

    * A word is defined as a sequence of non-space characters.
    * Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    * You need to reduce multiple spaces between two words to a single space in the reversed string.

Follow up: For C programmers, try to solve it in-place in O(1) space.
***************************************************************/
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        string::iterator it1 = s.begin(), it2 = s.end();
        unsigned last_space_nums  = 0;
        it2--;
        while(it2 >= it1)  {
            if(*it2 == ' ') {
                it2--;
                last_space_nums++;
            } else {
                break;
            }
        }
        it2++;
        unsigned first_space_nums = 0;
        while(it1 != it2) {
            if(*it1 == ' ') {
                it1++;
                first_space_nums++;
            } else {
                break;
            }
        }
        if(it1 != s.begin()) {
            copy(it1, it2, s.begin());
            s.resize(it2 - it1);
        }

        reverse(s.begin(), s.end());
        while(*it1 == ' ') it1++;
        it2 = it1;
        while(it1 != s.end() && it2 != s.end()) {
            if(*it2 == ' ') {
                reverse(it1, it2);
                it1 = it2 + 1;
                it2 += 2;
            } else {
                it2++;
            }
        }
        if(it1 != s.end()) {
            reverse(it1, it2);
        }
    }
};

int main(void) {
    Solution s;
    string str = "the sky is blue";
    s.reverseWords(str);
    cout << "input: \"the sky is blue\"" << endl;
    cout << "output: \"" << str << "\"" << endl;

    str = " ";
    s.reverseWords(str);
    cout << "input: \" \"" << endl;
    cout << "output: \"" << str << "\"" << endl;

    str = " 1";
    s.reverseWords(str);
    cout << "input: \" 1\"" << endl;
    cout << "output: \"" << str << "\"" << endl;

    str = " a ";
    s.reverseWords(str);
    cout << "input: \" a \"" << endl;
    cout << "output: \"" << str << "\"" << endl;

    return 0;
}

