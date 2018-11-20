import java.util.Scanner;

public class RomanToInteger {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (true) {
			System.out.println("请输入罗马数字");
			String Roman = sc.nextLine();
			System.out.println(romanToInt(Roman));
		}
	}

	public static int romanToInt(String s) {
		boolean qian = false;
		boolean wubai = false;
		boolean bai = false;
		boolean wushi = false;
		boolean shi = false;
		boolean wu = false;
		int result = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			switch (s.charAt(i)) {
			case 'I':
				result = shi || wu ? (result + 1) : (result - 1);
				break;
			case 'V':
				result += 5;
				wu = true;
				break;
			case 'X':
				result = wushi || bai ? (result + 10) : (result - 10);
				break;
			case 'L':
				result += 50;
				wushi = true;
				break;
			case 'C':
				result = wubai || qian ? (result + 100) : (result - 100);
				break;
			case 'D':
				result += 500;
				wubai = true;
				break;
			case 'M':
				result += 1000;
				qian = true;
				break;
			}
		}
		return result;
	}
}
