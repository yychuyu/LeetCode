import java.util.HashSet;
import java.util.Set;

/**
 * Created by Json Wan on 2018/11/27.
 * Description:
 * Given a string, find the length of the longest substring without repeating characters.
 Example 1:
 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.

 Example 2:
 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.

 Example 3:
 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 思路：找最长不重复子串，首先想到动规
 */
public class wanxu_pursue_0003 {
    class Unit{
        int l;
        int index;

        public Unit(int l, int index) {
            this.l = l;
            this.index = index;
        }
    }

    /**
     * 自己的解法，用了动规的思想，但是在set.contains这一步还是O(n)的复杂度，应该可以再优化
     * 占位25.12%
     * @param s
     * @return
     */
    public int lengthOfLongestSubstring(String s) {
        int l=s.length();
        if(l<=1)return l;
        Unit[] matrix=new Unit[l];
        matrix[0]=new Unit(1,0);
        for(int i=1;i<l;i++){
            Unit lastUnit=matrix[i-1];
            //两种情况
            //1.之前的最长不重复子串恰好出现在末尾
            if(lastUnit.index==i-1){
                //看看当前位是否与前子串中字符有重复，无重复则长度+1
                int j=i-1;
                while(j>i-lastUnit.l-1){
                    if(s.charAt(i)==s.charAt(j))
                        break;
                    j--;
                }
                if(j==i-lastUnit.l-1){
                    matrix[i]=new Unit(lastUnit.l+1,i);
                }else if(j==i-lastUnit.l){
                    matrix[i]=new Unit(lastUnit.l,i);
                }
                else{
                    matrix[i]=new Unit(lastUnit.l,lastUnit.index);
                }
            }
            //2.之前的子串没有出现在末尾
            else{
                //比较当前字符构成的末尾子串与lastUnit之间的大小，取大的
                Set<Character> set=new HashSet<>();
                int j=i;
                while(!set.contains(s.charAt(j))){
                    set.add(s.charAt(j--));
                }
                int newL=set.size();
                if(lastUnit.l>newL){
                    matrix[i]=new Unit(lastUnit.l,lastUnit.index);
                }else{
                    matrix[i]=new Unit(newL,i);
                }
            }
        }
        return matrix[l-1].l;
    }

    /**
     * 最牛逼的解法：位图法思想，字符串中的元素可以用有限范围内的数字表示！！！！
     * @param s
     * @return
     */
    public int bestLengthOfLongestSubstring(String s) {
        int[] p = new int[256];
        for(int i = 0; i < 256; i++){
            p[i] = -1;
        }

        int res = 0, left = -1;
        for(int i = 0; i < s.length(); i++) {
            left = Math.max(left, p[s.charAt(i)]);
            //确定当前字符的最新位置，会覆盖掉其前一个位置，所以在覆盖掉之前先将其记录到left中
            p[s.charAt(i)] = i;
            //当前字符前后两次出现位置的差值就是最大不重复子串长度？
            //是的！left会把起始计算位置不断往前推，以保证计算区间内不会有其他重复的字符
            //left维护的是最右的那一对重复字符的左边那个字符的下标
            res = Math.max(res, i - left);
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(new wanxu_pursue_0003().lengthOfLongestSubstring("abcabcbb"));
        System.out.println(new wanxu_pursue_0003().lengthOfLongestSubstring("bbbb"));
        System.out.println(new wanxu_pursue_0003().lengthOfLongestSubstring("pwwkew"));
    }
}
