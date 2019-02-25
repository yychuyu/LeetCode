/**
 * Created by Json Wan on 2019/1/14.
 * Description:
 * 10. Regular Expression Matching
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * <p>
 * Note:
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 * Example 1:
 * <p>
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * Example 2:
 * <p>
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * Example 3:
 * <p>
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * Example 4:
 * <p>
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 * Example 5:
 * <p>
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * ˼·��ֻ��Ҫƥ��.��*���õݹ�Ӧ���ǱȽϺ�д��
 */
public class wanxu_pursue_0010 {

    enum Result {
        TRUE, FALSE
    }

    Result[][] f;

    /**
     * ��̬�滮�ⷨ��
     ״̬��ʾ��f[i][j]��ʾp��j��ʼ����β���Ƿ���ƥ��s��i��ʼ����β
     ״̬ת�ƣ�
        1. ���p[j+1]����ͨ���'*'����f[i][j]���棬���ҽ���s[i]���Ժ�p[j]ƥ�䣬��f[i+1][j+1]���棻
        2. ���p[j+1]��ͨ���'*'������������ֻҪ��һ�����㣬f[i][j]�����棻
            ��1��f[i][j+2]���棻
            ��2��s[i]���Ժ�p[j]ƥ�䣬��f[i+1][j]���棻
     ��1������µ�״̬ת�ƺܺ���⣬�ǵ�2������µ�״̬ת����ô����أ�
        ��ֱ�۵�ת�Ʒ�ʽ�������ģ�ö��ͨ���'*'����ƥ����ٸ�p[j]��ֻҪ��һ���������ƥ�䣬��f[i][j]�����棻
        �������Ļ������Ƿ��֣�f[i][j]����ö��0��p[j]֮�⣬�����ö�ٲ�����������f[i+1][j]���ˣ���������ֻ���ж�
        f[i+1][j]�Ƿ�Ϊ�棬�Լ�s[i]�Ƿ���Ժ�p[j]ƥ�伴�ɡ�
     ʱ�临�Ӷȷ�����nn ��ʾs�ĳ��ȣ�mm ��ʾp�ĳ��ȣ��ܹ� nmnm ��״̬��״̬ת�Ƹ��Ӷ� O(1)O(1)��������ʱ�临�Ӷ��� O(nm)O(nm).
     */
    public boolean bestIsMatch(String text, String pattern) {
        f = new Result[text.length() + 1][pattern.length() + 1];
        return dp(0, 0, text, pattern);
    }

    public boolean dp(int i, int j, String text, String pattern) {
        if (f[i][j] != null) {
            // �ݹ���ֹ����
            return f[i][j] == Result.TRUE;
        }
        boolean ans;
        if (j == pattern.length()) {
            ans = i == text.length();
        } else {
            boolean first_match = (i < text.length() &&
                    (pattern.charAt(j) == text.charAt(i) ||
                            pattern.charAt(j) == '.'));

            if (j + 1 < pattern.length() && pattern.charAt(j + 1) == '*') {
                ans = (dp(i, j + 2, text, pattern) ||
                        first_match && dp(i + 1, j, text, pattern));
            } else {
                ans = first_match && dp(i + 1, j + 1, text, pattern);
            }
        }
        f[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }

    /**
     * �ݹ�汾
     * AC��0.92%��(|-__-)����Ҫ�ú�ѧϰһ����������
     *
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch(String s, String p) {
        int sLength = s.length();
        if (sLength == 0) {
            if ("".equals(p))
                return true;
            int i = p.length() - 1;
            while (i > 0 && p.charAt(i) == '*')
                i = i - 2;
            if (i < 0)
                return true;
            return false;
        } else if (sLength == 1) {
            if (p.equals(s) || ".".equals(p) || ".*".equals(p)) {
                return true;
            }
        }
        int pLength = p.length();
        if (pLength == 0) {
            if (sLength == 0)
                return true;
            return false;
        } else if (pLength == 1) {
            if (".".equals(p)) {
                if (sLength == 1)
                    return true;
                return false;
            } else if ("*".equals(p)) {
                if (sLength == 0)
                    return true;
                return false;
            } else {
                return p.equals(s);
            }
        } else if (pLength == 2) {
            if (".*".equals(p)) {
                return true;
            } else if (p.charAt(1) == '*') {
                Character sCh = p.charAt(0);
                for (Character ch : s.toCharArray()) {
                    if (!ch.equals(sCh)) {
                        return false;
                    }
                }
                return true;
            } else if ("..".equals(p)) {
                return sLength == 2;
            } else if (p.charAt(1) == '.') {
                return sLength == 2 && p.charAt(0) == s.charAt(0);
            } else if (p.charAt(0) == '.') {
                return sLength == 2 && p.charAt(1) == s.charAt(1);
            } else {
                return s.equals(p);
            }
        } else {
            if ('*' != p.charAt(1)) {
                return isMatch(s.substring(0, 1), p.substring(0, 1)) && isMatch(s.substring(1), p.substring(1));
            } else {
                if ('.' == p.charAt(0)) {
                    for (int i = sLength; i >= 0; i--) {
                        if (isMatch(s.substring(i), p.substring(2))) {
                            return true;
                        }
                    }
                    return false;
                } else {
                    for (int i = sLength; i >= 0; i--) {
                        String leftS = s.substring(0, i);
                        String rightS = s.substring(i);
                        String leftP = p.substring(0, 2);
                        String rightP = p.substring(2);
                        boolean subResult1 = isMatch(rightS, rightP);
                        boolean subResult2 = isMatch(leftS, leftP);
//                        System.out.println(leftP+"  "+leftS+"==>"+subResult2);
//                        System.out.println(rightP+"  "+rightS+"==>"+subResult1);
                        if (subResult1 && subResult2) {
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
    }

    public static void main(String[] args) {
        System.out.println(new wanxu_pursue_0010().isMatch("c", ".*b*b*"));
        System.out.println(new wanxu_pursue_0010().isMatch("abcaaaaaaabaabcabac", ".*ab.a.*a*a*.*b*b*"));
        System.out.println(new wanxu_pursue_0010().isMatch("a", "a*c*"));
        System.out.println(new wanxu_pursue_0010().isMatch("abbabaaaaaaacaa", "a*.*b.a.*c*b*a*c*"));
        System.out.println(new wanxu_pursue_0010().isMatch("a", ".*.a*"));
        System.out.println(!new wanxu_pursue_0010().isMatch("a", ".*..a*"));
        System.out.println(!new wanxu_pursue_0010().isMatch("aa", "a"));
        System.out.println(new wanxu_pursue_0010().isMatch("aa", "a*"));
        System.out.println(new wanxu_pursue_0010().isMatch("ab", ".*"));
        System.out.println(new wanxu_pursue_0010().isMatch("aab", "c*a*b"));
        System.out.println(!new wanxu_pursue_0010().isMatch("mississippi", "mis*is*p*."));
    }
}
