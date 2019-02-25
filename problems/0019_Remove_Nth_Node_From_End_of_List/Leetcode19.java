package leetcode;

class ListNode {
	int val;
	ListNode  next;
	public ListNode(int x) {
		// TODO Auto-generated constructor stub
		val = x;
	}
}

public class Leetcode19 {
		public static void main(String[] args) {
			
			
		}
		public ListNode removeNthFromEnd(ListNode head, int n) {
			int length = 1;
			int count = 0;
			ListNode slow;
			ListNode fast;
			slow = head;
			fast = head;
			// 求链表长度
			while (slow.next != null) {
				length++;
				slow = slow.next;
			}
			if (n == length) {
				head = head.next;
			}
			while (fast.next != null) {
				count++;
				if (count == length - n) {
					fast.next = fast.next.next;
					return head;
				}
				fast = fast.next;
			}
			return head;
		}
}
