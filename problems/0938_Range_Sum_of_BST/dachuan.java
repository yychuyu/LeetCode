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
    private int sum = 0;
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root != null){
            if(root.val >= L && root.val <= R){
                sum += root.val;
            }
            rangeSumBST(root.left, L, R);
            rangeSumBST(root.right, L, R);
        }
        return sum;
    }
}