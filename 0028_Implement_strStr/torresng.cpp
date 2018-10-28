/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/28
*
***************************************************************/
/**************************************************************
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

    Input: haystack = "hello", needle = "ll"
    Output: 2

Example 2:

    Input: haystack = "aaaaa", needle = "bba"
    Output: -1

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
***************************************************************/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;    
        for(int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; i++) {
            bool match = true;
            for(int j = 0; j < needle.size(); j++) {
                if(haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if(match) return i;
        }
        return -1;
    }
};

int main(void) {
	Solution s = Solution();
    string haystack = "hello", needle = "ll";
	cout << "haystack = \"hello\", needle = \"ll\": " << boolalpha << s.strStr(haystack, needle) << endl;
    haystack = "aaaaa";
    needle = "bba";
	cout << "haystack = \"aaaaa\", needle = \"bba\": " << boolalpha << s.strStr(haystack, needle) << endl;
    haystack = "abb";
    needle = "abaaa";
	cout << "haystack = \"aaaaa\", needle = \"bba\": " << boolalpha << s.strStr(haystack, needle) << endl;
	return 0;
}


