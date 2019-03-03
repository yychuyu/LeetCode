/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/25
*
***************************************************************/
/**************************************************************
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
 
https://assets.leetcode.com/uploads/2018/10/12/keyboard.png

Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

 

Note:

    1. You may use one character in the keyboard more than once.
    2. You may assume the input string will only contain letters of alphabet.
***************************************************************/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> row1 {'q','w','e','r','t','y','u','i','o','p'};
        set<char> row2 {'a','s','d','f','g','h','j','k','l'};
        set<char> row3 {'z','x','c','v','b','n','m'};
        vector<string> result;
        for(string word : words) {
            int i = word.size();
            for(char c : word) {
                c = tolower(c);
                if(row1.count(c)) i--;
            }
            if(i == 0) { 
                result.push_back(word);
                continue;
            }
            i = word.size();
            for(char c : word) {
                c = tolower(c);
                if(row2.count(c)) i--;
            }
            if(i == 0) { 
                result.push_back(word);
                continue;
            }
            i = word.size();
            for(char c : word) {
                c = tolower(c);
                if(row3.count(c)) i--;
            }
            if(i == 0) { 
                result.push_back(word);
                continue;
            }
        }
        return result;
    }
};

string join(const vector<string>& v, string c) {
    string s;
    for (vector<string>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += *p;
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

int main(void) {
    Solution s = Solution();
    vector<string> words {"Hello", "Alaska", "Dad", "Peace"};
    cout << "[\"Hello\", \"Alaska\", \"Dad\", \"Peace\"]: " << join(s.findWords(words), ", ") << endl;
    return 0;
}
