package algorithm._014_longestCommonPrefix;

/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
	输入: ["flower","flow","flight"]
	输出: "fl"
示例 2:
	输入: ["dog","racecar","car"]
	输出: ""
解释: 输入不存在公共前缀。
说明:
	所有输入只包含小写字母 a-z 。
*/
public class LongestCommonPrefix {
	public static void main(String[] args) {
		String[] s = new String[] {"dog","racecar","car"};
		System.out.println(longestCommonPrefix(s));
	}

	public static String longestCommonPrefix(String[] strs) {
		String str = "";
		String strTemp = "";
		boolean isEquals = false;
		if(strs.length == 0 || strs[0].length() == 0) {
			return str;
		}
		for (int i = 0; i < strs[0].length(); i++) {
			isEquals = false;
			strTemp += strs[0].charAt(i);
			for (int j = 0; j < strs.length; j++) {
				if(!strs[j].startsWith(strTemp)) {
					break;
				}
				if(j == strs.length - 1) {
					str = strTemp;
					isEquals = true;
				}
			}
			if(!isEquals) {
				break;
			}
		}
		return str;
	}
}
