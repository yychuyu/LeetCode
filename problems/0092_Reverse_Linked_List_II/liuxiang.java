/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

//解题思路，首先这题和整个链表翻转不同，链表的翻转用迭代比较好，这个地方需要先找到要翻转的第m个节点，并且存储第m个节点已经他的前后节点，然后从第m个节点到第n个节点开始翻转，反转过后的第m个节点的next为null，我们要指定m.next=m的前节点，原来m的后节点的next为第n个节点，这样就翻转完毕，返回头节点。
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
       if(head==null||head.next==null)return head;
		if (m == n || m > n) return head;
		ListNode start=null;
		ListNode end=null;
		ListNode temp=null;
		ListNode cur=head;
		ListNode pre=null;
		
		if(m>1) {
			for(int i=1;i<m;i++) {
				start=cur;		//存储m节点的前一个节点
				cur=cur.next;
				end=cur;		//存储第m个节点
			}
		}
		
		for(int i=m;i<=n;i++) {
			temp=cur.next;
			cur.next=pre;
			pre=cur;
			cur=temp;
      }
        
     if (m==1) {
        head.next = cur;
        return pre;
    }
		
		start.next=pre;
		end.next=cur;
		return head;
    }
}
