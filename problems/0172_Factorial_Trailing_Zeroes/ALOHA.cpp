class Solution {
public:
    int trailingZeroes(int n) {
        int i = 0;
        if(n<5)
            return 0;
        while(n>=5){
            n=n/5;
            i=i+n;            
        }
    return i;
    }
};