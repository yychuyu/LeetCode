/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/**
*解题思路：  判断是不是对称的二叉树，首先判断是不是空的二叉树或者是不是左右子树都是空的 如果是这样那就返回true。如果不是那就判断是不是只有左子树或者只有右子树为空，如果是那说明不对称，返回FALSE，如果还不是那就分析对称的含义，对称要求根节点的左边节点等于右边节点，且左节点的左节点和右节点的右节点相等，左节点的右节点和右节点的左节点相等，一直循环到不是空为止。
*
*/


class Solution {
    public boolean isSymmetric(TreeNode root) {
		 if(root==null||(root.left==null&&root.right==null)) return true;
		 return isMirror(root.left,root.right);
		 
	 }
	 
	 private boolean isMirror(TreeNode left, TreeNode right) {
		 if(left==null&&right==null)return true;
		 if(left==null||right==null)return false;
		 return (left.val==right.val)&&(isMirror(left.left,right.right))&&(isMirror(left.right,right.left));
         }
}
