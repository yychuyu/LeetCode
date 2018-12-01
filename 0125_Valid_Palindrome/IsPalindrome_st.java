package algorithm._125_isPalindrome;
/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
	输入: "A man, a plan, a canal: Panama"
	输出: true
示例 2:
	输入: "race a car"
	输出: false
*/

public class IsPalindrome {
	public static void main(String[] args) {
		String s = "race a car";
		System.out.println(isPalindrome(s));
	}

	//思路 : 定义一个数组用来存放字符串中的字母及数字(遍历存入的时候顺便将大写的字母全部转化为小写)
	//		利用双指针,往中间遍历,判断头尾指针所指向的数是否相等来判断其是否为回文串
	//解法 : 定义一个result的char数组用来存放字符串中的字母即数字,
	//		定义一个last用来遍历,
	//		27-37行实现了result数组的存放操作
	//		定义一个first用来做为头指针
	//		将之前用于遍历的last减1后作为尾指针
	//		43-49行判断result是否为回文数组来决定传入的字符串是否为回文串
	public static boolean isPalindrome(String s) {
		char[] result = new char[s.length()];
		int last = 0;
		for (int i = 0; i < s.length(); i++) {
			if ((s.charAt(i) >= '0' && s.charAt(i) <= '9')
					|| (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')) {
				result[last] = s.charAt(i);
				last++;
			}
			if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
				result[last] = (char) (s.charAt(i) + 32);
				last++;
			}
		}
		int first = 0;
		last -= 1;
		while (first < last) {
			if (result[first] != result[last]) {
				return false;
			}
			first++;
			last--;
		}
		return true;
	}
}
