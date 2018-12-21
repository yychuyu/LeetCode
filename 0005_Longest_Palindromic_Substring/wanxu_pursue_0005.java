/**
 * Created by Json Wan on 2018/12/15.
 * Description:
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 Example 1:

 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:

 Input: "cbbd"
 Output: "bb"
 思路：寻找最长回文串，典型的动态规划题目
 f(i,j)为i到j的子串是否为回文串
 f(i,j)=1,j==i
 f(i,j)=(s[i]==s[j]),j==i+1
 当j>i+1:
 f(i,j)=1, f(i+1,j-1)=1 && s[i]==s[j]
 f(i,j)=0, other
 需要注意，遍历为矩阵赋值时应斜线遍历，因为可确定的初值表现出的形态为斜线，每一次迭代（i++,j++）
 */
public class wanxu_pursue_0005 {

    /**
     * AC,0.2624
     * @param s
     * @return
     */
    public String longestPalindrome(String s) {
        int l=s.length();
        if(l<=1)
            return s;
        int matrix[][]=new int[l][l];
        int maxLength=0;
        int maxI=0,maxJ=0;
        for(int startJ=0;startJ<l;startJ++){
            int i=0;
            int j=startJ;
            while(i<l && j<l){
                if(j==i){
                    matrix[i][j]=1;
                }else if(j==i+1){
                    if(s.charAt(i)==s.charAt(j)){
                        matrix[i][j]=1;
                    }else{
                        matrix[i][j]=0;
                    }
                }else{
                    if(matrix[i+1][j-1]==1&&s.charAt(i)==s.charAt(j)){
                        matrix[i][j]=1;
                    }else{
                        matrix[i][j]=0;
                    }
                }
                if(matrix[i][j]==1){
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        maxI=i;
                        maxJ=j;
                    }
                }
                i++;
                j++;
            }
        }
        return s.substring(maxI,maxJ+1);
    }


    /**
     * 最优解法
     */
    int len = 0, maxLength = 0, start = 0;
    public String bestLongestPalindrome(String s) {
        char[] arr = s.toCharArray();
        len = s.length();
        if (len <= 1)
            return s;
        for (int i = 0; i < len; i++) {
            i = helper(arr, i);
        }
        return s.substring(start, start + maxLength);
    }

    public int helper(char[] arr, int k) {
        int i = k - 1, j = k;
        while (j < len - 1 && arr[j] == arr[j + 1])
            j++;
        int nextCenter = j++;
        while (i >= 0 && j < len && arr[i] == arr[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > maxLength) {
            maxLength = j - i - 1;
            start = i + 1;
        }
        return nextCenter;
    }
    public static void main(String[] args) {
        System.out.println(new wanxu_pursue_0005().longestPalindrome(""));
        System.out.println(new wanxu_pursue_0005().longestPalindrome("a"));
        System.out.println(new wanxu_pursue_0005().longestPalindrome("babad"));
        System.out.println(new wanxu_pursue_0005().longestPalindrome("abbd"));
        System.out.println(new wanxu_pursue_0005().longestPalindrome("abcdefgabdfefadfsdalfksadjlfksadflsdjsdfaslfjsdlkf"));
    }
}
