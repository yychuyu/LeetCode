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
    public boolean isUnivalTree(TreeNode root) {
      int val = root.val;
        boolean result =false;
        return perform(val, root);
    }

    public boolean perform(int num, TreeNode node) {
        if (node != null) {
            return num == node.val && perform(num, node.left) && perform(num, node.right);
        }
        return true;
    }
}