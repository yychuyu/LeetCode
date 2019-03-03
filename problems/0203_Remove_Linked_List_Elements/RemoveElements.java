package algorithm._203_removeElements;

/*
 ɾ�������е��ڸ���ֵ val �����нڵ㡣
ʾ��:
	����: 1->2->6->3->4->5->6, val = 6
	���: 1->2->3->4->5
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
		//���head����ĵ�һ������val�����head���������next�Ľڵ�
		while (head != null && head.val == val) {
			head = head.next;
		}
		//�ж�head�Ƿ�Ϊ��,Ϊ�յ����:1):�������ľ��ǿ�����,2):�������������е�����Ԫ�ض���val���
		if (head == null) {
			return null;
		}
		ListNode index = head;//����һ��index�ڵ�������head����
		//ɾ����������val��ȵĽڵ�
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
