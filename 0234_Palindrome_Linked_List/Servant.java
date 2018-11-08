package algorithm._234_isPalindrome;

/*
请判断一个链表是否为回文链表。
示例 1:
	输入: 1->2
	输出: false
示例 2:
	输入: 1->2->2->1
	输出: true
进阶：
	你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
		ListNode result = head;//用来反转后半部分链表
		ListNode index = head;//用来遍历链表
		//当index遍历结束后,result正好到中间,正好到后半部分需要反转的链表的开头
		while (index != null && index.next != null) {
			result = result.next;
			index = index.next.next;
		}
		ListNode pre = null;
		ListNode temp;//存储临时节点,确保result.next断掉之后还能继续遍历
		//反转后半部分链表
		while (result != null) {
			temp = result.next;
			result.next = pre;
			pre = result;
			if (temp == null)
				break;
			result = temp;
		}
		//遍历反转后的后半部分链表与原链表的前半部分是否相等要判断该链表是否为回文链表
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
