package algorithm._092_reverseBetween;


/*
 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
	1 ≤ m ≤ n ≤ 链表长度。
示例:
	输入: 1->2->3->4->5->NULL, m = 2, n = 4
	输出: 1->4->3->2->5->NULL
*/
public class ReverseBetween {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		head.next.next.next.next = new ListNode(5);
		ListNode index = reverseBetween(head, 2,4);
		while (index != null) {
			System.out.println(index.val);
			index = index.next;
		}
	}

	public static ListNode reverseBetween(ListNode head, int m, int n) {
		ListNode result = head;
		//让result走到要开始进行反转的节点的上一个节点
		for(int i = 0;i < m - 2;i ++) {
			result = result.next;
		}
		ListNode beg = result;
		//如果m=1则result没有走动,所有不再是result的下一个节点开始进行反转
		//如果m=2虽然result没有走动,但是它的下一个节点刚好为要进行反转的节点,所有可以把result看成走了0步
		if(m != 1) {
			result = result.next;
		}
		ListNode end = result;
		ListNode temp = result;
		ListNode pre = null;
		//进行反转
		for(int i = 0;i < n - m + 1;i ++) {
			temp = result.next;
			result.next = pre;
			pre = result;
			result = temp;
		}
		//将要进行反转的前一个节点与反转后的第一个节点连接
		beg.next = pre;
		//将反转后的最后一个节点与要进行反转的后一个节点连接
		end.next = result;
		//如果m = 1则head的头节点需要改变为反转后的第一个节点
		if(m == 1) {
			head = pre;
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