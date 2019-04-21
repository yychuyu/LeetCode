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
    public String tree2str(TreeNode t) {
        String s = this.preorder(t);
        return s;
    }
    private boolean noleft(TreeNode t) {
        if (t.left == null && t.right != null) return true;
        else return false;
    }
    private String preorder(TreeNode t) {
        //use flag.
        if (t == null) {
            return "";
        }
        String s =  ""+t.val;
        if ((noleft(t)) || 
            (t.left != null && !noleft(t))) s += "("+preorder(t.left)+")";
        if ((noleft(t)) || 
            (t.right != null && !noleft(t))) s += "("+preorder(t.right)+")";
        return s;
    }
}
