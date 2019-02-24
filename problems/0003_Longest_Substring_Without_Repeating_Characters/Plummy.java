package cn.plummy;

import java.util.ArrayList;
import java.util.List;

/**
 * 
 * @author lilin 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
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
		if (s.length() == 1) {
			return 1;
		}

		if (s.length() > 0) {
			StringBuilder sb;
			String tempA;
			String tempB;
			
			List<String> res = new ArrayList<>();

			for (int i = 0; i < s.length(); i++) {
				boolean flag = false;// 标记是否有重复
				tempA = String.valueOf(s.charAt(i));
				sb = new StringBuilder(tempA);
				for (int j = i + 1; j < s.length(); j++) {
					tempB = String.valueOf(s.charAt(j));
					if (sb.toString().contains(tempB)) {
						flag = true;
						res.add(sb.toString());
						sb = new StringBuilder(tempB);
						break;
					} else {
 						sb.append(tempB);
					}
				}

				if (!flag) {
					res.add(sb.toString());
					break;
				}

			}
			if (res.size() > 0) {
				maxLength = res.get(0).length();
				for (int i = 1; i < res.size(); i++) {
					if (res.get(i).length() > maxLength) {
						maxLength = res.get(i).length();
					}

				}
			}

		}

		return maxLength;
	}
}