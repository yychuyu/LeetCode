/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
	 public TreeNode sortedListToBST(ListNode head) {
		 if( head==null ) return null;
		 if( head.next==null ) return new TreeNode(head.val);
		 ListNode slow = head;
		 ListNode fast = head;
		 ListNode premid = null;
		 while( fast!=null && fast.next!=null ) {
			 premid = slow;
			 slow = slow.next;
			 fast = fast.next.next;
		 }
		 premid.next = null;
		 TreeNode root = new TreeNode(slow.val);
		 root.left = sortedListToBST(head);
		 root.right = sortedListToBST(slow.next);
		 return root;
	 }
}
