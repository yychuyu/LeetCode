/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
		//  0个节点 ||  1个节点
		if (head == null || head.next == null)  
			return head;
		//  >= 2个节点
		ListNode first = head, second = null, mid = getMid(head);
		second = mid.next;
		mid.next = null;  //将链表分为两段！！！！
		//递归
		first = sortList(first);
		second = sortList(second);
		return merge(first, second);
	}
 
	//排序
	ListNode merge(ListNode first, ListNode second) {
		if (first == null)
			return second;
		if (second == null)
			return first;
		
		ListNode res = new ListNode(0);
		ListNode curr = res;//控制新链表顺序的point
 
		while (first != null && second != null) {
			if (first.val < second.val) {
				curr.next = first;
				curr = curr.next;
				first = first.next;
			} else {
				curr.next = second;
				curr = curr.next;
				second = second.next;
			}
		}
 
		if (first != null)
			curr.next = first;
		if (second != null)
			curr.next = second;
		
		return res.next;
	}
	
	//将链表平分为两段，返回第一段末尾   例如：5个点返回2号点，6个点返回3号点
	ListNode getMid(ListNode head) {
		ListNode slow = head, fast = head.next;
		
		while (fast!=null&&fast.next!=null) {
			slow=slow.next;
			fast=fast.next.next;
		}
		
		return slow;
	}
}
