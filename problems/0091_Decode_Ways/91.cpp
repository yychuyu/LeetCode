class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] =='0' ){
            return 0;
        }
        if(s.length() == 1 ){
            return 1;
        }
        int dp1 = 1;//相当于dp[i-2]
        int dp2 = 1;//相当于dp[i-1]
        int result = 0;
        for(int i = 1;i<s.length();i++){
            int i1 = (s[i - 1] - 48) * 10 + (s[i] - 48);
            //不能连续出现0
            if(i1 == 0){
                return 0;
            }
            if(i1 >=10 && i1 <=26 ){
                result = dp1;
            }
            if(s[i] != '0'){
                result += dp2;
            }
            dp1 = dp2;
            dp2 = result;
            result = 0;
        }
        return dp2;

        
    }
};