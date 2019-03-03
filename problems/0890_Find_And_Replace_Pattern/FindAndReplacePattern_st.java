package algorithm._890_findAndReplacePattern;

import java.util.ArrayList;
import java.util.List;
/*
����һ�������б� words ��һ��ģʽ  pattern������֪�� words �е���Щ������ģʽƥ�䡣
���������ĸ������ p ��ʹ�ý�ģʽ�е�ÿ����ĸ x �滻Ϊ p(x) ֮�����Ǿ͵õ�������ĵ��ʣ���ô������ģʽ��ƥ��ġ�
������һ�£���ĸ�������Ǵ���ĸ����ĸ��˫�䣺ÿ����ĸӳ�䵽��һ����ĸ��û��������ĸӳ�䵽ͬһ����ĸ����
���� words �������ģʽƥ��ĵ����б�
����԰��κ�˳�򷵻ش𰸡�
ʾ����
	���룺words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
	�����["mee","aqq"]
���ͣ�
	"mee" ��ģʽƥ�䣬��Ϊ�������� {a -> m, b -> e, ...}��
	"ccc" ��ģʽ��ƥ�䣬��Ϊ {a -> c, b -> c, ...} �������С�
	��Ϊ a �� b ӳ�䵽ͬһ����ĸ��
��ʾ��
	1 <= words.length <= 50
	1 <= pattern.length = words[i].length <= 20
*/

public class FindAndReplacePattern {
	public static void main(String[] args) {
		System.out.println(findAndReplacePattern(
				new String[] { "abc", "deq", "mee", "aqq", "dkd", "ccc" },
				"abb"));
	}

	//˼· : �ȶ���һ��patterns��char������pattern�в�ͬ���ַ�,���ַ����е��ַ�ת��Ϊpattern�е��ַ�
	//		�ٶ�String������б���,��ÿһ��String���з���,�Ե�ǰ��String�е��ַ����б���,
	//		������ַ���֮ǰ���ֵ��ַ����,������ַ�����֮ǰ���ַ�ת������ַ�,
	//		����������ַ�����pattern�е���һ���ַ�,ÿ��һ��String�жϽ�����,
	//		���ж�����ģʽpattern�Ƿ����,֮������pattern��������0,������һ��String�ıȽ�
	//�ⷨ : ����һ��result���������ģʽ���ַ���
	//		����һ��patterns���ַ���������Ų�ͬģʽ�ַ���pattern�в�ͬ���ַ�
	//		����һ��index,��������patterns����
	//		����һ��is�����жϸ��ַ��Ƿ���ǰ�����ַ�
	//		����һ��temp������������ַ������ַ�ת�����ֵ
	//		����һ��word�����Ե�ǰ�������ַ������в���
	//		51-63��ʵ���˽�pattern�в�ͬ���ַ����patterns������
	//		70-83��ʵ���˽���ǰ�������ַ��������ַ�ת��������temp������
	//		85-92�ж�temp������ģʽpattern���жԱ����ж��ܷ�ƥ��ɹ�
	public static List<String> findAndReplacePattern(String[] words,
			String pattern) {
		List<String> result = new ArrayList<String>();
		char[] patterns = new char[pattern.length()];
		int index = 0;
		boolean is = false;
		char[] temp = new char[pattern.length()];
		String word;
		for (int i = 0; i < pattern.length(); i++) {
			is = false;
			for (int j = 0; j < patterns.length; j++) {
				if (patterns[j] == pattern.charAt(i)) {
					is = true;
					break;
				}
			}
			if (!is) {
				patterns[index] = pattern.charAt(i);
				index++;
			}
		}
		for (int i = 0; i < words.length; i++) {
			index = 0;
			word = words[i];
			if (word.length() != pattern.length()) {
				continue;
			}
			for (int j = 0; j < word.length(); j++) {
				is = false;
				for (int k = 0; k < j; k++) {
					if (word.charAt(j) == word.charAt(k)) {
						temp[j] = temp[k];
						is = true;
						break;
					}
				}
				if (!is) {
					temp[j] = patterns[index];
					index++;
				}
			}
			for (int j = 0; j < temp.length; j++) {
				if (temp[j] != pattern.charAt(j)) {
					break;
				}
				if (j == temp.length - 1) {
					result.add(word);
				}
			}
		}
		return result;
	}
}
