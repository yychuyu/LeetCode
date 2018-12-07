package leetcode_101;

/**
 * 给定一个二叉树，检查它是否是镜像对称的。
 */
public class Solution {
    //需满足下列两个条件：
    //它们的两个根结点具有相同的值。
    //每个树的右子树都与另一个树的左子树镜像对称。
    public boolean isSymmetric(TreeNode root) {
        if (root==null) return true;//条件都符合，已经没有下一个，直接返回
        return check(root,root);
    }
    public boolean check(TreeNode left,TreeNode right){
        if (left==null&&right==null)return true;
        if (left==null||right==null)return false;//如果只有一个为null就返回false
        return (left.val==right.val)&&check(left.left,right.right)&&check(left.right,right.left);
    }

}
