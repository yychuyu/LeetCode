/*
正则表达式与匹配
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

/******************************************
class Solution {
public:
    bool isMatch(char* s, char* p) {
        if(*p == '\0'){
            return *s == '\0';
        }
        if(*(p+1) == '\0' || *(p+1)!= '*'){
            if(*s == '\0' || (*p =  '.'&&*s != *p)){
                return false;
            }
            return isMatch(s+1,p+1);
        }
        int len = strlen(s);//包含\0的字符串长度
        int i = -1;
        while(i < len && (i < 0 || *p == '.' || *p == *(s+i))){
            if(isMatch(s+i+1,p+2)){
                return true;
            }
            i++;
        }
        return false;
    }
};
********************************************/
//动态规划
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int lens = s.length(), lenp = p.length();
        bool **dp = new bool *[lens + 2];
        for (int i = 0; i < lens + 2; i++)
            dp[i] = new bool[lenp + 2];

        for (int i = 0; i < lens + 2; i++)
            for (int j = 0; j < lenp + 2; j++)
                dp[i][j] = false;
        dp[0][0] = true;

        for (int i = 1; i < lenp; i++)
            if (p[i] == '*' && dp[0][i - 1])
                dp[0][i + 1] = true;

        for (int i = 0; i < lens; i++)
            for (int j = 0; j < lenp; j++)
            {
                if (s[i] == p[j] || p[j] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                else if (p[j] == '*')
                {
                    if (p[j - 1] != s[i] && p[j - 1] != '.')
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    else
                        dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                }
            }

        return dp[lens][lenp];
    }
};
int main()
{
    string s = "aaa";
    string p = "a*";
    cin >> s;
    cin >> p;
    Solution method;
    bool result = method.isMatch(s, p);
    cout << result;//method.isMatch(s, p);
    return 0;
}
