class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        ArrayList<Integer> list=new ArrayList<>();
        while(head!=null){
        	list.add(head.val);
        	head=head.next;
        }
        return build(list,0,list.size()-1);
    }
    private TreeNode build(ArrayList<Integer> nums,int head,int tail){
		if(head<tail){
			int index=(head+tail+1)/2;
			TreeNode root=new TreeNode(nums.get(index));
			root.left=build(nums,head,index-1);
			root.right=build(nums,index+1,tail);
			return root;
		}
		else if(head>tail){
			return null;
		}else{
			return new TreeNode(nums.get(head));
		}	
	}

}
