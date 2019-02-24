package five;

/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 *
 * @author: Howie Lee
 * @create: 2018-12-09 15:47
 */
public class LongestPalindromicSubstring {

    public static String longestPalindrome(String s) {

        //return null when the string is null or empty
        if (s == null || s.length() == 0) {
            return null;
        }
        //return self when the string's length is 1
        if (s.length() == 1) {
            return s;
        }
        //The core is to find the center value
        String longestSubStr = s.substring(0, 1);
        for (int i = 0; i < s.length(); i++) {
            // case 1: like "aba"
            String tmp = handleString(s, i, i);
            if (tmp.length() > longestSubStr.length()) {
                longestSubStr = tmp;
            }

            // case 2: like "abba"
            tmp = handleString(s, i, i + 1);
            if (tmp.length() > longestSubStr.length()) {
                longestSubStr = tmp;
            }
        }
        return longestSubStr;
    }

    //Determine whether palindrome number
    public static String handleString(String s, int begin, int end) {
        //When the value of the begin position and the end position is equal
        while (begin >= 0 && end <= s.length() - 1 && s.charAt(begin) == s.charAt(end)) {
            begin--;
            end++;
        }
        return s.substring(begin + 1, end);
    }

    public static void main(String[] args) {
        String sub = longestPalindrome("");
        System.out.println(sub);
    }
}
