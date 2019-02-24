package cn.plummy;
/**
 * 单链表反转(即所有的节点指向上一个节点)
 * 1.当遍历的节点没有下一个节点时，作为头节点(尾结点--->头节点)
 * 2.反转时,链表的第一个节点指向null(头结点--->尾节点)
 * @author lilin
 *
 */
public class ReverseLinkNode {
	
	public ListNode reverseList(ListNode head) {
		ListNode previousNode = null;
		ListNode currentNode = head;
		ListNode headNode = null;
		while (currentNode != null) {	//节点不为空
			ListNode nextNode = currentNode.next;//记录指向的节点
			if (nextNode == null) {//链表的最后一个节点
				headNode = currentNode;//当前节点为反转后的头节点
			}
			currentNode.next = previousNode;//当前节点指向上一个节点
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