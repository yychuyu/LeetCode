/**
 * Created by Json Wan on 2018/11/5.
 * ��Ŀ������
 * Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

 Note:
 The length of num is less than 10002 and will be �� k.
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
 ����˼·�����ȣ�����ʹ��String����ʾ˵����������ֿ��ܴܺ���int/longװ�����ˣ���˱���Ҫ�����㷨�ĸ��Ӷȣ�parseInt֮��ķ���Ӧ�����ò��˵ģ����������������İ취��
 ���ȱ�֤ǰ���������С����һ������Ϊmin(num.substring(0,k))��������Сֵ���±�ѡ����Сֵ��������ǰ����ַ�����ȥ����k��Ӧ�仯����������ȥ��ֱ��kΪ0Ϊֹ����Ҫע���������������ߵ����Ҳû�а�k�����꣬��ֱ��ȥ�����kλ�����߾��Ƕ���λ0�Ĵ����ˡ�
 */
public class wanxu_pursue_0402 {

    /**
     * ͨ����34ms��22.61%
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
     * ��һ�ָ�Ч���룬�õĴ������Ǻܼ�ࡣ
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
     * ���Ч�Ĵ��롣
     * @param num
     * @param k
     * @return
     */
    public String bestRemoveKdigits(String num, int k)
    {
        int n = num.length();
        // ��¼���Գ��Ƴ��ġ��㡱�ĸ���
        int zeros = 0;
        // ���ڼ������  zeros
        int tempOfZeros = k - 1;
        // �ж��ַ����е� P��Ԫ���Ƿ�Ϊ���㡱
        int indexP = 1;
        // �Ƴ����С��㡱��ʣ�µ��Ӵ�����ʼλ��
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
        // �Ƴ������� k ��Ԫ�غ�ʣ�µ�Ԫ��ȫ��Ϊ���㡱
        if(indexP >= n) {
            return "0";
        }
        // �Ƴ����С��㡱��ʣ�µ��Ӵ�
        String sub = i > -1 ? num.substring(i) : num;
        // �Ƴ����С��㡱�� k ��ֵ
        k -= i > -1 ? i-zeros : 0;
        // ����ת��Ϊ removeKdigits(String sub, int k)
        return removeKdigitsFromSub(sub, k);
    }


    public String removeKdigitsFromSub(String sub, int k) {
        StringBuilder sb = new StringBuilder();
        // �Ƴ� K ���ַ����ַ��� sub ��δ��Ӱ����Ӵ�����ʼλ��
        int indexSub = 0;
        // �������ת removeKdigits(String sub, int k)
        while(k > 0){
            // Ҫ�Ƴ�Ԫ������ = ʣ��Ԫ������
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
