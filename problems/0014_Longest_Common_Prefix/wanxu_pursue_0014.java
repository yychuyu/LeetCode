/**
 * Author: Json Wan
 * Created at: 2019/2/23 22:37
 * Description:
 * Write a function to find the longest common prefix string amongst an array of strings.
 If there is no common prefix, return an empty string "".
 Example 1:
 Input: ["flower","flow","flight"]
 Output: "fl"
 Example 2:
 Input: ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
 Note:
 All given inputs are in lowercase letters a-z.
 思路：遍历一次，每次比较相邻的两个串，得出公共前缀，再用公共前缀去跟下一个串比较，直至结束或者公共前缀为空为止
 **/
public class wanxu_pursue_0014 {

    //思路其实差不多，只是调用了库函数
    public String bestLongestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }

        String prefix = strs[0];

        for (int i = 1; i < strs.length; ++i) {
            while (!strs[i].startsWith(prefix)) {
                prefix = prefix.substring(0, prefix.length() - 1);

                if (prefix.isEmpty()) {
                    break;
                }
            }
        }

        return prefix;
    }

    //AC，0.8369
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0){
            return "";
        }
        String commonPrefix=strs[0];
        for(int i=1;i<strs.length;i++){
            commonPrefix=commonPrefix(commonPrefix,strs[i]);
            if("".equals(commonPrefix)){
                break;
            }
        }
        return commonPrefix;
    }

    private String commonPrefix(String str1,String str2){
        int l1=str1.length();
        int l2=str2.length();
        l1=l1<l2?l1:l2;
        int i=0;
        for(i=0;i<l1;i++){
            if(str1.charAt(i)!=str2.charAt(i)){
                break;
            }
        }
        return str1.substring(0,i);
    }

    public static void main(String[] args) {
        wanxu_pursue_0014 instance=new wanxu_pursue_0014();
        System.out.println("fl".equals(instance.longestCommonPrefix(new String[]{"flower","flow","flight"})));
        System.out.println("".equals(instance.longestCommonPrefix(new String[]{"dog","racecar","car"})));
    }
}
