package algorithm._788_rotatedDigits;
/*
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。
要求每位数字都要被旋转。
如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。
0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9 同理，
除了这些以外其他的数字旋转以后都不再是有效的数字。
现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
示例:
	输入: 10
	输出: 4
解释: 
	在[1, 10]中有四个好数： 2, 5, 6, 9。
	注意 1 和 10 不是好数, 因为他们在旋转之后不变。
注意:
	N 的取值范围是 [1, 10000]。
*/

public class RotatedDigits {
	public static void main(String[] args) {
		System.out.println(rotatedDigits(6000));
	}

	//思路 : 遍历1到N,再一个个判断其是不是好数,一个数令其一位数一位数的进行旋转
	//		如果一个数中存在3,4,7则不需要再进行判断,当旋转进行到了最后一个位了
	//		再判断其与原数是否相等(运用%,/的运算来进行取数)
	//优化 : 如果位数的数字为3,4,7则直接跳过该位数为3,4,7的数
	//		例 : 5400第二位数为4,则令下一个遍历的数为5500
	//			不用考虑什么5426,则下一个遍历的数为5526则中间的一些数没有遍历到,
	//			因为当遍历到5426前必会遍历到5400,所以会直接跳过到5500
	//解法 : 定义一个s来存储好数的个数,定义一个i用于遍历,
	//		定义一个digits来表示当前遍历的数是几位数(用1,10,100等10的倍数表示)
	//		定义一个temp和tempdigits来进行取数的操作,
	//		定义一个tempresult来存储取出来的数进行判断,
	//		定义一个result来存储旋转后的数字,用来判断当前所遍历的数是否为好数
	public static int rotatedDigits(int N) {
		int s = 0;
		int i = 1;
		int digits = 1;
		int tempdigits = 1;
		int temp = 1;
		int tempresult = 1;
		int result = 0;
		while (i <= N) {
			result = 0;
			if (i == (digits * 10)) {
				digits *= 10;
			}
			temp = i;
			tempdigits = digits;
			while (tempdigits != 0) {
				tempresult = temp / tempdigits;
				if (tempresult == 3 || tempresult == 4 || tempresult == 7) {
					i += tempdigits - 1;
					break;
				} else if (tempresult == 2) {
					tempresult = 5;
				} else if (tempresult == 5) {
					tempresult = 2;
				} else if (tempresult == 6) {
					tempresult = 9;
				} else if (tempresult == 9) {
					tempresult = 6;
				}
				result += tempresult * tempdigits;
				if (tempdigits == 1 && result != i) {
					s++;
				}
				temp %= tempdigits;
				tempdigits /= 10;
			}
			i++;
		}
		return s;
	}
}
