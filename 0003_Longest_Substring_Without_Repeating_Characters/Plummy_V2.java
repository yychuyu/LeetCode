package cn.plummy;

import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

/**
 * 
 * @author lilin 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * @description	从空间复杂度优化,缩短运行时间
 */
public class Test0003 {
	public static void main(String[] args) {
		int maxLength = Solution.lengthOfLongestSubstring("aab");
		System.out.println("不含有重复字符的 最长子串 的长度：" + maxLength);
	}
}

class Solution {
	public static int lengthOfLongestSubstring(String s) {
		int maxLength = 0;

		if (s.length() > 0) {
			StringBuilder sb = new StringBuilder();
			String tempA;
			String tempB;
			boolean flag;

			Set<Integer> res = new HashSet<Integer>();

			for (int i = 0; i < s.length(); i++) {
				flag = false;// 标记是否有重复
				tempA = String.valueOf(s.charAt(i));
				sb.append(tempA);
				for (int j = i + 1; j < s.length(); j++) {
					tempB = String.valueOf(s.charAt(j));
					if (sb.toString().contains(tempB)) {
						flag = true;
						res.add(sb.toString().length());
						sb.setLength(0);
						break;
					} else {
						sb.append(tempB);
					}
				}

				if (!flag) {
					res.add(sb.toString().length());
					break;
				}

			}

			if (res.size() > 0) {
				maxLength = Collections.max(res);
			}

		}

		return maxLength;
	}
}