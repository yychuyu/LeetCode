/**
 * Author: Json Wan
 * Created at: 2019/1/12 2:16
 * Description:
 * 9. Palindrome Number
 Easy
 Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

 Example 1:
 Input: 121
 Output: true

 Example 2:
 Input: -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

 Example 3:
 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 Follow up:
 Coud you solve it without converting the integer to a string?
 思路：分离首位末位逐一比较即可
 注意：
 （1）当你处理一个int类型的数的时候，如果处理过程中出现了比它本身要大的数字，一定要用范围更大的类型来包容；
（2）在进行整除/取余运算时，一定要注意数字中间的0的影响。
 **/
public class wanxu_pursue_0009 {

    //利用回文数特点不断分离末位来构造一个新的数字，并将其与x的左半边数字比较，直至二者相等为止，最后考虑原数字是奇偶数长度的情况，妙哉！
    public boolean bestIsPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber/10;
    }
    //AC,20.04%
    public boolean isPalindrome(int x) {
        if(x<0)
            return false;
        int n=1;
        long m=10;
        while(x/m!=0){
            m*=10;
            n+=1;
        }
        m=m/10;
        int firstN=0;
        int lastN=0;
        while(m!=0 && x!=0 && firstN==lastN){
            firstN=(int)(x/m);
            lastN=x%10;
            if(firstN!=lastN)
                return false;
            x=(int)(x%m)/10;
            //这里由m控制很重要，才不会忽略掉中间的0，如果靠x自身长度控制则容易忽略掉中间的0
            m=m/100;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(new wanxu_pursue_0009().isPalindrome(10002321));
        System.out.println(new wanxu_pursue_0009().isPalindrome(100023201));
        System.out.println(new wanxu_pursue_0009().isPalindrome(10000001));
        System.out.println(new wanxu_pursue_0009().isPalindrome(100000001));
        System.out.println(new wanxu_pursue_0009().isPalindrome(1000000001));
        System.out.println(new wanxu_pursue_0009().isPalindrome(121));
        System.out.println(new wanxu_pursue_0009().isPalindrome(-121));
        System.out.println(new wanxu_pursue_0009().isPalindrome(10));
        System.out.println(new wanxu_pursue_0009().isPalindrome(101));
        System.out.println(new wanxu_pursue_0009().isPalindrome(1010));
        System.out.println(new wanxu_pursue_0009().isPalindrome(1000000001));
    }
}
