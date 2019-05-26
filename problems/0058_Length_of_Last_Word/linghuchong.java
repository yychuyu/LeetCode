//把字符串转为数组，从后向前非特殊情况下找到第一个空格，并记下数目

class Solution {
    public int lengthOfLastWord(String s) {
      int length = 0;
      char[] chars = s.toCharArray();
      for (int i = s.length();i >= 0  ; i-- ) {
        if (length == 0) {
          if (chars[i] == ' ') {
            continue;
          }else {
            length++;
          }
        }else {
          if (chars[i] == ' ') {
            break;
          }else {
            length++;
          }
        }
      }
      return length;
}
