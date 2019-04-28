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
    ListNode re = result;
    if (l1 == null && l2 == null){
        return null;
    }
    while (l1 != null || l2 != null){  
        if ( l1 == null ) {
            while (l2 != null){
                result.val = l2.val;
                l2 = l2.next;
                if (l2 == null){
                    result.next = null;
                } else {
                    result.next = new ListNode(0);
                    result = result.next;
                }
            }
            break;
        }
        if ( l2 == null ) {
            while (l1 != null){
                result.val = l1.val;
                l1 = l1.next;
                if (l1 == null){
                    result.next = null;
                } else {
                    result.next = new ListNode(0);
                    result = result.next;
                }
            }
            break;
        }             
        if (l1.val <= l2.val) {
            // 将小值放入结果队列，该队列 和 结果队列 指向下一个节点
            result.val = l1.val;
            l1 = l1.next;
            result.next = new ListNode(0);
            result = result.next;
            continue;
        } else {
            result.val = l2.val;
            l2 = l2.next;
            result.next = new ListNode(0);
            result = result.next;
            continue;
        }
    }
    return re;
}
}