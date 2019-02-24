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
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }
        
        ListNode i = l1, j = l2, l3 = null, p = l3;
        while (i != null && j != null) {
            if (i.val <= j.val) {
                if (l3 == null) {
                    l3 = new ListNode(i.val);
                    p = l3;
                } else {
                    p.next = new ListNode(i.val);
                    p = p.next;                    
                }
                i = i.next;
            } else {
                if (l3 == null) {
                    l3 = new ListNode(j.val);
                    p = l3;
                } else {
                    p.next = new ListNode(j.val);
                    p = p.next;                    
                }
                j = j.next;
            }
        }
        while (i != null) {
            p.next = new ListNode(i.val);
            p = p.next;
            i = i.next;
        }
        while (j != null) {
            p.next = new ListNode(j.val);
            p = p.next;
            j = j.next;
        }
        return l3;
    }
}
