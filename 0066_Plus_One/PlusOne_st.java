package algorithm._066_plusOne;

/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
示例 1:
	输入: [1,2,3]
	输出: [1,2,4]
	解释: 输入数组表示数字 123。
示例 2:
	输入: [4,3,2,1]
	输出: [4,3,2,2]
	解释: 输入数组表示数字 4321。
*/

public class PlusOne {
	public static void main(String[] args) {
		int[] nums = { 9 };
		int[] result = plusOne(nums);
		for (int val : result) {
			System.out.println(val);
		}
	}

	//思路 : 定义一个boolean类型的数判断是否需要向上进一位,当第一位还需要向上进一位时,
	//		则需要定义一个长度比原数组长度大一的数组,使其第一位等于一,剩余的数与digits的数相同
	public static int[] plusOne(int[] digits) {
		boolean isCeil = true;
		int index = digits.length - 1;
		while (isCeil && index >= 0) {
			digits[index] += 1;
			if (digits[index] == 10) {
				isCeil = true;
				digits[index] = 0;
			} else {
				isCeil = false;
			}
			index--;
		}
		if (isCeil) {
			int[] result = new int[digits.length + 1];
			result[0] = 1;
			for (int i = 1, j = 0; i < result.length - 1; i++, j++) {
				result[i] = digits[j];
			}
			return result;
		}
		return digits;
	}
}
