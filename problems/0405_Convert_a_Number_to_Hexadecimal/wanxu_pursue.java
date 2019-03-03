
/**
 * Created by Json Wan on 2018/10/29.
 * Description:
 * Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two��s complement method is used.

 Note:

 All letters in hexadecimal (a-f) must be in lowercase.
 The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
 The given number is guaranteed to fit within the range of a 32-bit signed integer.
 You must not use any method provided by the library which converts/formats the number to hex directly.
 Example 1:

 Input:
 26

 Output:
 "1a"
 Example 2:

 Input:
 -1

 Output:
 "ffffffff"
 ����˼·��
 ������ҪŪ�����two's complement�Ǹ�ɶ����ʵ���Ƕ����Ʋ��룬Java����long���ͣ��ɽ�����תΪ���������㼴�ɣ�
 */

public class wanxu_pursue {

    /*
    ��ͨ����60.14%λ�ã����Ŵ����Ѽ�¼
     */
    public String toHex(int num) {
        long n=num;
        if(num<0)
            n=num+(long)(Math.pow(2,32));
        else if(num==0)
            return "0";
        StringBuilder result=new StringBuilder();
        while(n>0){
            long res=n%16;
            if(res>9){
                char ch=(char)('a'+(res-10));
                result.append(ch);
            }else{
                result.append(res);
            }
            n=n/16;
        }
        result.reverse();
        return result.toString();
    }

    public String bestToHex(int num) {
        if(num==0)
            return "0";
        StringBuilder sb=new StringBuilder();
        long n=num;
        // System.out.println((int)n);
        if(num<0)
            n=(long)Math.pow(16,8)+n;

        while(n>0){
            // System.out.println(n);
            int ans=(int)(n%16);
            n/=16;
            if(ans>=10)
                sb.append((char)('a'-10+ans));
            else
                sb.append(ans);
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        System.out.println(new wanxu_pursue().toHex(-1));
        System.out.println(new wanxu_pursue().toHex(0));
        System.out.println(new wanxu_pursue().toHex(16));
        System.out.println(new wanxu_pursue().toHex(26));
    }
}
