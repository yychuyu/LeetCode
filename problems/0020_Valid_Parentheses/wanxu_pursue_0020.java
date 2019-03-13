import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @Author: Json Wan
 * Created at: 2019/3/13.
 * Description:
 *
 * 思路：利用栈的思想即可解决，需要注意提前结束判断（只要有第一个右不能匹配上即可结束）
 */
public class wanxu_pursue_0020 {

    //1.自己手写数据结构ArrayList比使用现成的要来得快，因为少一层封装，减少new对象的成本
    //2.少量判断使用if-else比map来得快，因为节省了Hash计算的过程
    // '(', ')', '{', '}', '[' and ']'
    public boolean bestIsValid(String s) {
        char[] stack = new char[s.length()];
        int top = -1;
        for(char ch : s.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack[++top] = ch;
            } else if (ch == ')') {
                if (top >= 0 && stack[top] == '(') {
                    --top;
                } else {
                    return false;
                }
            } else if (ch == '}') {
                if (top >= 0 && stack[top] == '{') {
                    --top;
                } else {
                    return false;
                }
            } else if (ch == ']') {
                if (top >= 0 && stack[top] == '[') {
                    --top;
                } else {
                    return false;
                }
            }
        }
        return top == -1;
    }
    //AC,0.9215
    public boolean isValid(String s) {
        int l = s.length();
        if (l % 2 != 0) {
            return false;
        }
        Map<Character,Character> map=new HashMap<>();
        map.put(')','(');
        map.put(']','[');
        map.put('}','{');
        List<Character> list=new ArrayList<>();
        for(int i=0;i<l;i++){
            Character ch=s.charAt(i);
            if(')'==ch||']'==ch||'}'==ch){
                if(list.size()==0){
                    return false;
                }else{
                    if(list.get(list.size()-1).equals(map.get(ch))){
                        list.remove(list.size()-1);
                    }else{
                        return false;
                    }
                }
            }else {
                list.add(ch);
            }
        }
        if(list.size()==0) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        wanxu_pursue_0020 instance = new wanxu_pursue_0020();
        System.out.println(instance.isValid("()") == true);
        System.out.println(instance.isValid("()[]{}") == true);
        System.out.println(instance.isValid("(]") == false);
        System.out.println(instance.isValid("([)]") == false);
        System.out.println(instance.isValid("{[]}") == true);
    }
}
