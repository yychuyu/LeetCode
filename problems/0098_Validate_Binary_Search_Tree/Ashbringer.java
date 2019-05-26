import sun.reflect.generics.tree.Tree;

import java.util.ArrayList;
import java.util.List;

public class Ashbringer {

    public boolean isValidBST(TreeNode root) {
        if (root==null){
            return true;
        }else {
            int[] xxx = ff(root);
            if (xxx[2]==1){
                return true;
            }else {
                return false;
            }
        }
    }
    public int[] ff(TreeNode root){
        if (root.left==null && root.right==null){
            int [] x = new int[3];
            x[0] = root.val;
            x[1] = root.val;
            x[2] = 1;
            return x;
        }else if (root.left==null){
            int[] r = ff(root.right);
            if (r[0]>root.val){
                r[0] = root.val;
                return r;
            }else {
                r[2] = 0;
                return r;
            }
        }else if (root.right==null){
            int[] l = ff(root.left);
            if (l[1]<root.val){
                l[1] = root.val;
                return l;
            }else {
                l[2] = 0;
                return l;
            }
        }else {
            int[] l = ff(root.left);
            int[] r = ff(root.right);
            int[] xx = new int[3];
            if (l[1]<root.val && r[0]>root.val){

                xx[0] = l[0];
                xx[1] = r[1];
                if (l[2]==1 && r[2]==1){
                    xx[2]=1;
                }else {
                    xx[2] = 0;
                }
                return xx;
            }else {
                xx[2] = 0;
                return xx;
            }


        }
    }

}
