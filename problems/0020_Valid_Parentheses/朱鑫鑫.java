class Solution {
    public boolean isValid(String s) {
        Stack<Character> charStack = new Stack<>();
               
        boolean isTrue = true;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '[' || s.charAt(i) == '{' || s.charAt(i) == '('){
                charStack.push(s.charAt(i));
            }else{
                
                if(charStack.empty()){
                    return false;
                }
                
                char c = charStack.pop();
                if((c == '[' && s.charAt(i) == ']') || (c == '(' && s.charAt(i) == ')') || (c == '{' && s.charAt(i) == '}')){
                    continue;
                }else{
                    
                    isTrue = false;
                    break;
                }
            }
        }
        if(!charStack.empty()){
           return false;
        }
        
        return isTrue;
    }
}