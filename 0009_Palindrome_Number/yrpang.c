/***************************************************************************
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
****************************************************************************/



#include<stdio.h>
#include<stdbool.h>


bool isPalindrome(int x) {

    if(x<0) return false;

    else{
        int pop,com=0;
        int old = x;
        while(x!=0)
        {
            pop = x%10;
            com= com * 10 + pop;
            x = x / 10;
        }
        if(com == old) return true;
        else return false;
    }
    
}



int main()
{
    int input;
    scanf("%d",&input);
    printf("%d",isPalindrome(input));
    return 0;
}
