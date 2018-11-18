class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        else if(n == 1)
            return true;
        else
            return isPowerOfTwo(n/2) && !(n%2);
    }
};