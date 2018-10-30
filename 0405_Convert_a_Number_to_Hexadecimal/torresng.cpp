/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/31
*
***************************************************************/
/**************************************************************
 Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

    1. All letters in hexadecimal (a-f) must be in lowercase.
    2. The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
    3. The given number is guaranteed to fit within the range of a 32-bit signed integer.
    4. You must not use any method provided by the library which converts/formats the number to hex directly.

Example 1:

    Input:
    26

    Output:
    "1a"

Example 2:

    Input:
    -1

    Output:
    "ffffffff"
***************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        char map[16] = {'0','1','2','3','4','5','6','7',
                        '8','9','a','b','c','d','e','f'};
        vector<char> temp;
        unsigned int bin = num;
        while(bin) {
            char hex = map[bin & 0xf];
            temp.push_back(hex);
            bin = bin >> 4;
        }

        string result;
        for(auto it = temp.rbegin(); it != temp.rend(); ++it) {
            result += *it;
        }
        return result;
    }
};

int main(void) {
    Solution s = Solution();
    cout << "26: " << s.toHex(26) << endl;
    cout << "-1: " << s.toHex(-1) << endl;
    cout << "0: " << s.toHex(0) << endl;
    return 0;
}


