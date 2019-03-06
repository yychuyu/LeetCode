/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2019/03/06
*
***************************************************************/
/**************************************************************
Given an input string, reverse the string word by word.

Example 1:

    Input: "the sky is blue"
    Output: "blue is sky the"

Example 2:

    Input: "  hello world!  "
    Output: "world! hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

    Input: "a good   example"
    Output: "example good a"
    Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:

    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in the reversed string.
***************************************************************/

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string::iterator iter1 = s.begin(), iter2 = s.begin();
        while(iter1 != s.end()) {
            if(isspace(*iter1) && (iter1 == s.begin() || isspace(*(iter1 - 1)))) {
                iter1++;
            } else {
                *iter2 = *iter1;
                iter1++;
                iter2++;
            }
        }
        
        if((iter2 != s.begin()) && isspace(*(s.end() - 1))) iter2--;
        s.resize(iter2 - s.begin());
        if(s.empty()) return s;

        reverse(s.begin(), s.end());
        for(iter1 = s.begin(), iter2 = s.begin() + 1; iter2 != s.end(); iter2++) {
           if(isspace(*iter2)) {
                reverse(iter1, iter2);
                iter1 = iter2 + 1;
           }
        }
        reverse(iter1, iter2);
        return s;
    }
};

int main(void) {
    Solution s = Solution();
    assert(!s.reverseWords("the sky is blue").compare("blue is sky the"));
    assert(!s.reverseWords("  hello world!  ").compare("world! hello"));
    assert(!s.reverseWords("a good   example").compare("example good a"));
    assert(!s.reverseWords("").compare(""));
    assert(!s.reverseWords("  ").compare(""));
    assert(!s.reverseWords("a").compare("a"));

    return 0;
}
