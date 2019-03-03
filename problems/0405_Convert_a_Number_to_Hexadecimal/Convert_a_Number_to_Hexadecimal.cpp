/*
  题目：
  给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
  
  方法：
  取最低4位，得出十六进制字符，左移4位（需要把数当做无符号数），重复相同步骤。
  
  参考：
  https://blog.csdn.net/camellhf/article/details/52680097
*/
class Solution {
public:
    string toHex(int num) {
        string rst="";
        
        if(num==0){
            rst="0";
            return rst;
        }        
        
        string Char = "0123456789abcdef";
        while(num){
            rst = Char[num & 0xF] + rst;
            num = (unsigned)num >> 4;
        }
                
        return rst;         
    }
};
