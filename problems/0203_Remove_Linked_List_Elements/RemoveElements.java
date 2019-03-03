package algorithm._203_removeElements;

/*
 删除链表中等于给定值 val 的所有节点。
示例:
	输入: 1->2->6->3->4->5->6, val = 6
	输出: 1->2->3->4->5
*/
public class RemoveElements{
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(2);
		head.next.next.next = new ListNode(3);
		head.next.next.next.next = new ListNode(1);
		ListNode index = removeElements(head, 1);
		while (index != null) {
			System.out.println(index.val);
			index = index.next;
		}
	}

	public static ListNode removeElements(ListNode head, int val) {
		//如果head链表的第一个数与val相等则head本身等于其next的节点
		while (head != null && head.val == val) {
			head = head.next;
		}
		//判断head是否为空,为空的情况:1):传进来的就是空链表,2):传进来的链表中的所有元素都于val相等
		if (head == null) {
			return null;
		}
		ListNode index = head;//定义一个index节点来遍历head链表
		//删除链表中与val相等的节点
		while (index.next != null) {
			if (index.next.val == val) {
				index.next = index.next.next;
				continue;
			}
			index = index.next;
		}
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
