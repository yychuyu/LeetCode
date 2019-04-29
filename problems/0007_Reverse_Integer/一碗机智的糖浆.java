class Solution {
    public int reverse(int x) {
        //有符号位数值范围为 [?231,  231 ? 1]
        //一次构建反转整数的一位数字。在这样做的时候，我们可以预先检查向原整数附加另一位数字是否会导致溢出。
        int rev = 0;
        while (x != 0) {
            //取出x的末尾数字256，6
            int pop = x % 10;
            //x/10，25
            x /= 10;
            //判断新数是否大于Integer.MAX_VALUE/10，大于了就不乘以10了，以及其个位数字最大值个位7和最小值8间的差距
            if (rev > Integer.MAX_VALUE/10 || (rev == Integer.MAX_VALUE / 10 && pop > 7)) return 0;
            if (rev < Integer.MIN_VALUE/10 || (rev == Integer.MIN_VALUE / 10 && pop < -8)) return 0;
            //新数扩大10倍，再加个位
            rev = rev * 10 + pop;
        }
        return rev;
    }
}