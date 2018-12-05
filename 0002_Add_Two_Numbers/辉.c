//This file is added by 2345oo5432 

class ListNode {
	int val;
	ListNode next;
	
	public ListNode(int x) { val = x; }
}


public class AddTwoNumbers {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		if (l1 == null) { return l2; }
		if (l2 == null) { return l1; }
        ListNode tempNode = new ListNode(0);
		ListNode head = tempNode;
		int carry = 0, sum;
		
		while (l1 != null || l2 != null) {
			int x = (l1 == null) ? 0 : l1.val;
			int y = (l2 == null) ? 0 : l2.val;
			
			// 加和以及进位
            sum = x + y + carry;
            tempNode.val = (sum < 10) ? sum : (sum - 10);
            carry = (sum < 10) ? 0 : 1;
			
            // l1, l2向下移动
			if (l1 != null) { l1 = l1.next; }
			if (l2 != null) { l2 = l2.next; }
            
            // tempNode向下移动
            if (l1 != null || l2 != null || carry !=0) {
                tempNode.next = new ListNode(0);
                tempNode = tempNode.next;
            }
		}
		
		if (carry != 0) { tempNode.val = carry; }
		return head; 
    }
	
	// 测试程序
	public static void main(String[] args) {
		ListNode l1 = new ListNode(1);

		ListNode l2 = new ListNode(9);
		l2.next = new ListNode(9);
		
		AddTwoNumbers obj = new AddTwoNumbers();
		ListNode node = obj.addTwoNumbers(l1, l2);
		
		while (node != null) {
			System.out.println(node.val);
			node = node.next;
		}
	}
