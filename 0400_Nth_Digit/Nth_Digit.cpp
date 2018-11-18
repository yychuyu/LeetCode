/*
  题目：
  在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。

  1-9     有9*1个数字，    9*10^(1-1)*1
  10-99   有90*2个数字，   9*10^(2-1)*2
  100-999 有900*3个数字，  9*10^(3-1)*3
*/
class Solution {
public:
    int findNthDigit(int n) {        
        int bit_num=1; //几位数      
        while( n > 9*pow(10,bit_num-1)*bit_num ){                
            n -= 9*pow(10,bit_num-1)*bit_num;               
            bit_num++;
        }
             
        int s = (n-1)/bit_num;
        int y = (n-1)%bit_num;      
        int num=pow(10,bit_num-1)+s;
            
        for(int j=0; j<bit_num-1-y; j++){
            num /= 10;        
        }            
             
        return num%10;        
    }
};
