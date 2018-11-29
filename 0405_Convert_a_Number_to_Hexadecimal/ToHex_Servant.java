package algorithm._405_toHex;

/*
给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
注意:
	十六进制中所有字母(a-f)都必须是小写。
	十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；
	对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
	给定的数确保在32位有符号整数范围内。
	不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
示例 1：
	输入:26
	输出:"1a"
示例 2：
	输入:-1
	输出:"ffffffff"
*/

public class ToHex {
	public static void main(String[] args) {
		System.out.println(toHex(26));
	}

	public static String toHex(int num) {
		int[] result = new int[33];
		if (num == 0) {
			return "0";
		}
		//取出符号位,因为负数的补码为反码后加一,又因为是负数,所有可以加一后取反码
		if (num < 0) {
			result[0] = 1;
			num += 1;
		}
		int index = 32;
		//将num以32位二进制数存储到一个数组中
		while (num != 0) {
			if (num % 2 != 0) {
				result[index] = 1;
			}
			num /= 2;
			index--;
		}
		//因为正数的补码为本身,所有只当为负数是才进行求补码
		for (int i = 1; result[0] == 1 && i < result.length; i++) {
			if (result[i] == 0) {
				result[i] = 1;
			} else {
				result[i] = 0;
			}
		}
		int j = 1;
		int temp = 0;
		String stemp = "";
		String s = "";
		boolean isAdd = false;
		//将二进制转化为十六进制的字符串
		for (int i = result.length - 1; i > 0; i--) {
			temp += result[i] * j;
			j *= 2;
			if ((i - 1) % 4 == 0) {
				if (isAdd) {
					temp += 1;
					isAdd = false;
				}
				stemp = temp + "";
				switch (stemp) {
				case "10":
					stemp = "a";
					break;
				case "11":
					stemp = "b";
					break;
				case "12":
					stemp = "c";
					break;
				case "13":
					stemp = "d";
					break;
				case "14":
					stemp = "e";
					break;
				case "15":
					stemp = "f";
					break;
				case "16":
					isAdd = true;
					stemp = "0";
					break;
				}
				s = stemp + s;
				j = 1;
				temp = 0;
			}
		}
		//删除多余的前缀0
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != '0') {
				s = s.substring(i);
				break;
			}
		}
		return s;
	}
}
