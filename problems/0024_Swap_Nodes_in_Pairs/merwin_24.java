/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode result = head.next;
        ListNode pre = new ListNode(0);
        ListNode cur,next;
        pre.next = head;
        cur = head;
        while(cur != null && cur.next != null){
            next = cur.next;
            cur.next = next.next;
            next.next = cur;
            pre.next = next;
            pre = cur;
            cur = cur.next;
        }
        return result;
    }
}