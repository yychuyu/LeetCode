/*
  题目：
  请你来实现一个 atoi 函数，使其能将字符串转换成整数。
  
  参考：
  https://blog.csdn.net/u014056175/article/details/51768217
*/
class Solution {
public:        
    int myAtoi(string str){
        int i = 0;         
        while( isspace(str[i]) ){           
            i++;
        }
                   
        int sign = 1;       
        if(str[i]=='-' || str[i]=='+'){          
            if(str[i++] == '-'){
                sign *= -1;
            }
        }
          
        while(str[i]=='0'){
            i++;
        }
        
        long num = 0;            
        while( isdigit(str[i]) ){
            num = 10*num + (str[i++]-'0');
            if( num > fabs(long(INT_MIN)) ){
                break;
            }
        }
            
        num *= sign;
        
        if(num > INT_MAX){
            return INT_MAX;
        }
        if(num < INT_MIN){
            return INT_MIN;
        } 
        return num;
    }
};

/*
还有一种方法
class Solution {
public:
    int myAtoi(string str) {
        int out = 0;
        stringstream ss;
        ss << str;
        ss >> out;
        return out;
    }
};
*/
