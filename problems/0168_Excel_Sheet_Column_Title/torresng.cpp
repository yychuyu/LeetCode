/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     Torres Ng
*   Create Time 2018/12/10
*
***************************************************************/
/**************************************************************
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

Example 1:

    Input: 1
    Output: "A"

Example 2:

    Input: 28
    Output: "AB"

Example 3:

    Input: 701
    Output: "ZY"
***************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0) {
            res.insert(res.begin(), 'A' + (n - 1) % 26);
            n = (n - 1) / 26;
        }
        return res;
    }
};

int main(void) {
	Solution s = Solution();

    int n = 1;
	cout << "Input: 1" << endl << "Output: " << s.convertToTitle(n) << endl;
    n = 27;
	cout << "Input: 27" << endl << "Output: " << s.convertToTitle(n) << endl;
    n = 28;
	cout << "Input: 28" << endl << "Output: " << s.convertToTitle(n) << endl;
    n = 701;
	cout << "Input: 701" << endl << "Output: " << s.convertToTitle(n) << endl;
	return 0;
}
