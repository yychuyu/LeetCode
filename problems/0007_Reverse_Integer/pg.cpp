class Solution {
    public:
    int reverse(int x) {
        long ret=0;
        bool sign = false;
        int date = 0;
        x < 0 ? (sign = true):(sign = false);
        date = x > 0 ? x: -x;
        int remainder = date;
        int tail[10] = {0};
        int len = 0;
        while(remainder){
            tail[len++] = remainder%10;
            remainder/=10;
        }
        for (int i = 0; i < len; ++i){
            /* code */
            long overData = 0;
            ret += tail[i]*pow(10,len-i-1);
            sign ? (overData = - ret) : (overData = ret);
            if(overData > INT_MAX || overData < INT_MIN){
                return 0;
            }
            
        }
        sign ? (ret = (int)(-ret)):(ret = (int)ret);
        return ret;
    }
};
