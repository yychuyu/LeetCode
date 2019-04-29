class Solution {
public:
    int myAtoi(string str) {
        
        if (str.length() < 1) 
            return 0;
    
        int i = 0;
        while(str[i] == ' '){   // 去除空格
            i++;
        }
        
        //str = str.trim();   // 去掉空格
        char flag = '+';   //默认为正数
        
        if (str[i] == '-'){   //判断是否为负数
            flag = '-';
            i++;
        }
        else if (str[i] == '+'){
            flag = '+';
            i++;
        }
        
        double result = 0;   //字符串对整数的转换
        
        
        while(str.length() > i && str[i] >= '0' && str[i] <= '9'){
            result = result * 10 + str[i] - '0';
            i++;
        }
        
        if (flag == '-')
            result = -result;
        
        if (result > INT_MAX)
            return INT_MAX;
        if (result < INT_MIN)
            return INT_MIN;
        
        return result;
    }
};
