/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/
class Solution {
    //map中的参数是键值对
    private HashMap<Character,Character> mappings;
    public Solution(){
        this.mappings=new HashMap<Character, Character>();
        //键是)，因为后面要进行判断，左括号要加入栈，右括号要进行比较是否一致
        //值每啥子用，到底在哪里用到了？进行值比较的时候用到，弹栈的一定是左括号，进行比较就正好用到
        this.mappings.put(')','(');
        this.mappings.put(']','[');
        this.mappings.put('}','{');
    }
    public boolean isValid(String s) {
        //如果是基数肯定不是有效括号
        if(s.length()%2!=0)return false;
        //创建一个栈对象
        Stack<Character> stack=new Stack<Character>();
        //遍历字符串
        for(int i=0;i<s.length();i++){
            //获取字符串每一位的字符
            char c=s.charAt(i);
            //进行判断是否是左括号
            if(this.mappings.containsKey(c)){
                //是右括号,栈不为null就弹栈,并把弹栈的字符赋值给topElement
                char topElement=stack.empty()?'#':stack.pop();
                //如果弹出的字符和我们的键值对中的值不一致就返回false，弹栈的是左括号
                if(topElement!=this.mappings.get(c)){
                    return false;
                }
            }else{
                //是左括号就入栈
                stack.push(c);
            }
        }
        //最后判断栈是不是为空，是空的就说明刚刚好，所有括号都有效
        return stack.isEmpty();
    }
}