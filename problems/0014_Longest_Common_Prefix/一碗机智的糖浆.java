class Solution {
    //万一是oflower flow呢？
    //这个函数主要是找公共前缀所以可以一直减去末尾的字符！！！
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String prefix = strs[0];
        for (int i = 1; i < strs.length; i++){
            //循环套循环
            //str1.indexOf(str2)只要str1中不包含str2就返回-1,只要包含了就返回它的索引
            //这里返回0就是说str2完全和str1最前面的几个单词一致
            while (strs[i].indexOf(prefix) != 0) {
                //每回去掉str2的一个末尾字符，寻找和str1头部完全一致的字符串
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) return "";
            } 
        }
        return prefix;   
    }
}