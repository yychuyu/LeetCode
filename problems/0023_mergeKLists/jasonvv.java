/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode tem = null;
        for (int i = 0; i < lists.length; i++) {
            tem = mergeTwoLists(tem, lists[i]);
        }
        return tem;
    }
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode res = new ListNode(0);
        ListNode now = res;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                now.next = l1;
                now = now.next;
                l1 = l1.next;
            } else {
                now.next = l2;
                now = now.next;
                l2 = l2.next;
            }
        }
        while(l1 != null) {
            now.next = l1;
            now = now.next;
            l1 = l1.next;
        }
        while(l2 != null) {
            now.next = l2;
            now = now.next;
            l2 = l2.next;
        }
        return res.next;
    }
}
