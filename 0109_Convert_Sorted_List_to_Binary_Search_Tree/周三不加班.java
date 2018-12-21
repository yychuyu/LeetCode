public TreeNode sortedListToBST(ListNode head) {
	//条件判断
	if(head==null) return null;
	if(head.next == null) return new TreeNode(head.val);
	//快慢指针        
	ListNode fast = head.next.next;
	ListNode slow = head;
	
	while(fast!=null && fast.next!=null){
		fast = fast.next.next;
		slow = slow.next;
	}
	//找到中点以及右边链表的头部      
	ListNode temp = slow.next.next;
	TreeNode root = new TreeNode(slow.next.val);
	//切断      
	slow.next = null;    
	//递归
	root.left = sortedListToBST(head);
	root.right = sortedListToBST(temp);
	
	return root;
}

