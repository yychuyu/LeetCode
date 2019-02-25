package algorithm._142_detectCycle;


public class DetectCycle {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		head.next.next.next.next = head.next;
		ListNode index = detectCycle(head);
		while (index != null) {
			System.out.println(index.val);
			index = index.next;
		}
	}

	public static ListNode detectCycle(ListNode head) {
		ListNode result = head;
		ListNode index = head;
		//���ÿ���ָ���ж��Ƿ��л�
		while(index != null && index.next != null) {
			result = result.next;
			index = index.next.next;
			if(result == index) {
				break;
			}
		}
		if(index == null || index.next ==null) {
			return null;
		}
		//�ٰ�����һ��ָ��ָ��head,Ȼ������ָ�붼һ��һ����,��һ������ʱ��Ϊ���뻷�ĵ�һ���ڵ�
		//ԭ��:��Ϊһ��ʼ��ָ���ߵ�����ָ�������,��head��һ��ʼ�����Ľڵ���ǻ����ȵ�n��
		//	      �����ٴ�head��ʼ�ߵ�ָ��ض����ڵ�һ�������Ľڵ���index����
		// 	      ������Ϊ����ָ����ٶ�һ��,���е����������Ľڵ㼴Ϊ����ʼ�Ľڵ�
		result = head;
		while(result != index) {
			result = result.next;
			index = index.next;
		}
		return result;

	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}