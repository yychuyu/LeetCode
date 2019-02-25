package algorithm._061_rotateRight;

/*
����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����
ʾ�� 1:
	����: 1->2->3->4->5->NULL, k = 2
	���: 4->5->1->2->3->NULL
����:
	������ת 1 ��: 5->1->2->3->4->NULL
	������ת 2 ��: 4->5->1->2->3->NULL
ʾ�� 2:
	����: 0->1->2->NULL, k = 4
	���: 2->0->1->NULL
����:
	������ת 1 ��: 2->0->1->NULL
	������ת 2 ��: 1->2->0->NULL
	������ת 3 ��: 0->1->2->NULL
	������ת 4 ��: 2->0->1->NULL
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

	//˼· : �ȱ�������õ��䳤��leg,�������ƶ�k���ֵ��������ƶ�leg-k��(k<legʱ����,��k>leg����k%leg����)
	//		leg-k��Ϊ�������ͷ,��ʱ������leg-k-1ʱ����,����һ����ʱ�ڵ�temp,
	//		��temp�洢leg-k-1�ýڵ�,��leg-k�ýڵ���Ϊ�������ͷ�ڵ�,��ʹleg-k-1����һ���ڵ�Ϊnext
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