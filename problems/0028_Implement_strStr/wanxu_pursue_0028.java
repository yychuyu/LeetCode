/**
 * Author: Json Wan
 * Created at: 2019/3/27 2:18
 * Description:
 * 28. Implement strStr()
 Easy
 Implement strStr().
 Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 Example 1:
 Input: haystack = "hello", needle = "ll"
 Output: 2
 Example 2:
 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 Clarification:
 What should we return when needle is an empty string? This is a great question to ask during an interview.
 For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 思路：
 1.最简单的做法就是朴素匹配了，复杂的做法应该是kmp；
 **/
public class wanxu_pursue_0028 {

    //AC,1.00,呵呵
    public int strStr(String haystack, String needle) {
        if("".equals(needle)){
            return 0;
        }
        int l=haystack.length();
        int m=needle.length();
        if(l<m){
            return -1;
        }
        for(int i=0;i<l-m+1;i++){
            boolean flag=true;
            for(int j=0;j<m;j++){
                if(haystack.charAt(i+j)!=needle.charAt(j)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        wanxu_pursue_0028 instance=new wanxu_pursue_0028();
        System.out.println(instance.strStr("hello","ll")==2);
        System.out.println(instance.strStr("aaaaa","bba")==-1);
    }
}
