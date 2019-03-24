import sun.reflect.generics.tree.Tree;

import java.util.Map;

/**
 * @Author 宋宗垚
 * @Date 2018/11/30 21:49
 * @Description TODO
 */
/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
 */
public class Ashbringer {
    public static void main(String[] args){

    }
    public static boolean flag = true;
    public  boolean isBalanced(TreeNode root) {
        if(root == null){
            return true;
        }
        if(Math.abs(xxx(root.left)-xxx(root.right))>1){
            return false;
        }
        else {
            return isBalanced(root.left) &&isBalanced(root.right);
        }

    }

    public  void isFlag(TreeNode root) {
        if(root==null){
            return ;
        }
        int left = xxx(root.left);
        int right = xxx((root.right));
        if(left>right+1 || right>left+1){
           flag = false;
        }
//        return true;
    }

    public int xxx(TreeNode root){
        if(root==null){
            return 0;
        }
        int left = xxx(root.left);
        int right = xxx(root.right);
        return Math.max(left,right)+1;
    }
}
