/**
 * Created by Json Wan on 2018/11/5.
 * 题目描述：
 * Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

 Note:
 The length of num is less than 10002 and will be ≥ k.
 The given num does not contain any leading zero.
 Example 1:

 Input: num = "1432219", k = 3
 Output: "1219"
 Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 Example 2:

 Input: num = "10200", k = 1
 Output: "200"
 Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 Example 3:

 Input: num = "10", k = 2
 Output: "0"
 Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 解题思路：首先，数字使用String来表示说明输入的数字可能很大，用int/long装不下了，因此必须要考虑算法的复杂度，parseInt之类的方法应该是用不了的，必须另外想其他的办法；
 优先保证前面的数字最小，第一个数字为min(num.substring(0,k))，根据最小值的下标选出最小值，并对其前面的字符进行去除，k相应变化，依次往后去除直到k为0为止；需要注意特殊情况，如果走到最后也没有把k消耗完，则直接去除最后k位，再者就是对首位0的处理了。
 */
public class wanxu_pursue_0402 {

    /**
     * 通过，34ms，22.61%
     * @param num
     * @param k
     * @return
     */
    public String removeKdigits(String num, int k) {
        if(num.length()==k){
            return "0";
        }else{
            StringBuilder result=new StringBuilder();
            int start=0;
            int minIndex=start;
            char minCh=num.charAt(start);
            while(k>0){
                for(int i=start;i<=start+k&&i<num.length();++i){
                    char ch=num.charAt(i);
                    if(ch<minCh){
                        minCh=ch;
                        minIndex=i;
                    }
                }
                result.append(minCh);
                k-=minIndex-start;
                if(minIndex==start){
                    start+=1;
                }else {
                    start = minIndex+1;
                }
                if(start>=num.length()) {
                    break;
                }
                minIndex=start;
                minCh=num.charAt(start);
            }
            result.append(num.substring(start));
            String s=result.toString().substring(0,result.length()-k);
            start=0;
            while(start<s.length()&&s.charAt(start)=='0'){
                start++;
            }
            s=s.substring(start);
            if(s.length()==0){
                return "0";
            }else {
                return s;
            }
        }
    }

    /**
     * 另一种高效代码，好的代码总是很简洁。
     * @param num
     * @param k
     * @return
     */
    public String best2RemoveKdigits(String num, int k) {
        if (k == num.length()) return "0";
        char[] stack = new char[num.length()];
        int end = 0;
        for (char c : num.toCharArray()) {
            while (k > 0 && end > 0 && c < stack[end - 1]) {
                k--;
                end--;
            }
            stack[end] = c;
            end++;
        }

        // stack: increasing order
        while (k > 0) {
            end--;
            k--;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < end; i++) {
            char c = stack[i];
            if (sb.length() == 0 && c == '0') {
                continue;
            }
            sb.append(c);
        }

        return sb.length() == 0 ? "0" : sb.toString();
    }
    /**
     * 最高效的代码。
     * @param num
     * @param k
     * @return
     */
    public String bestRemoveKdigits(String num, int k)
    {
        int n = num.length();
        // 记录可以出移除的“零”的个数
        int zeros = 0;
        // 用于计算变量  zeros
        int tempOfZeros = k - 1;
        // 判断字符串中第 P个元素是否为“零”
        int indexP = 1;
        // 移除所有“零”后剩下的子串的起始位置
        int i = -1;
        while(tempOfZeros >= 0) {
            while(indexP < n && num.charAt(indexP) == '0') {
                zeros++;
                i = ++indexP;
            }
            if(tempOfZeros > 0) {
                indexP++;
            }
            tempOfZeros--;
        }
        // 移除不超过 k 个元素后剩下的元素全部为“零”
        if(indexP >= n) {
            return "0";
        }
        // 移除所有“零”后剩下的子串
        String sub = i > -1 ? num.substring(i) : num;
        // 移除所有“零”后 k 的值
        k -= i > -1 ? i-zeros : 0;
        // 问题转换为 removeKdigits(String sub, int k)
        return removeKdigitsFromSub(sub, k);
    }


    public String removeKdigitsFromSub(String sub, int k) {
        StringBuilder sb = new StringBuilder();
        // 移除 K 个字符后，字符串 sub 中未受影响的子串的起始位置
        int indexSub = 0;
        // 求解问题转 removeKdigits(String sub, int k)
        while(k > 0){
            // 要移除元素数量 = 剩下元素数量
            if (k == sub.length() - indexSub){ return sb.toString();}
            int temp = 1;
            int tempIndex = indexSub;
            while(temp <= k) {
                if(sub.charAt(indexSub + temp) < sub.charAt(indexSub)) {
                    k -= temp;
                    indexSub += temp;
                    break;
                }
                temp++;
            }
            if (tempIndex == indexSub) {
                sb.append(sub.charAt(indexSub++));
            }
        }
        return sb.toString() + sub.substring(indexSub);
    }

    public static void main(String[] args) {
        System.out.println(new wanxu_pursue_0402().removeKdigits("112",1));
        System.out.println(new wanxu_pursue_0402().removeKdigits("1432219",3));
        System.out.println(new wanxu_pursue_0402().removeKdigits("10200",1));
        System.out.println(new wanxu_pursue_0402().removeKdigits("10",2));
        System.out.println(new wanxu_pursue_0402().removeKdigits("10",1));
    }
}
