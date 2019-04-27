class Solution {
    public String removeOuterParentheses(String S) {
        //将字符串转换为字符数组
        char[] ch = S.toCharArray();
        //声明一个计数器，依次检验，如果是左括号就+1，右括号就-1，当右括号是右边是左括号，并且计数器不为0，则向StringBuilder中增加数据；
        int count = 0;
        boolean isBegin = false;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < ch.length; i++) {
            if(ch[i] == '('){
                count++;
            }else if(ch[i] == ')'){
                count--;
            }
            if(count ==1 && !isBegin){
                isBegin = true;
            }else if(count == 0 && isBegin){
                isBegin = false;
                continue;
            }else if(isBegin){
                sb.append(ch[i]);
            }
        }
        //返回sb.toString()
        return sb.toString();
    }
}