class Solution {
public:
    int climbStairs(int n) {
        int pre = 1;
        int cur = 1;
        for(int i = 2; i <= n; i ++)
        {
            int tmp = cur;
            cur = pre + cur;
            pre = tmp;

        }   
        return cur;
    }
};