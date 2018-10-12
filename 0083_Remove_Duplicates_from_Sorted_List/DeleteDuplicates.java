package algorithm._083_deleteDuplicates;

/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
示例 1:
	输入: 1->1->2
	输出: 1->2
示例 2:
	输入: 1->1->2->3->3
	输出: 1->2->3
*/
public class DeleteDuplicates {
	public class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
		}
	}

	public ListNode deleteDuplicates(ListNode head) {
		if (head == null) {
			return null;
		}
		ListNode temp = head;//定义一个temp引用head的地址,用于return后所返回的是head的第一个节点
		while (head.next != null) {
			if (head.val == head.next.val) {
				head.next = head.next.next;
			} else {
				head = head.next;
			}
		}
		return temp;
	}
}
