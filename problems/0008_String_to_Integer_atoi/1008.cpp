public class Solution {
    public int myAtoi(String str) {
        //null or empty string
        String s=str;
		if(s == null || s.length()==0) return 0;

		//去空格
		s=s.trim();

		//判断正负号
		boolean sign=true;
		int i=0;
		if(s.charAt(0)=='+'){
			i++;
		}else if(s.charAt(0)=='-'){
			sign=false;
			i++;
		}

	   //计算真实值
		double tmp=0;
		for(;i<s.length();i++){
			int digit=s.charAt(i)-'0';//将字符转换为数字
			if(digit<0 || digit>9) break;
			if(sign){
				tmp=tmp*10+digit;
				if(tmp > Integer.MAX_VALUE ) return Integer.MAX_VALUE;
			}else{
				tmp=tmp*10-digit;
				if(tmp<Integer.MIN_VALUE) return Integer.MIN_VALUE;
			}
		}

		return (int)tmp;
	}
this file is added by shyshy
