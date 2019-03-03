package algorithm._021_mergeTwoLists;
/*
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 
ʾ����
	���룺1->2->4, 1->3->4
	�����1->1->2->3->4->4
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

	//˼· : ����һ���µĽڵ����ڷ���,����һ���µĽڵ����ڱ����ı�����ṹ,
	//		����ʱ���ص������ڷ��ص��Ǹ��ڵ����һ���ڵ�,
	//		(���ڸı��ǵ��ýڵ�.next=�ڵ�,���ܽڵ�=�ڵ�,��Ϊ�������ڱ��������������Զûʲô�仯)
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