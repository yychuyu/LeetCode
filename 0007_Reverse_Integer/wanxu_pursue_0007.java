/**
 * Author: Json Wan
 * Created at: 2018/12/27 0:38
 * Description:
 **/
public class wanxu_pursue_0007 {

    /**
     * AC, 0.2514
     * @param x
     * @return
     */
    public int reverse(int x) {
        if(x==0||x>Integer.MAX_VALUE||x<Integer.MIN_VALUE)
            return 0;
        int sign=1;
        if(x<0){
            sign=-1;
            x=-x;
        }
        long result=0;
        while(x>0){
            result=result*10+(x%10);
            x=x/10;
        }
        result=result*sign;
        if(result>Integer.MAX_VALUE||result<Integer.MIN_VALUE)
            return 0;
        return (int)result;
    }

    /**
     * 最优解，最简洁，负数对正数求余得到的是负数，正数对负数求余得到的是正数，负数对负数求余得到的是负数
     * @param x
     * @return
     */
    public int bestReverse(int x) {
        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return (int)res == res ? (int)res : 0;
    }

    public static void main(String[] args) {
        System.out.println(new wanxu_pursue_0007().reverse(15));
        System.out.println(new wanxu_pursue_0007().reverse(-15));
        System.out.println(new wanxu_pursue_0007().reverse(-1500));
        System.out.println(new wanxu_pursue_0007().reverse(-10500));
        System.out.println(new wanxu_pursue_0007().reverse(1534236469));
        System.out.println(new wanxu_pursue_0007().reverse(0));
        System.out.println(new wanxu_pursue_0007().bestReverse(-1050));
        System.out.println(10%-3);
        System.out.println(-10%-3);
        System.out.println(-10%3);
        System.out.println(11%-3);
        System.out.println(-11%-3);
        System.out.println(-11%3);
    }
}
