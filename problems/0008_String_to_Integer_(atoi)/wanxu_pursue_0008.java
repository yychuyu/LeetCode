/**
 * Created by Json Wan on 2019/1/5.
 * Description:
 * Implement atoi which converts a string to an integer.
 The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 If no valid conversion could be performed, a zero value is returned.
 Note:
 Only the space character ' ' is considered as whitespace character.
 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [?231,  231 ? 1]. If the numerical value is out of the range of representable values, INT_MAX (231 ? 1) or INT_MIN (?231) is returned.
 Example 1:
 Input: "42"
 Output: 42
 Example 2:
 Input: "   -42"
 Output: -42
 Explanation: The first non-whitespace character is '-', which is the minus sign.
 Then take as many numerical digits as possible, which gets 42.
 Example 3:
 Input: "4193 with words"
 Output: 4193
 Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
 Example 4:
 Input: "words and 987"
 Output: 0
 Explanation: The first non-whitespace character is 'w', which is not a numerical
 digit or a +/- sign. Therefore no valid conversion could be performed.
 Example 5:
 Input: "-91283472332"
 Output: -2147483648
 Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
 Thefore INT_MIN (?231) is returned.
 ˼·�����߱߿������Ÿ��ſո񵥶��жϣ�ע�����¼��㣺
 1.������Ҫ���ǣ�
 2.���ų����ڷ��Ż����ֺ��涼����Ч�ģ�
 3.���֡�����֮��Ҳ�ǲ����пո�ģ��ո�ֻ�ܳ�����һ��ʼ��
 4.ע��Խ����жϣ��Һû���long���а��ݣ����Ҫ��ȡlongӦ����ô���أ�
 */
public class wanxu_pursue_0008 {

    public int myAtoi(String str) {
        int l=str.length();
        int i=0;
        byte hasSign=0;
        boolean hasNum=false;
        long num=0;
        while(i<l){
            char ch=str.charAt(i);
            i++;
            if(ch==' '){
                if(hasNum){
                    break;
                }
                continue;
            }else if(ch=='-'){
                if(hasSign!=0||hasNum){
                    break;
                }else{
                    hasSign=-1;
                }
                hasNum=true;
            }else if(ch=='+'){
                if(hasSign!=0||hasNum){
                    break;
                }else{
                    hasSign=1;
                }
                hasNum=true;
            }else if(ch>='0' && ch<='9'){
                hasNum=true;
                num=num*10+(ch-'0');
                if(num>Integer.MAX_VALUE)
                    break;
            }else{
                break;
            }
        }
        if(num==(int)num){
            if(hasSign==-1)
                return -(int)num;
            else
                return (int)num;
        }else{
            if(hasSign==-1)
                return Integer.MIN_VALUE;
            else
                return Integer.MAX_VALUE;
        }
    }

    public static void main(String[] args) {
        System.out.println(new wanxu_pursue_0008().myAtoi("+0 123"));
        System.out.println(new wanxu_pursue_0008().myAtoi("+42"));
        System.out.println(new wanxu_pursue_0008().myAtoi("42"));
        System.out.println(new wanxu_pursue_0008().myAtoi("  -42"));
        System.out.println(new wanxu_pursue_0008().myAtoi("4193 with words"));
        System.out.println(new wanxu_pursue_0008().myAtoi("words and 987"));
        System.out.println(new wanxu_pursue_0008().myAtoi("-91283472332"));
        System.out.println("====================֤��һ��i==(int)i���ֱȽ�����Խ���ǿ��׵�======================");
        for(long i=0;i<Long.MAX_VALUE;i++){
            if(i>Integer.MAX_VALUE && i==(int)i){
                System.out.println(i);
            }
        }
        System.out.println("��ʵ����֤��--��");
    }
}
