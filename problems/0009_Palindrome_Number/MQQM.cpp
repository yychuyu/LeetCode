/*
  题目：
  判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
  
  做法：利用第7题的整数反转。
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        int revs = reverse(x);
        if(revs != x){
            return false;
        }
        
        return true;
    }
    int reverse(int x) {//第7题的整数反转
        int y = abs(x);
        
        long rst = 0;
        while (y > 0) {    
            rst = rst * 10 + y % 10;    
            y /= 10;  
        }    
        rst = (x > 0) ? rst : -rst;
        
        if (rst > INT32_MAX || rst < INT32_MIN) {            
            return 0;      
        }else {            
            return (int)rst;      
        }
    } 
};
