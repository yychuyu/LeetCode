package Tree;

import sun.reflect.generics.tree.Tree;

/**
 * @Author 宋宗垚
 * @Date 2019/3/1 14:39
 * @Description 701二叉搜索树的插入操作
 */
public class InsertintoaBinarySearchTree_701 {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        TreeNode data = new TreeNode(val);
        if (null==root){
            return data;
        }else {
//            TreeNode p = null;
            TreeNode re = searchBST(root,val,null);
            if (null!=re){
                if(re.val>val){
                    re.left = data;
                }else {
                    re.right = data;
                }
            }
            return root;
        }

    }

    /**
     * 也就是说如果树中没有这个值的话，就返回其父节点
     * @param root 要查找的树的根节点
     * @param val 要查找的节点的值
     * @param pre 根节点的父节点
     * @return 如果又val这个值则返回的是带有val这个值的节点，如果没有val这个值，则返回的是插入操作中可以成为插入节点的双亲节点的节点
     */
    public TreeNode searchBST(TreeNode root, int val,TreeNode pre) {
        TreeNode result = null;
        if (null==root){
            // 返回父节点
            return pre;
        }else if (root.val==val){
            return root;
        }else if(root.val>val){
            return searchBST(root.left,val,root);
        }else if(root.val<val){
            return searchBST(root.right,val,root);
        }
        return result;
    }
}
