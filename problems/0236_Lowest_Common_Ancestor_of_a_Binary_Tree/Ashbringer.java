/**
 * @Author 宋宗垚
 * @Date 2019/3/6 19:05
 * @Description 236. 二叉树的最近公共祖先
 */
public class Ashbringer {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root==null || root.val == p.val || root.val == q.val){
            return root;
        }else {
            TreeNode left = lowestCommonAncestor(root.left,p,q);
            TreeNode right = lowestCommonAncestor(root.right,p,q);
            if (left != null && right != null){
                return root;
            }else if (left==null){
                return right;
            }else {
                return left;
            }
        }

    }

}
