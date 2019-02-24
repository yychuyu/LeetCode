package algorithm._151_reverseWords;

/*
给定一个字符串，逐个翻转字符串中的每个单词。
示例:  
	输入: "the sky is blue",
	输出: "blue is sky the".
说明:
	无空格字符构成一个单词。
	输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
	如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
*/

public class ReverseWords {
	public static void main(String[] args) {
		System.out.println(reverseWords("  the   sky  is  blue   "));
	}

	//思路 : 定义一个用来存放反转后的字符串,再定义一个用来临时存放单词的字符串
	//		遍历字符串,没遇到空格即让该字符加在单词里,直到遇到空格或已经遍历到了该字符串的最后一位
	//		再判断单词字符串是否有单词,有则判断反转字符串中有无字符存在,
	//		没有则令反转字符串等于该单词,有则令反转字符串等于该单词加上空格再加上原反转字符串,
	//		每当遇到空格则说明已遍历完了一个单词,完成临时单词的操作后需要将临时单词设置为空
	//解法 : 定义一个result字符串用来存放反转后的字符串
	//		定义一个temp字符串用来存放临时单词
	//		32-34行实现了临时单词的存储
	//		36-45行实现了反转字符串的增加,但遍历字符串遇到空格后或者遍历的为字符串的最后一位
	//		再判断临时单词temp中是否存在单词,如果存在则再判断反转字符串result中有无字符,
	//		如果有则该反转字符串result等于临时单词temp加上空格再加上原反转字符串result,
	//		如果没有则说明该临时单词temp是反转字符串result的最后一个单词,所有不需要有任何空格,
	//		则直接令反转字符串result等于临时单词temp即可,
	//		每当遇到空格则说明已遍历完了一个单词,完成临时单词的操作后需要将临时单词设置为空
	public static String reverseWords(String s) {
		String result = "";
		String temp = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != ' ') {
				temp += s.charAt(i);
			}
			if (s.charAt(i) == ' ' || i == s.length() - 1) {
				if (temp != "") {
					if (result == "") {
						result = temp;
					} else {
						result = temp + " " + result;
					}
				}
				temp = "";
			}
		}
		return result;
	}
}
