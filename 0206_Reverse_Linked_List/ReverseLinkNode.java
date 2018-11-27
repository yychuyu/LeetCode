package cn.plummy;
/**
 * ������ת(�����еĽڵ�ָ����һ���ڵ�)
 * 1.�������Ľڵ�û����һ���ڵ�ʱ����Ϊͷ�ڵ�(β���--->ͷ�ڵ�)
 * 2.��תʱ,����ĵ�һ���ڵ�ָ��null(ͷ���--->β�ڵ�)
 * @author lilin
 *
 */
public class ReverseLinkNode {
	
	public ListNode reverseList(ListNode head) {
		ListNode previousNode = null;
		ListNode currentNode = head;
		ListNode headNode = null;
		while (currentNode != null) {	//�ڵ㲻Ϊ��
			ListNode nextNode = currentNode.next;//��¼ָ��Ľڵ�
			if (nextNode == null) {//��������һ���ڵ�
				headNode = currentNode;//��ǰ�ڵ�Ϊ��ת���ͷ�ڵ�
			}
			currentNode.next = previousNode;//��ǰ�ڵ�ָ����һ���ڵ�
			previousNode = currentNode;
			currentNode = nextNode;
		}
		return headNode;
	}

	public static int[] stringToIntegerArray(String input) {
		input = input.trim();
		input = input.substring(1, input.length() - 1);
		if (input.length() == 0) {
			return new int[0];
		}

		String[] parts = input.split(",");
		int[] output = new int[parts.length];
		for (int index = 0; index < parts.length; index++) {
			String part = parts[index].trim();
			output[index] = Integer.parseInt(part);
		}
		return output;
	}

	public static ListNode stringToListNode(String input) {
		// Generate array from the input
		int[] nodeValues = stringToIntegerArray(input);

		// Now convert that list into linked list
		ListNode dummyRoot = new ListNode(0);
		ListNode ptr = dummyRoot;
		for (int item : nodeValues) {
			ptr.next = new ListNode(item);
			ptr = ptr.next;
		}
		return dummyRoot.next;
	}

	public static String listNodeToString(ListNode node) {
		if (node == null) {
			return "[]";
		}

		String result = "";
		while (node != null) {
			result += Integer.toString(node.val) + ", ";
			node = node.next;
		}
		return "[" + result.substring(0, result.length() - 2) + "]";
	}

}