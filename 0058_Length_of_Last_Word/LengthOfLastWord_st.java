package algorithm._058_lengthOfLastWord;
/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指由字母组成，但不包含任何空格的字符串。
示例:
	输入: "Hello World"
	输出: 5
*/

public class LengthOfLastWord {
	public static void main(String[] args) {
		System.out.println(lengthOfLastWord("Hello World"));
	}

	//1):思路 : 定义一个字符串来存储单词,定义一个boolean类型来判断是否进入下一个单词,
	//		      遍历结束后返回字符串的长度即可
	//	  解法 : 对字符串进行遍历,如果当前字符为空则令isClear为true,即再遇到非空字符时,
	//		      如果isClear为true时清空result字符串且令当前字符为result字符串的首字符,
	//		      否则则令result增加该字符串,遍历结束后返回result字符串的长度即可
	//2):思路 : 因为返回的是字符串的的最后一个单词的长度,则从后开始遍历该字符串即可,
	//	               且不需要知道该单词是什么只需要知道长度即可,所以定义一个int类型的元素即可
	//		      当当前遍历的字符为空字符时,如果result长度为0则表明最后一个单词还没出现,
	//		      所以此时无需操作,否则表明最后一个单词已出现,则直接返回该长度即可
	//		      如果当前遍历的字符不为空字符时,则令result长度加1即可,遍历结束后返回result
	public static int lengthOfLastWord(String s) {
		/*boolean isClear = false;
		String result = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ') {
				isClear = true;
			} else {
				if (isClear) {
					result = s.charAt(i) + "";
				} else {
					result += s.charAt(i);
				}
				isClear = false;
			}
		}
		return result.length();*/

		int result = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s.charAt(i) == ' ') {
				if (result != 0) {
					break;
				}
			} else {
				result++;
			}
		}
		return result;
	}
}
