
/**
  04/14/2019
*/
public class Solution{
  public String longestPalindrome(String s){
    if (s == null || s.length() == 0) {
      //基于中心点枚举的方法，时间复杂度为O(n^2)
      return "";
    }
    int start = 0, len =0, longest=0;
    for (int i = 0; i<s.length() ;i++ ) {
      //以一个点为中心点，向两边查找对称的最长子串个数
      len = findLongestPalindromeFrom(s,i,i);
      if (len > longest) {
        longest = len;
        start = i-len/2 ;//起始位置为中心点减一半的对称长度
      }

      //以两个点的为中心，向两边查找对称的最长子串个数
      len = findLongestPalindromeFrom(s,i,i+1);
      if (len > longest) {
        longest = len ;
        start = i-len/2+1;
      }
    }
    return s.substring(start, start + longest);
  }
  private int findLongestPalindromeFrom(String s, int left, int right) {
        int len = 0;
        //向两边寻找对称的最长子串个数
        while (left >= 0 && right < s.length()) {
            if (s.charAt(left) != s.charAt(right)) {
                break;
            }
            if (left == right) {    //左右位置相同时，长度只加1，其他加2
                len += 1;
            } else {
                len += 2;
            }
            left--;
            right++;
        }
        return len;
    }
}
