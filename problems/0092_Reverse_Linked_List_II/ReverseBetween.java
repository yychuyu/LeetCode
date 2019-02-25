package algorithm._092_reverseBetween;


/*
 ��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��
˵��:
	1 �� m �� n �� �����ȡ�
ʾ��:
	����: 1->2->3->4->5->NULL, m = 2, n = 4
	���: 1->4->3->2->5->NULL
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
		//��result�ߵ�Ҫ��ʼ���з�ת�Ľڵ����һ���ڵ�
		for(int i = 0;i < m - 2;i ++) {
			result = result.next;
		}
		ListNode beg = result;
		//���m=1��resultû���߶�,���в�����result����һ���ڵ㿪ʼ���з�ת
		//���m=2��Ȼresultû���߶�,����������һ���ڵ�պ�ΪҪ���з�ת�Ľڵ�,���п��԰�result��������0��
		if(m != 1) {
			result = result.next;
		}
		ListNode end = result;
		ListNode temp = result;
		ListNode pre = null;
		//���з�ת
		for(int i = 0;i < n - m + 1;i ++) {
			temp = result.next;
			result.next = pre;
			pre = result;
			result = temp;
		}
		//��Ҫ���з�ת��ǰһ���ڵ��뷴ת��ĵ�һ���ڵ�����
		beg.next = pre;
		//����ת������һ���ڵ���Ҫ���з�ת�ĺ�һ���ڵ�����
		end.next = result;
		//���m = 1��head��ͷ�ڵ���Ҫ�ı�Ϊ��ת��ĵ�һ���ڵ�
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