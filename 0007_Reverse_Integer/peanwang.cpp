class Solution {
public:
    int reverse(int x) {
        bool flag = x>=0;
        x = flag?x:-x;
        long long reverse_x = 0;
        do{
            reverse_x = reverse_x*10 + x%10;
            x/=10;
        }while(x);
        reverse_x *= flag?1:-1;
        return (reverse_x<=INT_MAX && reverse_x>=INT_MIN)?reverse_x:0;
    }
};