/**
 * * @ClassName Palindrome
 * * @Description
 * 回文数组，使用栈解决。
 * 先让链表的一半元素入栈，再对剩余的元素和堆栈中的元素做比较
 * * @Author luoquan
 * * 微信 luo_quan1982
 * * @Email luo.quan@aliyun.com
 * * @Date 2018/11/7 8:45
 **/



import java.util.PriorityQueue;
import java.util.Stack;

public class Palindrome {

    private class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val = x;
        }
    }

    public boolean isPalindrome(ListNode head) {
        boolean res = true;
        Stack<Integer> s = new Stack<>();

        int size = this.getSize(head);
        int halfSize = size / 2;
        ListNode cur = head;

        for (int i = 0; i < halfSize; i++) {
            s.push(cur.val);
            cur = cur.next;
        }

        //如果链表size为奇数时，跳过正中的元素不进行比较
        if (1 == size % 2) {
            cur = cur.next;
        }

        while (null != cur) {
            if (cur.val == s.peek()) {
                s.pop();
                cur = cur.next;
            }else{
                return false;
            }
        }

        return res;
    }

    private int getSize(ListNode head) {
        int size = 0;
        if (null != head) {
            ListNode next = head.next;
            size++;
            while (null != next) {
                size++;
                next = next.next;
            }
        }
        return size;
    }
}
