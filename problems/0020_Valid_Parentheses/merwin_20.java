//注意char的装箱类型为Character
class Solution {
    public boolean isValid(String s) {
        if(s.length()==0){
            return true;
        }
        char [] chars = s.toCharArray();
        Stack<Character> stack = new Stack<>();
        for(int i=0; i<chars.length; i++){
            if(chars[i] == '('){
                stack.push(chars[i]);
            }
            if(chars[i] == '{'){
                stack.push(chars[i]);
            }
            if(chars[i] == '['){
                stack.push(chars[i]);
            }
            if(chars[i] == ')'){
                if(stack.isEmpty() || stack.pop() != '('){
                    return false;
                }
            }
            if(chars[i] == '}'){
                if(stack.isEmpty() || stack.pop() != '{'){
                    return false;
                }
            }
            if(chars[i] == ']'){
                if(stack.isEmpty() || stack.pop() != '['){
                    return false;
                }
            }
        }
        if(stack.isEmpty()){
            return true;
        }
        return false;
    }
}
