//by zchaos
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;//判断是否为为空
        
        int sign = 1/*正负号标记*/, base = 0/*转化值*/, i = 0/*索引位数*/, n = str.size();
        while (i < n && str[i] == ' ') ++i;//判断是否为空格
        if (str[i] == '+' || str[i] == '-') {
            sign = (str[i++] == '+') ? 1 : -1;
        }//判断正负
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 ||(base == INT_MAX / 10&&str[i]-'0'>7)) /*是否越界*/{
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};
