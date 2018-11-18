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

/** 微信号 :VINO
 *  判断是否成环 用快慢指针
 */


public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null)
        {
        	slow = slow.next;
        	fast = fast.next.next;
        	if(slow == fast)
        		return true;
        }
        return false;

    }
}