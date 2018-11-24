/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */


/**
 *	微信号: VINO
 *	先判断是否成环，记录快慢指针第一次相遇时将慢指针归head处 
 *  快慢指针在环内一定会相遇且相遇点只能是环入口，否则俩指针速度一样，在环内永不可能相遇
 *
 */

public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null)
        {
        	slow = slow.next;
        	fast = fast.next.next;
        	if(slow == fast)
        		break;
        }
        
        if(fast == null || fast.next == null)
        	return null;
        
        slow = head;//慢指针重新归位头指针处
        while(slow != fast)
        {
        	slow = slow.next;
        	fast = fast.next;
        }
        return slow;
    }
}