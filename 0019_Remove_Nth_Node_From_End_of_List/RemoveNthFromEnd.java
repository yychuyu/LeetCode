package algorithm._019_removeNthFromEnd;

/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
	给定一个链表: 1->2->3->4->5, 和 n = 2.
	当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：
	给定的 n 保证是有效的。
进阶：
	你能尝试使用一趟扫描实现吗？
*/
public class RemoveNthFromEnd {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		ListNode index = removeNthFromEnd(head, 2);
		while (index != null) {
			System.out.println(index.val);
			index = index.next;
		}
	}

	public static ListNode removeNthFromEnd(ListNode head, int n) {
		//如果该链表只有一个节点,那删除后肯定为null
		if (head.next == null) {
			return null;
		}
		ListNode index = head;
		ListNode result = head;
		//先让index先走n步,使result与index有n步之差
		for (int i = 0; i < n; i++) {
			index = index.next;
		}
		//如果index == null,则说明要删除的节点为第一个节点
		if (index == null) {
			head = head.next;
			return head;
		}
		//当index.next == null 时,则result的下一个节点即为删除节点
		while (index.next != null) {
			result = result.next;
			index = index.next;
		}
		result.next = result.next.next;
		return head;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
