/**
 * Solution.java
 * top.actim.leetcode._3_Longest_Substring_Without_Repeating_Characters
 *
 * Function： TODO 
 *
 *   ver     date      		author
 * ──────────────────────────────────
 *   		 2019年4月8日 		a
 *
 * Copyright (c) 2019, TNT All Rights Reserved.
*/

package top.actim.leetcode._3_Longest_Substring_Without_Repeating_Characters;

import java.util.Iterator;
import java.util.LinkedHashSet;

public class MySolution {
	public static void main(String[] args) {
		Solution solution = new Solution();

		int res = solution.lengthOfLongestSubstring("abcabcbb");
		System.out.println(res);

		res = solution.lengthOfLongestSubstring("bbbbbb");
		System.out.println(res);

		res = solution.lengthOfLongestSubstring("pwwkew");
		System.out.println(res);

		res = solution.lengthOfLongestSubstring("abcdbcadf");
		System.out.println(res);

	}
}

class Solution {
	public int lengthOfLongestSubstring(String s) {
		// 用Hash鉴别重复 List保持顺序
		LinkedHashSet<Character> temp = new LinkedHashSet<Character>();
		// 将字符串转化为数组
		char[] charArr = s.toCharArray();
		// 结果
		int result = 0;

		for (char c : charArr) {

			// 记录长度并移除重复部分
			if (temp.contains(c)) {
				if (temp.size() > result)
					result = temp.size();
				for (Iterator<Character> iterator = temp.iterator(); iterator.hasNext();) {
					char ch = iterator.next();
					iterator.remove();
					if (ch == c) {
						break;
					}
				}
			}

			// 加入缓存区
			temp.add(c);

		}

		// 最后长度
		if (temp.size() > result)
			result = temp.size();

		return result;
	}
}
