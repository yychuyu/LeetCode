/******
这是用java写堆栈

*******/


class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
			//这里的for(char c:chars)就是定义一个遍历字符c，让它分别等于字符串数组chars里面的各个字符，然后执行下面的语句，当c被赋值为chars里面所有字符各一次后，就会退出这个循环.
        for (char c : s.toCharArray()){
            if (c == '(')
                stack.push(')');
            else if (c == '{')
                stack.push('}');
            else if (c == '[')
                stack.push(']');
            else if (stack.isEmpty() || stack.pop()!= c)
                return false;
        }
        return stack.isEmpty();}
}
	


