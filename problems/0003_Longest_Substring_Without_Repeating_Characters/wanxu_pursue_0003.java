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
 ˼·��������ظ��Ӵ��������뵽����
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
     * �Լ��Ľⷨ�����˶����˼�룬������set.contains��һ������O(n)�ĸ��Ӷȣ�Ӧ�ÿ������Ż�
     * ռλ25.12%
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
            //�������
            //1.֮ǰ������ظ��Ӵ�ǡ�ó�����ĩβ
            if(lastUnit.index==i-1){
                //������ǰλ�Ƿ���ǰ�Ӵ����ַ����ظ������ظ��򳤶�+1
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
            //2.֮ǰ���Ӵ�û�г�����ĩβ
            else{
                //�Ƚϵ�ǰ�ַ����ɵ�ĩβ�Ӵ���lastUnit֮��Ĵ�С��ȡ���
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
     * ��ţ�ƵĽⷨ��λͼ��˼�룬�ַ����е�Ԫ�ؿ��������޷�Χ�ڵ����ֱ�ʾ��������
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
            //ȷ����ǰ�ַ�������λ�ã��Ḳ�ǵ���ǰһ��λ�ã������ڸ��ǵ�֮ǰ�Ƚ����¼��left��
            p[s.charAt(i)] = i;
            //��ǰ�ַ�ǰ�����γ���λ�õĲ�ֵ��������ظ��Ӵ����ȣ�
            //�ǵģ�left�����ʼ����λ�ò�����ǰ�ƣ��Ա�֤���������ڲ����������ظ����ַ�
            //leftά���������ҵ���һ���ظ��ַ�������Ǹ��ַ����±�
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
