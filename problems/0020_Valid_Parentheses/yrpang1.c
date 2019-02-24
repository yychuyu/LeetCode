/*****************************************************************
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 * 
 *****************************************************************/



#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isValid(char* input);

int main()
{
    
    if(isValid("()"))
    {
        printf("yes");
    }





    return 0;
}



bool isValid(char* input)
{
    char stack[1000];
    int bp = 0, sp = 0;

    int i;
    for(i=0;i<strlen(input);i++)
    {
        if(input[i] == '{' || input[i] == '[' || input[i] == '(')
        {
            sp++;
            stack[sp] = input[i];
        }

        else
        {
            if((input[i] == '}' && stack[sp] == '{' ) || ( input[i] == ']' && stack[sp]=='[' ) || ( input[i] == ')' && stack[sp]=='(' ))
            {
                sp--;
            }
            else return false;
        }

    }

    if(sp == bp) return true;
    
    else 
    {
        return false;
        printf("lll");
    }

}