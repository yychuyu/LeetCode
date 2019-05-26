class Solution {
public:
    int getSum(int a, int b) {
        int carry = a & b;
        carry = (carry & __INT_MAX__)<<1;
        //carry = carry<<1;
        if(carry==0)
        {
            return a ^ b;
        }
        else
        {
            return getSum(a ^ b,carry);
        }
        
        
    }
};