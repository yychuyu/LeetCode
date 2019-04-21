
//目的：计算出这样移动之后的带头大哥
//为了可以做到单链表有循环接上之前头节点的功能
//设置了一个虚拟头节点，一个暂存节点（用来表达最后的头节点落在了哪里）
//所以设置了三个节点


//官方一些的说法
*本质只需要找到这个链表的倒数第k个元素*
然后将从第K个元素开始的所有节点都移到链表的开头即可


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution{
	private int getLength(ListNode head){
		int length = 0;
		while (head != null){
			length++;
			head = head.next;
		}
	return length;
	}

	public ListNode rotateRight(ListNode head, int n){
		if (head == null) {
			return null;
		}
		int length = getLength(head);
		n = n % length;
		ListNode dummy = new ListNode(0);
		dummy.next = head;
		head= dummy;

		ListNode tail = dummy;
		for (int i =0;i < n ; i++ ) {
			head = head.next;
		}
		while(head.next != null){
			tail = tail.next;
			head = head.next;
		}
		head.next = dummy.next;
		dummy.next = tail.next;
		tail.next = null;
		return dummy.next;

	}
}
