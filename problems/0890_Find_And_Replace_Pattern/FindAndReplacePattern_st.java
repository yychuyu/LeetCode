package algorithm._890_findAndReplacePattern;

import java.util.ArrayList;
import java.util.List;
/*
你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。
如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。
（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）
返回 words 中与给定模式匹配的单词列表。
你可以按任何顺序返回答案。
示例：
	输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
	输出：["mee","aqq"]
解释：
	"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
	"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
	因为 a 和 b 映射到同一个字母。
提示：
	1 <= words.length <= 50
	1 <= pattern.length = words[i].length <= 20
*/

public class FindAndReplacePattern {
	public static void main(String[] args) {
		System.out.println(findAndReplacePattern(
				new String[] { "abc", "deq", "mee", "aqq", "dkd", "ccc" },
				"abb"));
	}

	//思路 : 先定义一个patterns的char数组存放pattern中不同的字符,将字符串中的字符转化为pattern中的字符
	//		再对String数组进行遍历,对每一个String进行分析,对当前的String中的字符进行遍历,
	//		如果给字符与之前出现的字符相等,则令该字符等于之前的字符转化后的字符,
	//		否则则令该字符等于pattern中的下一个字符,每当一个String判断结束后,
	//		则判断其与模式pattern是否相等,之后再令pattern的索引归0,进行下一个String的比较
	//解法 : 定义一个result来存放满足模式的字符串
	//		定义一个patterns的字符数组来存放不同模式字符串pattern中不同的字符
	//		定义一个index,用来遍历patterns数组
	//		定义一个is用来判断该字符是否与前面有字符
	//		定义一个temp数组用来存放字符串中字符转化后的值
	//		定义一个word用来对当前遍历的字符串进行操作
	//		51-63行实现了将pattern中不同的字符存进patterns数组中
	//		70-83行实现了将当前遍历的字符串进行字符转化后存放在temp数组中
	//		85-92行对temp数组与模式pattern进行对比来判断能否匹配成功
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
