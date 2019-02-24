public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        for (int j = 0; j < strs[0].length(); ++j) {
            for (int i = 0; i < strs.length - 1; ++i) {
                if (j >= strs[i].length() || j >= strs[i + 1].length() || strs[i].charAt(j) != strs[i + 1].charAt(j)) {
                    return strs[i].substring(0, j);   
                }
            }
        }
        return strs[0];
    }
}
