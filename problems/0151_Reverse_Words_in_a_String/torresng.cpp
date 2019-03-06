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
        s = trim(s);
        if(s == "") return s;
        reverse(s.begin(), s.end());
        string res = "";
        
        std::string::iterator b = s.begin(), e = s.begin() + 1;
        while(e != s.end()) {
            if(*e == ' ') {
                string temp = string(b, e);
                reverse(temp.begin(), temp.end());
                if(res.empty()) {
                    res = res + temp;
                } else {
                    res = res + " " + temp;
                }
                b = e + 1;
                while(*b == ' ' && *b != '\0') {
                    b++;
                }
                if(*b == '\0') break;
                e = b;
            } else {
                e++;
            }
        }

        if(b != e) {
            string temp = string(b, e);
            reverse(temp.begin(), temp.end());
            if(b != s.begin()) {
                res = res + " " + temp;
            } else {
                res = temp;
            }
        }

        return res;
    }
    std::string & trim(std::string & str)
    {
        return ltrim(rtrim(str));
    }
    std::string & ltrim(std::string & str)
    {
        auto it2 =  std::find_if( str.begin() , str.end() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
        str.erase( str.begin() , it2);
        return str;   
    }

    std::string & rtrim(std::string & str)
    {
        auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
        str.erase( it1.base() , str.end() );
        return str;   
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
