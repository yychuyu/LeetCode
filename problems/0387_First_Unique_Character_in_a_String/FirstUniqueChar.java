/**
 * * @ClassName Palindrome
 * * @Description
 * *  给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * * 使用hash表统计单词出现的频率
 * * @Author luoquan
 * * 微信 luo_quan1982
 * * @Email luo.quan@aliyun.com
 * * @Date 2018/11/7 8:45
 **/
public class FirstUniqueChar {
    public int firstUniqChar(String s) {
        int[] frequence = new int[26];

        for(int i = 0; i < s.length(); i++){
            frequence[s.charAt(i)-'a']++;
        }

        for(int i = 0; i < s.length(); i++){
            if(1 == frequence[s.charAt(i)-'a'])
                return i;
        }

        return -1;

    }
}