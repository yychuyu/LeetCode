package algorithm._058_lengthOfLastWord;
/*
����һ����������Сд��ĸ�Ϳո� ' ' ���ַ��������������һ�����ʵĳ��ȡ�
������������һ�����ʣ��뷵�� 0 ��
˵����һ��������ָ����ĸ��ɣ����������κοո���ַ�����
ʾ��:
	����: "Hello World"
	���: 5
*/

public class LengthOfLastWord {
	public static void main(String[] args) {
		System.out.println(lengthOfLastWord("Hello World"));
	}

	//1):˼· : ����һ���ַ������洢����,����һ��boolean�������ж��Ƿ������һ������,
	//		      ���������󷵻��ַ����ĳ��ȼ���
	//	  �ⷨ : ���ַ������б���,�����ǰ�ַ�Ϊ������isClearΪtrue,���������ǿ��ַ�ʱ,
	//		      ���isClearΪtrueʱ���result�ַ������ǰ�ַ�Ϊresult�ַ��������ַ�,
	//		      ��������result���Ӹ��ַ���,���������󷵻�result�ַ����ĳ��ȼ���
	//2):˼· : ��Ϊ���ص����ַ����ĵ����һ�����ʵĳ���,��Ӻ�ʼ�������ַ�������,
	//	               �Ҳ���Ҫ֪���õ�����ʲôֻ��Ҫ֪�����ȼ���,���Զ���һ��int���͵�Ԫ�ؼ���
	//		      ����ǰ�������ַ�Ϊ���ַ�ʱ,���result����Ϊ0��������һ�����ʻ�û����,
	//		      ���Դ�ʱ�������,����������һ�������ѳ���,��ֱ�ӷ��ظó��ȼ���
	//		      �����ǰ�������ַ���Ϊ���ַ�ʱ,����result���ȼ�1����,���������󷵻�result
	public static int lengthOfLastWord(String s) {
		/*boolean isClear = false;
		String result = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ') {
				isClear = true;
			} else {
				if (isClear) {
					result = s.charAt(i) + "";
				} else {
					result += s.charAt(i);
				}
				isClear = false;
			}
		}
		return result.length();*/

		int result = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s.charAt(i) == ' ') {
				if (result != 0) {
					break;
				}
			} else {
				result++;
			}
		}
		return result;
	}
}
