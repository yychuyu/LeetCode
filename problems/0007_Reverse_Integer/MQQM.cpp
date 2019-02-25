/*
  题目：
  给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
  
  注意:
  假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
class Solution {
public:
    int reverse(int x) {  
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
