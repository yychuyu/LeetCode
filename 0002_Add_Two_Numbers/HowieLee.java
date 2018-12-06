import java.util.Arrays;

/**
 * @description: add-two-numbers
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 * @author: Howie Lee
 * @create: 2018-11-18 00:44
 **/
public class HowieLee {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return helper(l1,l2,0);
    }

    public ListNode helper(ListNode l1, ListNode l2, int carry){
        if(l1==null && l2==null){
            return carry == 0? null : new ListNode(carry);
        }
        if(l1==null && l2!=null){
            l1 = new ListNode(0);
        }
        if(l2==null && l1!=null){
            l2 = new ListNode(0);
        }
        int sum = l1.val + l2.val + carry;
        ListNode curr = new ListNode(sum % 10);
        curr.next = helper(l1.next, l2.next, sum / 10);
        return curr;
    }

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
        }
    }

}
