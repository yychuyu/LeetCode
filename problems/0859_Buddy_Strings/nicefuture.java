class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;  // 句子不等长直接判错
        
        if (A.equals(B)) {  // 句子完全相同时
            for (int i=0; i<A.length()/2; i++) {  // 存在完全相同的两个字符则可以互换还是相等
                if (A.indexOf(A.charAt(i)) != A.lastIndexOf(A.charAt(i)))
                    return true;
            }
            return false;
        } else {  // 句子不同时
            int first=-1, second=-1;
            for (int i=0; i<A.length(); i++) {  // 找出不同的两处位置
                if (A.charAt(i) != B.charAt(i)) {
                    if (first == -1) first = i;
                    else if (second == -1) second = i;
                    else return false;  // 不只两个字符不同直接判错
                }
            }
            if (A.charAt(first) == B.charAt(second) && A.charAt(second) == B.charAt(first))
                return true;  // 若四个字符交叉相等则满足条件
            else return false;
        }
    }
}
