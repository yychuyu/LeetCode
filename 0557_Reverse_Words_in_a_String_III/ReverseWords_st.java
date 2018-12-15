package algorithm._557_reverseWords;
/*
����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
ʾ�� 1:
	����: "Let's take LeetCode contest"
	���: "s'teL ekat edoCteeL tsetnoc" 
ע�⣺���ַ����У�ÿ�������ɵ����ո�ָ��������ַ����в������κζ���Ŀո�
*/

public class ReverseWords {
	public static void main(String[] args) {
		System.out.println(reverseWords("Let's take LeetCode contest"));
	}

	//˼· : �����ַ���,�߱����߷�ת����,ÿ�����ո񼴽��÷�ת��ĵ��ʼӵ��µ��ַ�����,
	//		�������������һ�����ʻ�û�мӵ����ַ�����,��Ҫ�ټ�һ��
	//�ⷨ : ����һ��StringBuilder������������ַ���,
	//		����һ��String�����������ʱ����,��Ҫ��������ת�������Ա���ԭ˳��,
	//		�����ַ���,�����ո��ַ���result����temp�Ϳո�,����temp���ϸ��ַ�(����ǰ��),
	//		������������һ����ת����Ϊ��ӽ�result��,���������������result����temp����
	public static String reverseWords(String s) {
		StringBuilder result = new StringBuilder(s.length());
		String temp = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ') {
				result.append(temp);
				result.append(" ");
				temp = "";
			} else {
				temp = s.charAt(i) + temp;
			}
		}
		result.append(temp);
		return result.toString();
	}
}
