/*
 * Longest Substring Without Repeating Characters.java
 *
 * April 13,2019 
 *
 * Author:lkk789@aliyun.com
 *
 */
 
 /*
 
Given a string, find the length of the longest substring without repeating characters.

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


 */
 


public class Solution {
	
	public int lengthOfLongestSubstring(String s) {
		if(s.length() == 0) {
			return 0;
		}
		int result = 1;
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 1; j < s.length(); j++) {
				//判断[i, j]区间内是否有重复元素
				boolean flag = false;
				for(int k = i; k < j; k++) {
					if(s.charAt(k) == s.charAt(j)) {
						flag = true;
						break;
					}
				}
				if(!flag) {
					result = Math.max(result, j - i + 1);
				}else {
					break;
				}
			}
		}
		return result;
	}
}



 