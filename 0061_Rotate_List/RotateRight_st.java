package algorithm._061_rotateRight;

/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
示例 1:
	输入: 1->2->3->4->5->NULL, k = 2
	输出: 4->5->1->2->3->NULL
解释:
	向右旋转 1 步: 5->1->2->3->4->NULL
	向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:
	输入: 0->1->2->NULL, k = 4
	输出: 2->0->1->NULL
解释:
	向右旋转 1 步: 2->0->1->NULL
	向右旋转 2 步: 1->2->0->NULL
	向右旋转 3 步: 0->1->2->NULL
	向右旋转 4 步: 2->0->1->NULL
*/

public class RotateRight {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		head.next.next.next.next = new ListNode(5);
		head = rotateRight(head, 2);
		while (head != null) {
			System.out.println(head.val);
			head = head.next;
		}
	}

	//思路 : 先遍历链表得到其长度leg,先向右移动k步又等于向左移动leg-k步(k<leg时满足,当k>leg先让k%leg即可)
	//		leg-k即为新链表的头,此时遍历到leg-k-1时即可,定义一个临时节点temp,
	//		让temp存储leg-k-1该节点,令leg-k该节点作为新链表的头节点,再使leg-k-1的下一个节点为next
	public static ListNode rotateRight(ListNode head, int k) {
		if (head == null) {
			return head;
		}
		int leg = 1;
		ListNode index = head;
		while (index.next != null) {
			leg++;
			index = index.next;
		}
		k = k % leg;
		if (k == 0) {
			return head;
		}
		index.next = head;
		for (int i = 0; i < leg - k - 1; i++) {
			head = head.next;
		}
		index = head;
		head = head.next;
		index.next = null;
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