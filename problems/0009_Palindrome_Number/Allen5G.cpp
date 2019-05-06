/*
 * Reverse Integer.cpp
 *
 * May,5 2019 
 *
 * Author:lkk789@aliyun.com
 *
 */
 
 /*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:
你能不将整数转为字符串来解决这个问题吗？

 */


/**
 * Palindrome Number
 * 回文数
*/

#include <stdio.h>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }
        
        int len=1;
        for (len=1; (x/len) >= 10; len*=10 );
        
        while (x != 0 ) {
            int left = x / len;
            int right = x % 10;
            
            if(left!=right){
                return false;
            }
            
            x = (x%len) / 10;
            len /= 100;
        }
        return true;
    }
    
    bool isPalindrome2(int x) {
        return (x>=0 && x == reverse(x));
    }
private:    
    int reverse(int x) {
        int y=0;
        int n;
        while( x!=0 ){
            n = x%10;
            y = y*10 + n;
            x /= 10;
        }
        return y;
    }
};
int main()
{
    Solution s;
    printf("%d is %d\n", 0, s.isPalindrome(0) );
    printf("%d is %d\n", -101, s.isPalindrome(-101) );
    printf("%d is %d\n", 1001, s.isPalindrome(1001) );
    printf("%d is %d\n", 1234321, s.isPalindrome(1234321) );
    printf("%d is %d\n", 2147447412, s.isPalindrome(2147447412) );
    printf("%d is %d\n", 2142, s.isPalindrome(2142) );
}