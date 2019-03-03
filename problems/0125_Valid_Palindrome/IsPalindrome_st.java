package algorithm._125_isPalindrome;
/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
ʾ�� 1:
	����: "A man, a plan, a canal: Panama"
	���: true
ʾ�� 2:
	����: "race a car"
	���: false
*/

public class IsPalindrome {
	public static void main(String[] args) {
		String s = "race a car";
		System.out.println(isPalindrome(s));
	}

	//˼· : ����һ��������������ַ����е���ĸ������(���������ʱ��˳�㽫��д����ĸȫ��ת��ΪСд)
	//		����˫ָ��,���м����,�ж�ͷβָ����ָ������Ƿ�������ж����Ƿ�Ϊ���Ĵ�
	//�ⷨ : ����һ��result��char������������ַ����е���ĸ������,
	//		����һ��last��������,
	//		27-37��ʵ����result����Ĵ�Ų���
	//		����һ��first������Ϊͷָ��
	//		��֮ǰ���ڱ�����last��1����Ϊβָ��
	//		43-49���ж�result�Ƿ�Ϊ��������������������ַ����Ƿ�Ϊ���Ĵ�
	public static boolean isPalindrome(String s) {
		char[] result = new char[s.length()];
		int last = 0;
		for (int i = 0; i < s.length(); i++) {
			if ((s.charAt(i) >= '0' && s.charAt(i) <= '9')
					|| (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')) {
				result[last] = s.charAt(i);
				last++;
			}
			if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
				result[last] = (char) (s.charAt(i) + 32);
				last++;
			}
		}
		int first = 0;
		last -= 1;
		while (first < last) {
			if (result[first] != result[last]) {
				return false;
			}
			first++;
			last--;
		}
		return true;
	}
}
