class Solution {
public:
    bool judgeSquareSum(int c) {
        int head = 0;
        long long n = int(sqrt(c));
        long long tail = n;
        while (head <= tail){
            long long res = head * head + tail * tail;
            if (res == c) return true;
            else if (res > c) 
                tail -= 1;
            else head += 1;
        }
        return false;
    }
};
