package algorithm._405_toHex;

/*
����һ����������дһ���㷨�������ת��Ϊʮ�������������ڸ�����������ͨ��ʹ�� �������� ������
ע��:
	ʮ��������������ĸ(a-f)��������Сд��
	ʮ�������ַ����в��ܰ��������ǰ���㡣���Ҫת������Ϊ0����ô�Ե����ַ�'0'����ʾ��
	�������������ʮ�������ַ����еĵ�һ���ַ���������0�ַ��� 
	��������ȷ����32λ�з���������Χ�ڡ�
	����ʹ���κ��ɿ��ṩ�Ľ�����ֱ��ת�����ʽ��Ϊʮ�����Ƶķ�����
ʾ�� 1��
	����:26
	���:"1a"
ʾ�� 2��
	����:-1
	���:"ffffffff"
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
		//ȡ������λ,��Ϊ�����Ĳ���Ϊ������һ,����Ϊ�Ǹ���,���п��Լ�һ��ȡ����
		if (num < 0) {
			result[0] = 1;
			num += 1;
		}
		int index = 32;
		//��num��32λ���������洢��һ��������
		while (num != 0) {
			if (num % 2 != 0) {
				result[index] = 1;
			}
			num /= 2;
			index--;
		}
		//��Ϊ�����Ĳ���Ϊ����,����ֻ��Ϊ�����ǲŽ�������
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
		//��������ת��Ϊʮ�����Ƶ��ַ���
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
		//ɾ�������ǰ׺0
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != '0') {
				s = s.substring(i);
				break;
			}
		}
		return s;
	}
}
