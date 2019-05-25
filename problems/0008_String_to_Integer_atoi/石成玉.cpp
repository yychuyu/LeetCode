class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int i = 0;
        int sign = 1;
        while (str[i] == ' ')
            i++;
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+')
            i++;
        if (str[i] > '9' || str[i] < '0')
            return 0;
        while (str[i] <= '9' && str[i] >= '0') {
            result = result * 10 + (str[i++] - '0');
            if (result > INT_MAX && sign == 1)
                return INT_MAX;
            if (result > INT_MAX && sign == -1)
                return INT_MIN;
        }
        return result*sign;
    }
};
