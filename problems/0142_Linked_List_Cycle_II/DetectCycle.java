package algorithm._142_detectCycle;


public class DetectCycle {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		head.next.next.next.next = head.next;
		ListNode index = detectCycle(head);
		while (index != null) {
			System.out.println(index.val);
			index = index.next;
		}
	}

	public static ListNode detectCycle(ListNode head) {
		ListNode result = head;
		ListNode index = head;
		//先用快慢指针判断是否有环
		while(index != null && index.next != null) {
			result = result.next;
			index = index.next.next;
			if(result == index) {
				break;
			}
		}
		if(index == null || index.next ==null) {
			return null;
		}
		//再把其中一个指针指向head,然后两个指针都一步一步走,第一次相遇时即为进入环的第一个节点
		//原因:因为一开始快指针走的是慢指针的两倍,即head到一开始相遇的节点会是环长度的n倍
		//	      所有再从head开始走的指针必定会在第一次相遇的节点与index相遇
		// 	      但是因为两个指针的速度一样,所有当它们相遇的节点即为环开始的节点
		result = head;
		while(result != index) {
			result = result.next;
			index = index.next;
		}
		return result;

	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}