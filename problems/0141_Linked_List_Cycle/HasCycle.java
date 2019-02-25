package algorithm._141_hasCycle;

/*
����һ�������ж��������Ƿ��л���
	���ף����ܷ�ʹ�ö���ռ������⣿
*/
public class HasCycle {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(2);
		head.next.next.next = head.next.next;
		System.out.println(hasCycle(head));
	}

	//�ҵ�˼·...:�жϵ�ǰ�ڵ����һ���ڵ���û���ڸýڵ�֮ǰ���ֹ�,�������������л�
	public static boolean hasCycle(ListNode head) {
		if (head == null) {
			return false;
		}
		ListNode result = head;
		ListNode index = null;
		//�ж�result��ǰ�ڵ����һ���ڵ��Ƿ���result�ڵ�֮ǰ���ֹ�,���������head�������л�����
		while (result.next != null) {
			index = head;
			if (result == result.next) {
				return true;
			}
			while (index != result) {
				if (index == result.next) {
					return true;
				}
				index = index.next;
			}
			result = result.next;
		}
		return false;
	}

	//���е�˼·:�ÿ���ָ��ķ���,����л����ָ���׷����ָ��
	public static boolean hasCycle1(ListNode head) {
		ListNode index = head;
		while(index != null && index.next != null) {
			head = head.next;
			index = index.next.next;
			if(head == index) {
				return true;
			}
		}
		return false;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
