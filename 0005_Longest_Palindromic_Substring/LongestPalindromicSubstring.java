/**
 * Created by zhoudl on 2018/10/3.
 */
public class LongestPalindromicSubstring {
    /*
    Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

    Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
    Example 2:

    Input: "cbbd"
    Output: "bb"

    词汇： palindromic 回文
    翻译：求解回文字符串，所谓回文字符串，就是正读和反读都一样的字符串
    */

    /**
     * 动态规划算法
     *
     * @param s
     * @return
     */
    public static String longestPalindrome(String s) {
        if (s == null || s.length() < 2) {
            return s;
        }

        int maxLength = 0;
        String longest = null;

        int length = s.length();
        boolean[][] table = new boolean[length][length];

        // 单个字符都是回文
        for (int i = 0; i < length; i++) {
            table[i][i] = true;
            longest = s.substring(i, i + 1);
            maxLength = 1;
        }

        // 判断两个字符是否是回文
        for (int i = 0; i < length - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                table[i][i + 1] = true;
                longest = s.substring(i, i + 2);
                maxLength = 2;
            }
        }


        // 求长度大于2的子串是否是回文串
        for (int len = 3; len <= length; len++) {
            for (int i = 0, j; (j = i + len - 1) <= length - 1; i++) {
                if (s.charAt(i) == s.charAt(j)) {
                    table[i][j] = table[i + 1][j - 1];
                    if (table[i][j] && maxLength < len) {
                        longest = s.substring(i, j + 1);
                        maxLength = len;
                    }
                } else {
                    table[i][j] = false;
                }
            }
        }
        return longest;
    }

    /**
     * 中心扩展算法
     * 回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n - 12n−1 个这样的中心。
     * 时间复杂度：由于围绕中心来扩展回文会耗去 O(n)O(n) 的时间O(n^2)
     * 空间复杂度：O(1)
     *
     * @param s
     * @return
     */
    public static String longestPalindrome2(String s) {
        if (s == null || s.length() < 1) {
            return "";
        }
        int start = 0, end = 0;
        // 当回文串的长度为奇数时
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = Math.max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(start, end + 1);
    }

    private static int expandAroundCenter(String s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
            L--;
            R++;
        }
        return R - L - 1;
    }

    public static void main(String[] args) {
        String str = "222020221";
        System.out.println(longestPalindrome(str));
    }
}
