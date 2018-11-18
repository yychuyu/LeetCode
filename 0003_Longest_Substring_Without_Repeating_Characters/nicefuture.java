package solution0003;

import java.util.Scanner;

public class Solution {
	
	Scanner scanner = new Scanner(System.in);
	
	public int lengthOfLongestSubstring(String s) {
		int len = 0, j = 0;
		for (int i = 0; i < s.length(); i++) {
			for (; j < s.length(); j++) {
				String sub = s.substring(i, j+1);
				if (isUnique(sub)){
                    if (sub.length() > len) {
                        len = sub.length();
                    }
                } else {
                    break;
                }
			}
			j = j+1;
		}
		return len;
    }
	
	public boolean isUnique(String s) {
		StringBuffer unique = new StringBuffer();
		for (int i = 0; i < s.length(); i++) {
			if (unique.indexOf(""+s.charAt(i)) != -1)  return false;
			unique.append(s.charAt(i));
		}
		return true;
	}
	
	public static void main(String[] args) {
		Solution init = new Solution();
		
		String input = init.scanner.next();
//		String out = String.valueOf(init.lengthOfLongestSubstring(input));
//		System.out.println(out);
		System.out.println(init.lengthOfLongestSubstring(input));
	}
}
