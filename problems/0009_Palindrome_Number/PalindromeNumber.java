import java.util.Scanner;

public class PalindromeNumber {

	//测试方法
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入你的数字：");
		int x = sc.nextInt();
		System.out.println(isPalindrome(x));
	}

	//
	public static boolean isPalindrome(int x) {
		//排除负数或者以0 结尾
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}
		
		//模十取余法
		int rev = 0;
		while (x > rev) {
			rev = rev * 10 + x % 10;
			x /= 10;
		}

		return x == rev || x == rev / 10;

	}
}
