/*
有效的括号
右侧括号出现时必须和左侧的匹配上，不然就直接输出错误！
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static bool isValid(char *s)
{
    int n = 0,cap = 100;
    char *stack = malloc(cap);
    stack[n] = '\0';
    while (*s != '\0')
    {
        switch(*s)
        {
            case('('):
            case('['):
            case('{'):
                if(n+1>=cap)
                {
                    cap *= 2;
                    stack = realloc(stack,cap);//对于stack的空间进行重新赋值
                }
                stack[n++] = *s;
                break;
            case(')'):
                if(stack[--n] != '(')
                return false;
                break;
            case (']'):
                if(stack[--n] != '[')
                return false;
                break;
            case('}'):
                if(stack[--n] != '{')
                return false;
                break;
            default:
                return false;
        }
        s++;
    }
    return n == 0;
}
int main(int argc, char **argv)
{
    char *s = "{{}{[]()}}";
    printf("%s\n",s);
    printf("%s\n",isValid(s)?"true":"false");
    return 0;
}
