## 题目描述

```text
Leetcode 91
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。
示例 1:
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:
输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
```
## 解题思路
```text
dp[i]表示前i个字符的解码方式。
那么考虑加进来的第i个字符，如果i个字符可以自己构成一个信息，也就第i个不等于0，那么dp[i] = dp[i-1],
如果i和i-1合在一起还能表示一个信息，那么这时，dp[i] = dp[i-2]
所以考虑上面的情况，我们可以分析得出，
当第i个字符不等于0的时候，最少dp[i] = dp[i-1],
如果i和i-1还能构成一个信息，也就是在11-19到21-26之间的时候，自然dp[i] = dp[i-1]+ dp[i-2].

```
## 代码实现
```java

public class Solution {
   public int numDecodings(String s) {
       if (s == null || s.length() == 0) {
           return 0;
       }
       int[] nums = new int[s.length() + 1];
       nums[0] = 1;
       nums[1] = s.charAt(0) != '0' ? 1 : 0;
       for (int i = 2; i <= s.length(); i++) {
           if(s.charAt(i-1) != '0') {
               nums[i] = nums[i-1];
           }
           int twoDigits = (s.charAt(i - 2) - '0') * 10 + s.charAt(i - 1) - '0';
           if (twoDigits >= 10 && twoDigits <= 26) {
               nums[i] += nums[i - 2] ;
           }
       }
       return nums[s.length()] ;
   }
}
```
