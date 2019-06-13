/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        return isMirror(root.left, root.right);
    }
    
    public boolean isMirror(TreeNode left, TreeNode right) {

        if(left == null){
            if(right == null) return true;
            else return false;
        }else {
            return right != null 
            && left.val == right.val 
            && isMirror(left.left, right.right) 
            && isMirror(left.right, right.left);
        }
        
    }
}


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        
        if(root == null) return true;
        
        // 手动进行栈管理
        LinkedList<TreeNode> l = new LinkedList<TreeNode>();
        LinkedList<TreeNode> r = new LinkedList<TreeNode>();
        
        // 将左右子树压栈
        l.push(root.left);
        r.push(root.right);
       
       	// 在循环中从镜像顺序遍历左右子树，值相同则继续，否则返回false,遍历完成返回true 
        while(true){
        	// 空树 弹栈
            if(l.peek() == null){
                if(r.peek() == null) {
                    TreeNode cl,cr;
                    do{// 若当前分别处于后序节点，则多次弹栈
                        cl = l.pop();
                        cr = r.pop();
                        if(l.isEmpty() && r.isEmpty()) return true;// 遍历完成
                    } while(l.peek().right == cl && r.peek().left == cr);
                    l.push(l.peek().right);// 分别将后序节点压栈
                    r.push(r.peek().left);
                }
                else return false;// 镜像节点不相等
            }else{
                if(r.peek() != null && r.peek().val == l.peek().val) {
                    l.push(l.peek().left);// 分别将先序节点压栈
                    r.push(r.peek().right);
                }
                else return false;// 镜像节点不相等
            }
        }
        
        
    }
    
}

