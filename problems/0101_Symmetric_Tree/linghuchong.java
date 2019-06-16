//令狐冲的解法

public class Solution {
    /**
     * @param root: root of the given tree
     * @return: whether it is a mirror of itself 
     */
    public boolean isSymmetric(TreeNode root) {
        // Write your code here
        return root==null || isSymmetricHelp(root.left, root.right);
    }
    
    private boolean isSymmetricHelp(TreeNode left, TreeNode right) {
        if (left==null || right==null) {
            return left == right;
        }
        if (left.val != right.val) {
            return false;
        }
        return isSymmetricHelp(left.left, right.right) && isSymmetricHelp(left.right, right.left);
    }
}