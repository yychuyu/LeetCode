/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/26
*
***************************************************************/
/**************************************************************
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

    Input: "A man, a plan, a canal: Panama"
    Output: true

Example 2:

    Input: "race a car"
    Output: false
***************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int start = 0, end = s.size()-1;
        while(start < end) {
            if(!isalnum(s[start])) {
                ++start;
                continue;
            }
            if(!isalnum(s[end])) {
                --end;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};

int main(void) {
    Solution s = Solution();
    // Example 1
    string str = "A man, a plan, a canal: Panama";
    cout << "\"A man, a plan, a canal: Panama""\": " << boolalpha << s.isPalindrome(str) << endl;

    // Example 2
    str = "race a car";
    cout << "\"race a car""\": " << boolalpha << s.isPalindrome(str) << endl;

    // Example 3
    str = "0P";
    cout << "\"0P""\": " << boolalpha << s.isPalindrome(str) << endl;

    // Example 4
    str = "ab@a";
    cout << "\"ab@a""\": " << boolalpha << s.isPalindrome(str) << endl;

    return 0;
}



