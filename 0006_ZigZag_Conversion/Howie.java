package six;

/**
 * Regular Expression Matching
 *
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 *
 *
 * @author: Howie Lee
 * @create: 2018-12-16 12:52
 */
public class Solution {

    public static boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[s.length()][p.length()] = true;
        for (int i = s.length(); i >= 0; i--){
            for (int j = p.length() - 1; j >= 0; j--){
                boolean first_match = (i < s.length() &&
                        (p.charAt(j) == s.charAt(i) ||
                                p.charAt(j) == '.'));
                if (j + 1 < p.length() && p.charAt(j+1) == '*'){
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }

    public static void main(String[] args) {
        boolean res = isMatch("mississippi", "mis*is*p*.");
        System.out.println(res);
    }
}
