
/**
* LeetCode The 8th problem :string-to-integer-atoi
* Auth:Barlowwang
* Date:2019-03-16
**/
#include <iostream>
#include <string>
using namespace std;
#define INT_MAX 2147483647
int myAtoi(string str)
{
    int i = 0, len = str.length();
    long long sum = 0;
    char tmp, sign = '+';
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ')
            break;
    }
    if (str[i] == '+' || str[i] == '-')
    {
        sign = str[i];
        i++;
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
    }
    else if (str[i] > '9' || str[i] < '0')
    {
        return 0;
    }
    for (; i < len; i++)
    {
        tmp = str[i];
        if (tmp < '0' || tmp > '9')
            break;
        sum =sum * 10 + tmp - '0';
        if(sum-INT_MAX>0)
        {
            return sign == '+' ? INT_MAX : INT_MAX * -1 - 1;
        }
    }
    return sign == '+' ? sum : sum * -1;
}
int  main()
{
    string s;
    while(1){
        cin>>s;
        cout<<endl<<myAtoi(s)<<endl;
    }
}