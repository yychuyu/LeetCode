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
        unsigned i = 0, j = 0;
        while(i != s.size()) {
            if(isspace(s[i]) && ((i == 0) || (isspace(s[i-1])))) {
                i++;
            } else {
                s[j++] = s[i++];
            }
        }

        if(j > 0 && isspace(s[j-1])) j--;  // remove tail space
        s.resize(j);
        reverse(s.begin(), s.end());
    
        auto iter1 = s.begin(), iter2 = s.begin();
        while(iter2 != s.end()) {
            if(isspace(*iter2)) {
                reverse(iter1, iter2);
                iter2++;
                iter1 = iter2;
            } else {
                iter2++;
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
    assert(!s.reverseWords("1 ").compare("1"));

    return 0;
}
