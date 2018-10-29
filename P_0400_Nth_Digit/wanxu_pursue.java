package P_0400_Nth_Digit;

/**
 * Created by Json Wan on 2018/10/29.
 * Description：
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

 Note:
 n is positive and will fit within the range of a 32-bit signed integer (n < 231).

 Example 1:

 Input:
 3

 Output:
 3
 Example 2:

 Input:
 11

 Output:
 0

 Explanation:
 The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 思路：找到n位数以内的数字总量的通项公式即可：
 S=9*10^(1-1)*1+9*10^(2-1)*2+9*10^(3-1)*3+……+9*10^(n-1)*n
 */
public class wanxu_pursue {
    /*
    解法通过，3ms
     */
    public int findNthDigit(int n) {
        //必须注意这里的long类型，int+int可能会产生long，必须考虑类型边界安全的问题
        long s=0;
        int num=0;
        while(s<n){
            num++;
            s+=9*Math.pow(10,num-1)*num;
        }
        s-=9*(long)(Math.pow(10,num-1))*num;
        //要找的数字位于某一个num位数中
        //过了num-1位数后，还差多少
        long res=n-s;
        int count=(int)(res/num);
        int lastRes=(int)(res%num);
        //要求的数字位于number中
        int number=(int)(Math.pow(10,num-1))+count;
        if(lastRes==0){
            number=number-1;
            String numStr=""+number;
            return Integer.parseInt(numStr.charAt(numStr.length()-1)+"");
        }else{
            String numStr=""+number;
            return Integer.parseInt(numStr.charAt(lastRes-1)+"");
        }
    }
    public static void main(String[] args) {
        //System.out.println("hello");
        wanxu_pursue testInstance=new wanxu_pursue();
        System.out.println(testInstance.findNthDigit(1000000000));
        for (int i = 1; i < 100; i++) {
            System.out.println(testInstance.findNthDigit(i));
        }
    }
}
