//需求：在int范围内将数字反转，符号不变；若超出int范围，返回0；
//分析：模10法，一边用x模10取余，一边用余数乘10加新的余数
//注意：若有溢出，结尾要判断一下
//		正负数不影响
//时间复杂度：O(n)
//空间复杂度：O(1)

public class ReverseInteger {
//测试代码
	public static void main(String[] args) {
		int number = -123456;
		int result = reverse(number);
		System.out.print("反转后的数字是：" + result);

	}

	public static int reverse(int x) {
		long res = 0;
		while (x != 0) {
			res = res * 10 + x % 10;
			x /= 10;
		}
		return (int) ((res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) ? 0
				: res);
	}

}
