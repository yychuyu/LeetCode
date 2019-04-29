/*
有效的括号：
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string s){
    stack<char> st;
    for(auto ch:s)
    {
        if(ch == '{' || ch == '[' || ch == '(')
        {
            st.push(ch);
        }
        else if(ch == '}' || ch == ']' || ch == ')')
        {
            if(st.empty())
                return false;
            char sch = st.top();
            if((sch == '{' && ch == '}') || (sch == '[' && ch == ']') || (sch == '(' && ch == ')'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else{
            return false;
        }
    }
    return st.empty();
}
int main(int argc, char const *argv[])
{
    string s = "{{}{[]()}}";
    if(argc > 1)
    {
        s = argv[1];
    }
    cout << "str == \"" << (s) << "\"" << endl;
    cout << isValid(s) << endl;
    return 0;
}



