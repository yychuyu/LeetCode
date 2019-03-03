/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     Torres Ng
*   Create Time 2018/11/5
*
***************************************************************/
/**************************************************************
The count-and-say sequence is the sequence of integers with the first five terms as following:

    1.     1
    2.     11
    3.     21
    4.     1211
    5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ² n ² 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

    Input: 1
    Output: "1"

Example 2:

    Input: 4
    Output: "1211"
***************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		string result = "1";
    	string s; 
		for(int j = 1; j < n; j++) {
            s = result;
			result.clear();
            int count = 1;
            char c = s[0];
			int i = 1;
			while(i < s.size()) {
                if(c != s[i]) {
                    result += (to_string(count) + c);
                    c = s[i];
                    count = 1;
                } else {
                    count++;
                }
                i++;
			}
            result += (to_string(count) + c);
            if(!result.empty()) {
                s = result;
            }
		}
		return result;
    }
};

int main(void) {
	Solution s = Solution();

	cout << "1: " << s.countAndSay(1) << endl;
	cout << "4: " << s.countAndSay(4) << endl;
	return 0;
}




