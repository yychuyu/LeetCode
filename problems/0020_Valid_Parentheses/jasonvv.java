class Solution {
    public boolean isValid(String s) {
        int len = s.length();
        if(s=="") return false;
        Stack<Character> stack = new Stack<Character>();
        char c;
        for(int i=0; i<len; i++)
        {
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='[') {
                stack.push(s.charAt(i));
            } else if(!stack.empty()) {
				c = stack.pop();
                switch (s.charAt(i)) {
                    case ')':
                        if(c != '(') return false;
                        break;
                    case ']':
                        if(c != '[') return false;
                        break;
                    case '}':
                        if(c != '{') return false;
                        break;
                    default: return false;
                }
			} else return false;
        }
        if(stack.empty()) return true;
        return false;
    }
}
