package algorithm._021_mergeTwoLists;
/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例：
	输入：1->2->4, 1->3->4
	输出：1->1->2->3->4->4
*/

public class MergeTwoLists {
	public static void main(String[] args) {
		ListNode l1 = new ListNode(1);
		l1.next = new ListNode(3);
		l1.next.next = new ListNode(5);
		ListNode l2 = new ListNode(2);
		l2.next = new ListNode(4);
		l2.next.next = new ListNode(6);
		ListNode list = mergeTwoLists(l1, l2);
		while (list != null) {
			System.out.println(list.val);
			list = list.next;
		}

	}

	//思路 : 定义一个新的节点用于返回,定义一个新的节点用于遍历改变链表结构,
	//		返回时返回的是用于返回的那个节点的下一个节点,
	//		(用于改变是得用节点.next=节点,不能节点=节点,因为还用用于遍历如果这样则永远没什么变化)
	public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		if (l1 == null && l2 == null) {
			return null;
		} else if (l1 == null) {
			return l2;
		} else if (l2 == null) {
			return l1;
		}
		ListNode result = new ListNode(0);
		ListNode temp = result;
		while (l1 != null && l2 != null) {
			if (l1.val > l2.val) {
				temp.next = l2;
				temp = temp.next;
				l2 = l2.next;
			} else {
				temp.next = l1;
				temp = temp.next;
				l1 = l1.next;
			}
		}
		if (l1 != null) {
			temp.next = l1;
		} else {
			temp.next = l2;
		}
		return result.next;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}