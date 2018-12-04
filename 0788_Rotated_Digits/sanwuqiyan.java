package practice;

class Solution {
    public int rotatedDigits(int N) {
        int res=0;
        for( int i=1; i<=N; i++ ) {
        	boolean IsGoodNum = true;
        	String temp = String.valueOf(i);
            int weisum = 0;
        	for( int j=0; j<temp.length(); j++ ) {
        		int wei = temp.charAt(j);
        		if( wei!='3' && wei!='4' && wei!='7' ) {
                    if( wei=='0' || wei=='1' || wei=='8' ){
                        weisum++;
                    }
        		}else{
                    IsGoodNum=false;
                    break;
                }
        	}
            if( IsGoodNum && weisum<temp.length() ) res++;
        }
        return res;
    }
}This file is added by 三五七言
