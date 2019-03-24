import java.util.ArrayList;
import java.util.List;

/**
 * @Author 宋宗垚
 * @Date 2019/3/4 21:35
 * @Description 257. 二叉树的所有路径
 */
public class Ashbringer {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> data = new ArrayList<>();
        if (root==null){
            return data;
        }else {
            ff(root,""+root.val,data);
            return data;
        }

    }

    public void ff(TreeNode root,String str,List<String> data){
        if (root.left==null&&root.right==null){
            data.add(str);
        }else if (root.left==null){
            ff(root.right,str+"->"+root.right.val,data);
        }else if (root.right==null){//
            ff(root.left,str+"->"+root.left.val,data);
        }else {
            ff(root.right,str+"->"+root.right.val,data);
            ff(root.left,str+"->"+root.left.val,data);
        }
    }
}
