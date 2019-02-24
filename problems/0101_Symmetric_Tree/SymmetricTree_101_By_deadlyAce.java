/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class SymmetricTree_101_By_deadlyAce{
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true; //根节点是空，返回true
        }else {
            return isSymmetric(root.left, root.right);//然后进行递归，思路的实现
        }
    }
    private boolean isSymmetric(TreeNode left, TreeNode right) {
        if (left == null && right == null) {//左右子树都是空，肯定对称，true
            return true;
        }else if (left == null || right == null) {
            return false;//左右子树只有一个为空，那么返回false
        }
        if(left.val != right.val)//左右子树都不为空，但是值不相等，返回false
            return false;
        //这里是左右子树的值相等，然后递归判断每个子树
        return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
    }
}
