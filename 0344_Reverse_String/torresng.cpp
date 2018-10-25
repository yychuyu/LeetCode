/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/25
*
***************************************************************/
/**************************************************************
Write a function that takes a string as input and returns the string reversed.

Example 1:

Input: "hello"
Output: "olleh"

Example 2:

Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
***************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        if(s.empty()) return s;
        int i = 0, j = s.size() - 1;
        while(i < j) {
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main(void) {
    Solution s = Solution();
    cout << "hello: " << s.reverseString("hello") << endl;
    cout << "A man, a plan, a canal: Panama: " << s.reverseString("A man, a plan, a canal: Panama") << endl;
    return 0;
}
