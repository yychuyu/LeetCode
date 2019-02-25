package algorithm._443_compress;

/*
给定一组字符，使用原地算法将其压缩。
压缩后的长度必须始终小于或等于原数组长度。
数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
在完成原地修改输入数组后，返回数组的新长度。
进阶：
	你能否仅使用O(1) 空间解决问题？
示例 1：
	输入：
		["a","a","b","b","c","c","c"]
	输出：
		返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
说明：
	"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
示例 2：
	输入：
		["a"]
	输出：
		返回1，输入数组的前1个字符应该是：["a"]
说明：
	没有任何字符串被替代。
示例 3：
	输入：
		["a","b","b","b","b","b","b","b","b","b","b","b","b"]
	输出：
		返回4，输入数组的前4个字符应该是：["a","b","1","2"]。
说明：
	由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
	注意每个数字在数组中都有它自己的位置。
注意：
	所有字符都有一个ASCII值在[35, 126]区间内。
	1 <= len(chars) <= 1000。
*/

public class Compress {
	public static void main(String[] args) {
		System.out
				.println(compress(new char[] { 'a', 'a', 'b', 'b', 'c', 'c' }));
	}

	//思路 : 定义两个指针,一个用来遍历,另一个用来移动改变数组的值,且定义一个用来记录当前字符重复出现的次数
	//		判断遍历的当前字符与下一个字符是否相同或当前字符已是数组的最后一个字符,
	//		不是则该字符即为重复出现的字符,令count++
	//		再判断当前字符重复出现的次数是否大于1,是的话则要将出现的次数转化为char类型存放进数组中即可
	//		int类型转化为char类型的两种方式:
	//			1):int --> String --> char (遍历String逐一字符转化为char类型)(个人觉得这个方法较好)
	//			2):int --> +48 --> char	(+48后强转为char即可,+48是因为0对应的ASCII码为48)
	//解法 : 定义leg用来遍历改变数组,定义count用来记录字符重复出现的次数,
	//		每出现不与当前字符重复的字符则令其归1
	//		59-65行实现了重复出现的字符将其重复出现的次数转为char类型存入到了数组中,并将count归1
	public static int compress(char[] chars) {
		int leg = 0;
		int count = 1;
		for (int i = 0; i < chars.length; i++) {
			if (i == chars.length - 1 || chars[i] != chars[i + 1]) {
				chars[leg++] = chars[i];
				if (count > 1) {
					String k = String.valueOf(count);
					for (int j = 0; j < k.length(); j++) {
						chars[leg++] = k.charAt(j);
					}
					count = 1;
				}
			} else {
				count++;
			}
		}
		return leg;
	}
}
