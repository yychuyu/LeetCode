package algorithm._019_removeNthFromEnd;

/*
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
ʾ����
	����һ������: 1->2->3->4->5, �� n = 2.
	��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����
	������ n ��֤����Ч�ġ�
���ף�
	���ܳ���ʹ��һ��ɨ��ʵ����
*/
public class RemoveNthFromEnd {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		ListNode index = removeNthFromEnd(head, 2);
		while (index != null) {
			System.out.println(index.val);
			index = index.next;
		}
	}

	public static ListNode removeNthFromEnd(ListNode head, int n) {
		//���������ֻ��һ���ڵ�,��ɾ����϶�Ϊnull
		if (head.next == null) {
			return null;
		}
		ListNode index = head;
		ListNode result = head;
		//����index����n��,ʹresult��index��n��֮��
		for (int i = 0; i < n; i++) {
			index = index.next;
		}
		//���index == null,��˵��Ҫɾ���Ľڵ�Ϊ��һ���ڵ�
		if (index == null) {
			head = head.next;
			return head;
		}
		//��index.next == null ʱ,��result����һ���ڵ㼴Ϊɾ���ڵ�
		while (index.next != null) {
			result = result.next;
			index = index.next;
		}
		result.next = result.next.next;
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
