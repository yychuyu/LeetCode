class Solution {
    public int titleToNumber(String s) {
        if (s != null && s.length() > 0) {
            char[] chars = s.toCharArray();
            int len = chars.length;
            int sum = 0;
            for (int i = 0; i < len; i++) {
                sum += ((int) chars[i] - 64) * Math.pow(26, len - i - 1);
            }
            return sum;
        } else {
            return 0;
        }
    }
}