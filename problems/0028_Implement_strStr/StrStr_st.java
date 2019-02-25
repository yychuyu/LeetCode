package algorithm._028_strStr;

/*
ʵ�� strStr() ������
����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)��
��������ڣ��򷵻�  -1��
ʾ�� 1:
	����: haystack = "hello", needle = "ll"
	���: 2
ʾ�� 2:
	����: haystack = "aaaaa", needle = "bba"
	���: -1
˵��:
	�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣
	���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������
*/

public class StrStr {
	public static void main(String[] args) {
		System.out.println(strStr("mississippi", ""));
	}

	public static int strStr(String haystack, String needle) {
		if (needle.length() == 0 ) {
			return 0;
		}
		if (haystack.length() < needle.length()) {
			return -1;
		}
		for (int i = 0; i < haystack.length(); i++) {
			if (haystack.charAt(i) == needle.charAt(0)) {
				for (int j = 0; j < needle.length() && i + j < haystack.length(); j++) {
					if (haystack.charAt(i + j) != needle.charAt(j)) {
						break;
					}
					if (j == needle.length() - 1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
}
