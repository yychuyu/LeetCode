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
    public boolean isSymmetric(TreeNode root) {
        return isSame(root, root);
		//下边的写法，没有上边巧妙；
//		if(root == null){
//			return true;
//		}else{
//			return isSame(root.left, root.right);
//		}
	}
	
	public boolean isSame(TreeNode node1, TreeNode node2){
		if(node1 == null && node2 == null){
			return true;
		}else if(node1 == null || node2 == null){
			return false;
		}else{
			return node1.val == node2.val && isSame(node1.left, node2.right) && isSame(node1.right, node2.left);
		}
    }
}