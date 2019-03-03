package algorithm._083_deleteDuplicates;

/*
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
ʾ�� 1:
	����: 1->1->2
	���: 1->2
ʾ�� 2:
	����: 1->1->2->3->3
	���: 1->2->3
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
		ListNode temp = head;//����һ��temp����head�ĵ�ַ,����return�������ص���head�ĵ�һ���ڵ�
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
