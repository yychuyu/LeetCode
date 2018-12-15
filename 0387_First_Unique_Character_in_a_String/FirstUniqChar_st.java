package algorithm._387_firstUniqChar;

/*
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
����1:
	s = "leetcode"
	���� 0.
����2:
	s = "loveleetcode",
	���� 2.
ע����������Լٶ����ַ���ֻ����Сд��ĸ��
*/

public class FirstUniqChar {
	public static void main(String[] args) {
		System.out.println(firstUniqChar("loveleetcode"));
	}

	//˼· : ����һ������Ϊ26��int����������ģ��26����ĸ,��0-25Ϊa-z
	//		������һ��,��ÿ���ַ���Ӧ��int�����ϵ�λ�õ�ֵ��һ,
	//		�����ڶ���,�����ַ���Ӧ��int�����ϵ�λ�õ�ֵΪ1ʱ,
	//		����ַ���Ϊ��һ�����ظ����ַ�,���ظ��ַ�����������
	//�ⷨ : ����һ��arr����������Ϊ26
	//		27-29��ʵ���˽��ַ����е�ÿ���ַ����ֵĴ��������arr�����ж�Ӧ��λ��
	//		31-35����Ѱ�Ҹ��ַ����е�һ�����ظ����ַ�,�ҵ���ֱ�ӷ���,�Ҳ����򷵻�-1
	public static int firstUniqChar(String s) {
		int arr[] = new int[26];
		for (int i = 0; i < s.length(); i++) {
			arr[s.charAt(i) - 97]++;
		}
		for (int i = 0; i < s.length(); i++) {
			if (arr[s.charAt(i) - 97] == 1) {
				return i;
			}
		}
		return -1;
	}
}
