package algorithm._400_findNthDigit;

/*
在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
注意:
	n 是正数且在32为整形范围内 ( n < 2^31)。
示例 1:
	输入:3
	输出:3
示例 2:
	输入:11
	输出:0
说明:
	第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
*/

public class FindNthDigit {
	public static void main(String[] args) {
		System.out.println(findNthDigit(999999999));
	}

	//思路 : 先找到n所在的那个整数,再找n所指的是该整数的那个数,返回该数即可
	//解答 : 根据位数区分,一位数的有9个,二位数的有90个,三位数的有900个,
	// 		所有可以得到9*10^(位数-1),又因为每个数字有是几位数就占几个数,
	//		可得到9*10^(位数-1)*位数,根据n的值求出n所在的数字是几位数的数字
	//		再由n%n的位数的到一个数,如果该数为几就返回这个几位数的第几个数字,
	//		若为0则直接返回这个几位数的最后一个数字(%);
	//注意 : p*i*9 大于int范围而变为负数,
	//		取一个整数中的某个数先在该数中将以要取的那个数为一个新数的尾取出前面的数后求余10得到
	//		或者将以要取的那个数为一个新数的头取出后面的数后除以10得到
	public static int findNthDigit(int n) {
		if (n < 10) {
			return n;
		}
		int leg = 1;
		int p = 1;
		for (int i = 1; n - 9 * i * p > 0; i++) {
			n = n - 9 * i * p;
			p *= 10;
			leg++;
			if(9 * i * p < 0 ) {
				break;
			}
		}
		int temp = n % leg;
		if (temp == 0) {
			n = n / leg;
			n = p + n - 1;
			return n % 10;
		}
		n = n / leg + 1;
		n = p + n - 1;
		for (; temp > 1; temp--) {
			p /= 10;
		}
		return n / p % 10;
	}
}
