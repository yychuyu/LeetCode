import java.util.ArrayList;
import java.util.List;

/**
 * @Author 宋宗垚
 * @Date 2018/11/27 13:15
 * @Description T二叉树的层次遍历
 */
/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
 */
public class BinaryTreeLevelOrderTraversal_102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> data = new ArrayList<>();
        ff(root,data,0);
        return data;
    }

    public void ff(TreeNode root,List<List<Integer>> data,int deepth){
        if(root==null){
            return;
        }
        if(data.size()-1<deepth){
            List<Integer> a = new ArrayList<>();
            data.add(a);
        }
        data.get(deepth).add(root.val);
        ff(root.left,data,deepth+1);
        ff(root.right,data,deepth+1);

    }


}
