/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy.next;
        ListNode pCur = prev.next;
        while (pCur != null) {
            prev.next = pCur.next;
            pCur.next = dummy.next;
            dummy.next = pCur;
            pCur = prev.next;
        }
        return dummy.next;
    }
}
