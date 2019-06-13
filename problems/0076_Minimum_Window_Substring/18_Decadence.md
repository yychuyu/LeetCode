## 题目描述

```text
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
```

## 解题思路
```text
大致思路是：
首先对T中出现的字符以及出现次数做统计，之后查找S中是否有对应字符，以及对应字符出现次数是否不小于T中出现次数。
1.遍历T，将T中字符出现次数存入数组ta[]；新建数组sa[]存储S中字符出现次数；
2.设置指针start和end，都指向S开始位置；
3.end向后遍历，若遇到的字符在ta[]中的值不为0（即T中存在的字符），则有两
种情况：一、sa[]中该字符值等于ta[]中该字符值，则说明该字符已经找够，不需要再找，
则忽略该字符，继续遍历；二、sa[]中该字符值小于ta[]中该字符值（sa[]中该字符值可能为0，即未出现过的字符），
则说明该字符还未找全，将sa[]中该字符值加1，count加1，继续遍历。若遇到的字符在ta[]中的值为0，忽略该字符，继续遍历；
4.当count值等于T的长度，则说明已经找到了T中所有元素，end暂停遍历；此时关注start，在此时的start处或者start向后一段内，
可能都是T中不存在的字符，但由于这些字符未计入count值，所以是否包含这些字符不影响判断条件；但是为了找到最小的Window，
需要start向后遍历，将T中不存在的字符都排除，找到T中存在的第一个字符位置，即找到了一个包含T的Window；
将此时的Window长度与minwin长度比较，若小于minwin长度，说明找到了更小的Window，更新minwin为当前找到的Window；
5.找到一个Window后end继续遍历。每当end后移一步，就考察start处字符，若start处字符次数大于T中该字符次数，
则start后移，若start处字符不存在T中，start也后移，直到找到包含T的最小Window，再进行记录。
6.直到end遍历到S的结尾位置，算法结束。
```

## 代码实现
```java
public class Min_Win_Sub {
    public String minWindow(String s, String t) {
        int[] ta = new int[128];
        int[] sa = new int[128];
        int min = Integer.MAX_VALUE;
        String minwin = "";
        for(int i = 0; i<t.length(); i++){
            ta[t.charAt(i)]++;
        }
        int count = 0; int end = 0; int start = 0;
        while(end < s.length()){
            if(ta[s.charAt(end)] != 0){
                if(sa[s.charAt(end)] < ta[s.charAt(end)]){
                    count++;
                }
                sa[s.charAt(end)]++;
            }
            if(count == t.length()){
                while(ta[s.charAt(start)] == 0 || sa[s.charAt(start)] > ta[s.charAt(start)]){
                    if(sa[s.charAt(start)] > ta[s.charAt(start)]){
                        sa[s.charAt(start)]--;
                    }
                    start++;
                }
                if(end-start+1 < min){
                    minwin = s.substring(start,end+1);
                    min = end-start+1;
                }
            }
            end++;
        }
        return minwin;
    }
    
}
```