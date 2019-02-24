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
        if( root==null ) return true;
        else{
            return dfs(root.left, root.right);   
        }
    }
    
    public boolean dfs(TreeNode left, TreeNode right) {
        
    	if( left==null && right==null ) {
    		return true;
    	}else if( left!=null && right!=null ) {
			if( left.val!=right.val ) {
				return false;
			}
		}else{
            return false;
        }
    	return (dfs(left.left, right.right) && dfs(left.right, right.left));
    }
    
}
