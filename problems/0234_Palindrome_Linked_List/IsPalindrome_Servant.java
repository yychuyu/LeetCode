package algorithm._234_isPalindrome;

/*
���ж�һ�������Ƿ�Ϊ��������
ʾ�� 1:
	����: 1->2
	���: false
ʾ�� 2:
	����: 1->2->2->1
	���: true
���ף�
	���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿
*/
public class Servant{
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(2);
		head.next.next.next = new ListNode(1);
		System.out.println(isPalindrome(head));
	}

	public static boolean isPalindrome(ListNode head) {
		ListNode result = head;//������ת��벿������
		ListNode index = head;//������������
		//��index����������,result���õ��м�,���õ���벿����Ҫ��ת������Ŀ�ͷ
		while (index != null && index.next != null) {
			result = result.next;
			index = index.next.next;
		}
		ListNode pre = null;
		ListNode temp;//�洢��ʱ�ڵ�,ȷ��result.next�ϵ�֮���ܼ�������
		//��ת��벿������
		while (result != null) {
			temp = result.next;
			result.next = pre;
			pre = result;
			if (temp == null)
				break;
			result = temp;
		}
		//������ת��ĺ�벿��������ԭ�����ǰ�벿���Ƿ����Ҫ�жϸ������Ƿ�Ϊ��������
		while (result != null) {
			if (result.val != head.val) {
				return false;
			}
			result = result.next;
			head = head.next;
		}
		return true;
	}

}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
