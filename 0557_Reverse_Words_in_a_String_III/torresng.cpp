/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/03
*
***************************************************************/
/**************************************************************
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

    Input: "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string. 
***************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string::iterator iter1 = s.begin(), iter2 = s.begin();
        while(iter2 != s.end()) {
            if(*iter2 == ' ') {
                reverse(iter1, iter2);
                iter2++;
                iter1 = iter2;
            } else {
                iter2++;
            }
        }
        if(iter2 - iter1 > 1) {
            reverse(iter1, iter2);
        }
        return s;
    }
};

int main(void) {
    Solution s = Solution();
    string str = "Let's take LeetCode contest";
    cout << "Input: \"Let's take LeetCode contest\"\nOutput: " << s.reverseWords(str) << endl;
    return 0;
}

