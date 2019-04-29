#
class Solution {
    public String longestPalindrome(String s) {
        boolean[][] flag = new boolean[s.length()][s.length()];
        int begin = 0;
        int end = 0;
        int maxlen = 0;

        for (int i = s.length(); i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (s.charAt(i)==s.charAt(j) && (j-i <= 2 || flag[i+1][j-1])){
                    flag[i][j] = true;
                    if (maxlen < j-i+1){
                        maxlen = j-i+1;
                        begin = i;
                        end = j;
                    }
                }
            }
        }


        return s.substring(begin,end+1);

    }
}
this file is added by shyshy
