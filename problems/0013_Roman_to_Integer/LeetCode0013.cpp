/*
罗马数字倒转
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution{
public:
    int romanToInt(string s) {
        int result = 0;
        int n = s.length();
        for(int i=0; i < n;i++){
            switch(s[i])
            {
                case'I':
                    if(i<n-1 && s[i+1]=='V')
                    {
                        result+=4;
                        i++;
                    }
                    else if(i<n-1 && s[i+1]=='X')
                    {
                        result+=9;
                        i++;
                    }
                    else result++;
                    break;
                case'V':
                    result+=5;
                    break;
                case'X':
                    if(i<n-1 && s[i+1]=='L')
                    {
                        result+=40;
                        i++;
                    }
                    else if(i<n-1 && s[i+1]=='C')
                    {
                        result+=90;
                        i++;
                    }
                    else result+=10;
                    break;
                case'L':
                    result+=50;
                    break;
                case'C':
                    if(i<n-1 &&s[i+1]=='D')
                    {
                        result+=400;
                        i++;
                    }
                    else if(i<n-1 && s[i+1]=='M')
                    {
                        result+=900;
                        i++;
                    }
                    else result+=100;
                    break;
                case'D':
                    result+=500;
                    break;
                case'M':
                    result+=1000;
            }
        }
        return result;
    }
};

int main()
{
    //string s = "MCMXCIV";
    string s = "LVIII";    
    int result;
    Solution method;
    result = method.romanToInt(s);
    cout << "result:" << result << endl;
    return 0;
}