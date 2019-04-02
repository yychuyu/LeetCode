import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @Author: Json Wan
 * Created at: 2019/3/13.
 * Description:
 *
 * ˼·������ջ��˼�뼴�ɽ������Ҫע����ǰ�����жϣ�ֻҪ�е�һ���Ҳ���ƥ���ϼ��ɽ�����
 */
public class wanxu_pursue_0020 {

    //1.�Լ���д���ݽṹArrayList��ʹ���ֳɵ�Ҫ���ÿ죬��Ϊ��һ���װ������new����ĳɱ�
    //2.�����ж�ʹ��if-else��map���ÿ죬��Ϊ��ʡ��Hash����Ĺ���
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
