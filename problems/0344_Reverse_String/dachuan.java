class Solution {
	public String reverseString(String s) {
		char[] chars = s.toCharArray();
		int len = chars.length;
		int end = len - 1;
		for (int i = 0; i < len; i++) {
			if (i < end) {
				char tmp = chars[i];
				chars[i] = chars[len - 1 - i];
				chars[len - 1 - i] = tmp;
				end--;
			}
		}
		return new String(chars);
    }
}