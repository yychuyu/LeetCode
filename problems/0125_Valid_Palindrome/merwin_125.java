package _125_huiwen;

/**
 * 注意两点：
 * 1.toLowerCase 不改变原有的字符串
 * 2.排除非数字字母时，i和j要尽量平行前进。
 */
class Solution {
    public boolean isPalindrome(String s) {
        s=s.toLowerCase();
        int i=0,j=s.length()-1;
        char[] c = s.toCharArray();
        while(i<j){
            if( c[i]<'0' || (c[i]>'9'&&c[i]<'a') || c[i]>'z'){
                i++;
                continue;
            }
            else if(c[j]<'0' || (c[j]>'9'&&c[j]<'a') || c[j]>'z'){
                j--;
                continue;
            }
            if(c[i]!=c[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isPalindrome("A man, a plan, a canal: Panama"));
    }
}
