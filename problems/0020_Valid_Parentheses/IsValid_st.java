package algorithm._020_isValid;

import java.util.Stack;

/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
	�����ű�������ͬ���͵������űպϡ�
	�����ű�������ȷ��˳��պϡ�
	ע����ַ����ɱ���Ϊ����Ч�ַ�����
ʾ�� 1:
	����: "()"
	���: true
ʾ�� 2:
	����: "()[]{}"
	���: true
ʾ�� 3:
	����: "(]"
	���: false
ʾ�� 4:
	����: "([)]"
	���: false
ʾ�� 5:
	����: "{[]}"
	���: true
*/

public class IsValid {
	public static void main(String[] args) {
		System.out.println(isValid("()[]{}"));
	}

	//˼· : ��ASCII������ʾ����,(=40,)=41,[=91,]=93,{=123,}=125
	//		�����ַ���,���������������ջ���д洢,���ʹ���������ж���ջ��Ԫ���Ƿ�ƥ��
	//		��Ϊ��һ�������ſ϶��������������ƥ��,������ջ������ȥ�жϼ���
	//�ⷨ : ����ַ���Ϊ�ջ򳤶�Ϊ0����true,�����������2������0������false
	//		����һ��ջ���ȴ���ַ����ĵ�һ��Ԫ��,��Ϊ���ȴ��ֱ�ӱ����Ļ�,�����һ��Ϊ�����������ֿ�ָ��
	//		�����ַ���,��������������Ž�ջ��,���Ϊ����������ջ�������ж�,
	//		���ƥ����ɾ���Ѷ���Ԫ��,��ƥ����ֱ�ӷ���false,
	//		�������������жϸ�ջ�Ƿ�Ϊ��ջ,�����Ϊ����ջ�л��ж����������û�н���ƥ��
	//		�������Ϊ��ջ�ŷ���true,���򷵻�false
	public static boolean isValid(String s) {
		if (s == null || s.length() == 0) {
			return true;
		}
		if (s.length() % 2 != 0) {
			return false;
		}
		Stack<Character> stack = new Stack<>();
		stack.push(s.charAt(0));
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) == 40 || s.charAt(i) == 91 || s.charAt(i) == 123) {
				stack.push(s.charAt(i));
			} else {
				if (s.charAt(i) - 1 == stack.peek()
						|| s.charAt(i) - 2 == stack.peek()) {
					stack.pop();
				} else {
					return false;
				}
			}
		}
		if (stack.empty()) {
			return true;
		}
		return false;
	}
}
