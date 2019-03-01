/**
 * @Author 宋宗垚
 * @Date 2018/11/15 12:48
 * @Description TODO
 */
/*
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
你应该返回如下子树:

      2
     / \
    1   3
在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。
 */
public class SearchinaBinarySearchTree_700 {
    public TreeNode searchBST1(TreeNode root, int val) {
        TreeNode result = null;
        if(root==null){
            result = null;
        }else {
            if(val==root.val){
                result= root;
            }else {
                TreeNode left = searchBST1(root.left,val);
                if(left!=null){
                    result = left;
                }
                TreeNode right = searchBST1(root.right,val);
                if(right!=null){
                    result = right;
                }
            }
        }
        return result;
    }

    public TreeNode searchBST(TreeNode root, int val) {
        TreeNode result = null;
        if (root==null){
            return result;
        }else if (root.val==val){
            return root;
        }else if(root.val>val){
            return searchBST(root.left,val);
        }else if(root.val<val){
            return searchBST(root.right,val);
        }
        return result;
    }

}
