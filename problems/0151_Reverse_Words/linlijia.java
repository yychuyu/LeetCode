
import java.util.*;
public class Solution {
    public String reverseWords(String s) {
        
        if (s == null || s.length() < 1)
            return s;

        Deque<String> stack = new LinkedList<String>();
        s = s.trim();
        String t = "";
        for (char c : s.toCharArray()) {
            if (c != ' ') {
                t += c;
            } else if (!"".equals(t)) {
                stack.addFirst(t);
                t = "";
            }            
        }

        if (!"".equals(t)) {
            stack.addFirst(t);
        }
            t = "";
        for (String i : stack) {
            t = t + i + " ";
        }
        return t.trim();
    }
}
