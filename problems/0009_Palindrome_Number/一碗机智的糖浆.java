class Solution {
    public boolean isPalindrome(int x) {
        //所有的负数都不是回文数
        //末尾是0的数也不是（除0外）
        if( x<0 || x%10==0 && x!=0 ){
            return false;
        }
        //取x的后半段值于前半段比较是否相同
        //当后半段值大于前半段值时就到了数的中间位置
        int revertedNumber=0;
        while(x>revertedNumber){
            //每次后半段的数都要revertedNumber*10+x%10的值
            revertedNumber = revertedNumber*10 + x%10;
            //每次x都要除以10
            x /= 10;
        }
        //判断后半段后前半段
        //若是基数时去除中间位置
        return x==revertedNumber || x==revertedNumber/10;
    }
}