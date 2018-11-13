package algorithm._141_hasCycle;

/*
给定一个链表，判断链表中是否有环。
	进阶：你能否不使用额外空间解决此题？
*/
public class HasCycle {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(2);
		head.next.next.next = head.next.next;
		System.out.println(hasCycle(head));
	}

	//我的思路...:判断当前节点的下一个节点有没有在该节点之前出现过,有则代表该链表有环
	public static boolean hasCycle(ListNode head) {
		if (head == null) {
			return false;
		}
		ListNode result = head;
		ListNode index = null;
		//判断result当前节点的下一个节点是否在result节点之前出现过,出现则表明head链表中有环链表
		while (result.next != null) {
			index = head;
			if (result == result.next) {
				return true;
			}
			while (index != result) {
				if (index == result.next) {
					return true;
				}
				index = index.next;
			}
			result = result.next;
		}
		return false;
	}

	//大佬的思路:用快慢指针的方法,如果有环则快指针会追上慢指针
	public static boolean hasCycle1(ListNode head) {
		ListNode index = head;
		while(index != null && index.next != null) {
			head = head.next;
			index = index.next.next;
			if(head == index) {
				return true;
			}
		}
		return false;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
