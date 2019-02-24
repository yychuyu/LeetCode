package practice;
import java.util.*;

class Solution {
	
	
	public static void main(String[] args) {
		String words[]={"abca","deqa","meed","abbc", "aqqd","dkdd","ccdc"};
		String pattern = "abbf";
		List<String> res = new ArrayList<>();
		res = new Solution().findAndReplacePattern(words, pattern);
		System.out.println(res);
	}
	
	public List<String> findAndReplacePattern(String[] words, String pattern) {
		List<String> res = new ArrayList<>();
		for( String word : words ) {
			int flag = 0;
			HashMap<Character, Character> kv = new HashMap<>();
			for( int i=0; i<pattern.length(); i++ ) {
				char a=pattern.charAt(i), b=word.charAt(i);
				if( kv.containsKey(a) ) {//已有键值对中已包括就比较
					if( kv.get(a)!=b ) {
						break;
					}					
				}
				else {
					if( kv.containsValue(b) ) {
						break;
					}
					else {
						kv.put(a, b);
					}
				}
				if( i==pattern.length()-1 ) {
					flag=1;
				}
				if( flag==1 ) {
					res.add(word);
				}
			}
			
		}
		
		return res;
	}
}
This file is added by makersy
