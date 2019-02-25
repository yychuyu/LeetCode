//by zchaos
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;//�ж��Ƿ�ΪΪ��
        
        int sign = 1/*�����ű��*/, base = 0/*ת��ֵ*/, i = 0/*����λ��*/, n = str.size();
        while (i < n && str[i] == ' ') ++i;//�ж��Ƿ�Ϊ�ո�
        if (str[i] == '+' || str[i] == '-') {
            sign = (str[i++] == '+') ? 1 : -1;
        }//�ж�����
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 ||(base == INT_MAX / 10&&str[i]-'0'>7)) /*�Ƿ�Խ��*/{
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};
