package algorithm._020_isValid;

import java.util.Stack;

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
	左括号必须用相同类型的右括号闭合。
	左括号必须以正确的顺序闭合。
	注意空字符串可被认为是有效字符串。
示例 1:
	输入: "()"
	输出: true
示例 2:
	输入: "()[]{}"
	输出: true
示例 3:
	输入: "(]"
	输出: false
示例 4:
	输入: "([)]"
	输出: false
示例 5:
	输入: "{[]}"
	输出: true
*/

public class IsValid {
	public static void main(String[] args) {
		System.out.println(isValid("()[]{}"));
	}

	//思路 : 用ASCII码来表示括号,(=40,)=41,[=91,]=93,{=123,}=125
	//		遍历字符串,如果是左括号则用栈进行存储,如何使右括号则判断与栈顶元素是否匹配
	//		因为第一个右括号肯定与最近的左括号匹配,所有用栈顶与其去判断即可
	//解法 : 如果字符串为空或长度为0返回true,如果长度求余2不等于0即返回false
	//		定义一个栈后先存放字符串的第一个元素,因为不先存放直接遍历的话,如果第一个为右括号则会出现空指针
	//		遍历字符串,如果是左括号则存放进栈中,如果为右括号则与栈顶进行判断,
	//		如果匹配则删除堆顶的元素,不匹配则直接返回false,
	//		遍历结束后再判断该栈是否为空栈,如果不为空则栈中还有多余的左括号没有进行匹配
	//		所有如果为空栈才返回true,否则返回false
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
