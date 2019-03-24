class Solution {
   public String longestPalindrome(String s) {
        if(s.length()<1) return "";
        int start = 0;
        int end=0;
        
        for(int i=0 ; i<s.length()-1 ; i++){
            int len1 = center(s,i,i);
            int len2 = center(s,i,i+1);
            int len = Math.max(len1,len2);
            if(len>end-start+1){
                end = i+len/2;
                start = i-(len-1)/2;
            }
            
        }
        return s.substring(start,end+1);
    }
    public int center(String s,int L,int R){
        while(L>=0 && R<=s.length()-1 && s.charAt(L) ==s.charAt(R)){
            L--;
            R++;
        }
        return R-L-1;
    }
}
