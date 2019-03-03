package algorithm._014_longestCommonPrefix;

/*
��дһ�������������ַ��������е������ǰ׺��
��������ڹ���ǰ׺�����ؿ��ַ��� ""��
ʾ�� 1:
	����: ["flower","flow","flight"]
	���: "fl"
ʾ�� 2:
	����: ["dog","racecar","car"]
	���: ""
����: ���벻���ڹ���ǰ׺��
˵��:
	��������ֻ����Сд��ĸ a-z ��
*/
public class LongestCommonPrefix {
	public static void main(String[] args) {
		String[] s = new String[] {"dog","racecar","car"};
		System.out.println(longestCommonPrefix(s));
	}

	public static String longestCommonPrefix(String[] strs) {
		String str = "";
		String strTemp = "";
		boolean isEquals = false;
		if(strs.length == 0 || strs[0].length() == 0) {
			return str;
		}
		for (int i = 0; i < strs[0].length(); i++) {
			isEquals = false;
			strTemp += strs[0].charAt(i);
			for (int j = 0; j < strs.length; j++) {
				if(!strs[j].startsWith(strTemp)) {
					break;
				}
				if(j == strs.length - 1) {
					str = strTemp;
					isEquals = true;
				}
			}
			if(!isEquals) {
				break;
			}
		}
		return str;
	}
}
