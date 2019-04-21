class Solution {
    public int reverse(int x) {
        int result = 0;
        int temp = x;
        while(temp!=0){
            
            if(result < Integer.MIN_VALUE/10 || result > Integer.MAX_VALUE/10)
                return 0;// 在越界前判断
            
            result *= 10;
            
            if((x < 0 && result < Integer.MIN_VALUE - temp%10) || (x > 0 && result > Integer.MAX_VALUE - temp%10))
                return 0;// 在越界前判断
            
            result += temp%10;
            temp /= 10;
        }
        
        return result;
    }
}