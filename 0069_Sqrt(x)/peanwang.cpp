
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        int left = 0,right = x;
        while(left < right-1){
            int mid = left+(right-left)/2;
            if(x/mid < mid)
                right = mid;
            else if(x/mid > mid)
                left = mid;
            else
                return mid;
        }
        return left;
    }
};