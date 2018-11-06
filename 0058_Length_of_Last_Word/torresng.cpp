/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/06
*
***************************************************************/
/**************************************************************
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

    Input: "Hello World"
    Output: 5
***************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        auto rit = s.rbegin();
        // ignore space
        while(*rit == ' ' && rit != s.rend()) {
            ++rit;
        }
        for(; rit != s.rend(); ++rit) {
            if(*rit == ' ') break;
            result++;
        }
        return result;
    }
};

int main(void) {
    Solution s = Solution();
    cout << "Hello World: " << s.lengthOfLastWord("Hello World") << endl;
    cout << "a: " << s.lengthOfLastWord("a") << endl;
    cout << "a : " << s.lengthOfLastWord("a ") << endl;
    cout << ": " << s.lengthOfLastWord("") << endl;
    return 0;
}

