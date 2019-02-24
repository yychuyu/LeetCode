package algorithm._387_firstUniqChar;

/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
案例1:
	s = "leetcode"
	返回 0.
案例2:
	s = "loveleetcode",
	返回 2.
注意事项：您可以假定该字符串只包含小写字母。
*/

public class FirstUniqChar {
	public static void main(String[] args) {
		System.out.println(firstUniqChar("loveleetcode"));
	}

	//思路 : 定义一个容量为26的int类型数组来模拟26个字母,即0-25为a-z
	//		遍历第一次,让每个字符对应在int类型上的位置的值加一,
	//		遍历第二次,当该字符对应在int类型上的位置的值为1时,
	//		则该字符即为第一个不重复的字符,返回该字符的索引即可
	//解法 : 定义一个arr数组其容量为26
	//		27-29行实现了将字符串中的每个字符出现的次数存放在arr数组中对应的位置
	//		31-35行则寻找该字符串中第一个不重复的字符,找到则直接返回,找不到则返回-1
	public static int firstUniqChar(String s) {
		int arr[] = new int[26];
		for (int i = 0; i < s.length(); i++) {
			arr[s.charAt(i) - 97]++;
		}
		for (int i = 0; i < s.length(); i++) {
			if (arr[s.charAt(i) - 97] == 1) {
				return i;
			}
		}
		return -1;
	}
}
