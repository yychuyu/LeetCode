class Solution {
 
    //思路是利用栈的特点，有效的括号必须是前后对称的，把三种括号用map存储（也可以直接用if语句，语句多一些），有效的括号就必须是当吧所有的左括号进栈后出栈时要对应键值对的value，不然就返回false，最后出栈完了后看栈是不是空的  不是空的话那就发挥false。
    public boolean isValid(String s) {
       Map<Character,Character> map=new HashMap<>();
		map.put('(', ')');
		map.put('[',']');
		map.put('{', '}');
		Stack<Character> stack=new Stack<>();
		for(int i=0;i<s.length();i++) {
			char c=s.charAt(i);
			if(map.containsKey(c)) {
				stack.push(c);
			}else {
				if(stack.isEmpty()) return false;
				char left=stack.pop();
				if(c!=map.get(left))return false;
			}
		}
		return stack.isEmpty();
    }

}
