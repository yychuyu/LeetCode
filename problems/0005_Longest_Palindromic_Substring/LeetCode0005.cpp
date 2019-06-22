/*
最长回文子串
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    string findPalindrome(string s,int left,int right){
        int n = s.size();
        while(left >= 0 && right <= n-1 && s[left] == s[right]){
            left --;
            right ++;
        }
        return s.substr(left + 1,right - left -1);//起点，长度（没有\0）
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        string long_str;
        string str;
        for(int i = 0;i < n-1; i++)
        {
            str = findPalindrome(s,i,i)；//奇数回文数
            if(str.size() > long_str.size()){
                long_str = str;
            }
            str = findPalindrome(s,i,i+1);//偶数回文数
            if(str.size() > long_str.size())
            {
                long_str = str;
            }
        }
        return long_str;
    }
};


int main()
{
    string s;
    cin >> s;
    Solution method;
    cout << method.longestPalindrome(s);
    return 0;
}
