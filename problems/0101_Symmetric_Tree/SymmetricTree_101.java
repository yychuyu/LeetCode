import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @Author 宋宗垚
 * @Date 2018/11/27 12:19
 * @Description TODO
 */
/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 */
public class SymmetricTree_101 {

    public boolean isSymmetric(TreeNode root) {
        if(root ==null){
            return true;
        }
        boolean flag = isSymmetric(root.left,root.right);
        return flag;

    }
    public boolean isSymmetric(TreeNode left ,TreeNode right){
        if(left==null && right==null){
            //如果都是空的
            return true;
        }else if((left==null && right!=null) ||(left!=null&&right==null)){
            // 如果只有一个空的
            return false;
        }
        else if(left.val !=right.val){
            return false;
        }
        else {
            return isSymmetric(left.left,right.right) && isSymmetric(left.right,right.left);
        }
    }

}
