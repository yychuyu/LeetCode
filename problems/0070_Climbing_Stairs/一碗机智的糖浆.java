//到第n阶的方法有两种，从n-1到n或者从n-2到n
//所以只要计算出到n-1阶的方法总数在加上n-2阶的总数就ok
class Solution {
    public int climbStairs(int n) {
        if(n==1)return 1;
        int[] dp=new int[n+1];
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
}