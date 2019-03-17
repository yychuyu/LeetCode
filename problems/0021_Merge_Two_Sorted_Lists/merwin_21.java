/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode head = result;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                result.next = l1;
                l1 = l1.next;
            } else {
                result.next = l2;
                l2 = l2.next;
            }
            result = result.next; //这一步别漏了
        }
        if(l1 == null){
            result.next = l2;
        }
        if(l2 == null){
            result.next = l1;
        }
        return head.next;
    }
}