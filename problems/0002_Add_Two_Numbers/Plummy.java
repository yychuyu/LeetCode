package cn.plummy;
/**
 * 单链表反转(即所有的节点指向上一个节点)
 * 1.当遍历的节点没有下一个节点时，作为头节点(尾结点--->头节点)
 * 2.反转时,链表的第一个节点指向null(头结点--->尾节点)
 * @author lilin
 *
 */
public class Plummy {

	public static void main(String[] args) throws IOException {
		ListNode lnx = ReverseLinkNode.stringToListNode("[2,4,3,1]");
		ListNode lny = ReverseLinkNode.stringToListNode("[5,6,4,9]");

		ListNode res = addTwoNumbers(lnx, lny);

		String out = ReverseLinkNode.listNodeToString(res);
		System.out.print(out);

	}

	public static ListNode addTwoNumbers(ListNode lnx, ListNode lny) {

		// 存放和的链表
		ListNode resListNode = null;
		// 存放lnx的下一个节点
		ListNode nextListNodeX = lnx;
		// 存放lny的下一个节点
		ListNode nextListNodeY = lny;
		
		ListNode tempNode = null;
		
		int temp = 0;
		int val;

		while (nextListNodeX != null || nextListNodeY != null) {
			
			
			// 第一个值相加
			int x = nextListNodeX != null ? nextListNodeX.val : 0;
			int y = nextListNodeY != null ? nextListNodeY.val : 0;
			val = (x + y >= 10) ? (x + y) % 10 : (x + y);
			ListNode newListNode = new ListNode(val + temp);
			if(resListNode == null){
				resListNode = newListNode;
				tempNode = resListNode;
			}else{
				tempNode.next = newListNode;
				tempNode = tempNode.next;
			}
			
			temp = (x + y >= 10) ? 1 : 0;
			nextListNodeX = nextListNodeX !=null ? nextListNodeX.next : null;
			nextListNodeY = nextListNodeY != null ? nextListNodeY.next :null;
			
			if(temp != 0 && nextListNodeX == null && nextListNodeY == null ){
				 newListNode = new ListNode(temp);
				 tempNode.next = newListNode;
				 tempNode = tempNode.next;
			}
		}

		return resListNode;
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