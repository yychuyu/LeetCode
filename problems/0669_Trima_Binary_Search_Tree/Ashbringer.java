/**
 * @Author 宋宗垚
 * @Date 2018/11/15 13:49
 * @Description TODO
 */
/*
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值
给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。
你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

示例 1:

输入:
    1
   / \
  0   2

  L = 1
  R = 2

输出:
    1
      \
       2
示例 2:

输入:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

输出:
      3
     /
   2
  /
 1
 */
public class Ashbringer {
    public TreeNode trimBST(TreeNode root, int L, int R) {
        TreeNode result = null;
        if (root==null){

        }else {
            if(root.val<L){
                result = trimBST(root.right,L,R);
            }else if(root.val>R){
                result = trimBST(root.left,L,R);
            }else {
                root.left = trimBST(root.left,L,R);
                root.right = trimBST(root.right,L,R);
                result = root;
            }

        }
        return  result;
    }
}
