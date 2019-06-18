//解题思路：  动态规划，简历dp数组，dp[i]表示当字符串长度为i时的可能的解码方法次数，
//主要考虑到字符串中有0 以及有些可以组成2位的（10-26），所以分为当前位为0和不为0的情况
//为0的时候考虑前一位为1或者2，那么dp[i]=dp[i-2]，不然的话直接返回0;
//不为0的时候考虑是否可以组成2位的，10-26，如果可以组成2位的，dp[i]=dp[i-1]+dp[i-2],不然dp[i]=dp[i-1]
class Solution {
    public int numDecodings(String s) {
        if(s.length()==0||s.equals("0")||s.charAt(0)=='0')return 0; 
	     int n=s.length();
	     char[] c=s.toCharArray();
	     int[] dp=new int[n+1];
	     dp[0]=1;
	     dp[1]=1;
	     for(int i=1;i<n;i++) {
	    	 if(c[i]=='0') {
	    		 if(c[i-1]=='1'||c[i-1]=='2') {
	    			 dp[i+1]=dp[i-1];
	    		 }else {
	    			return 0;
	    		 }
	    	 }else {
	    		 if((c[i-1]=='1'||(c[i-1]=='2'&&c[i]<'7'))) {
	    			 dp[i+1]=dp[i]+dp[i-1];
	    		 }else {
	    			 dp[i+1]=dp[i];
	    		 }
	    	 }
	     }
	    return dp[n];	 
		 	 
    }
}
