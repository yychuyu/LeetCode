package algorithm._557_reverseWords;
/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
示例 1:
	输入: "Let's take LeetCode contest"
	输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/

public class ReverseWords {
	public static void main(String[] args) {
		System.out.println(reverseWords("Let's take LeetCode contest"));
	}

	//思路 : 遍历字符串,边遍历边反转单词,每遇到空格即将该反转后的单词加到新的字符串中,
	//		遍历结束后最后一个单词还没有加到新字符串中,需要再加一遍
	//解法 : 定义一个StringBuilder类型来存放新字符串,
	//		定义一个String类型来存放临时单词,主要是用来反转单词且仍保留原顺序,
	//		遍历字符串,遇到空格字符则result加上temp和空格,否则temp加上该字符(加在前面),
	//		遍历结束后还有一个反转单词为添加进result中,则遍历结束后再让result加上temp即可
	public static String reverseWords(String s) {
		StringBuilder result = new StringBuilder(s.length());
		String temp = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ') {
				result.append(temp);
				result.append(" ");
				temp = "";
			} else {
				temp = s.charAt(i) + temp;
			}
		}
		result.append(temp);
		return result.toString();
	}
}
