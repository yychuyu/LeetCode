package leetcode_58;

/**
 *给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 如果不存在最后一个单词，请返回 0 。
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 示例:
 * 输入: "Hello World"
 * 输出: 5
 */
public class Solution {
    public int lengthOfLastWord(String s) {
        //去除首尾空格，然后总长度-找到最后空格的索引在减去1（字符串从0开始）即为单词长度
        return s.trim().length()-s.trim().lastIndexOf(' ')-1;
    }
}


