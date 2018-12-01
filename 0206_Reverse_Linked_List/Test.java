package cn.plummy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test {
	public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in  ));
        String line;
        while ((line = in.readLine()) != null) {
            ListNode head = ReverseLinkNode.stringToListNode(line);
            ListNode ret = new ReverseLinkNode().reverseList(head);
            String out = ReverseLinkNode.listNodeToString(ret);
            
            System.out.print(out);

        }
    }
}
