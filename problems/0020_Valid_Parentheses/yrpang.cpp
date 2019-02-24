/*****************************************************************
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 * 
 *****************************************************************/


#include<map>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> input;

        for(char i : s)
        {
            
                switch(i) {
				case ')':
					if(input.size() != 0 && input.top() == '(') {
						input.pop();
					} else {
						return false;
					}
					break;
				case '}':
					if(input.size() != 0 && input.top() == '{') {
						input.pop();
					} else {
						return false;
					}
					break;
				case ']':
					if(input.size() != 0 && input.top() == '[') {
						input.pop();
					} else {
						return false;
					}
					break;
                
                default:
				input.push(i);
				break;

                }
        }

        if(input.size() == 0) {
			return true;
		} else {
			return false;
		}



    }
};
