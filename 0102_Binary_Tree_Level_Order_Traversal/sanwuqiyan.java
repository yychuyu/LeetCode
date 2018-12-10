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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res=new LinkedList<>();
        LinkedList<TreeNode> queue=new LinkedList<TreeNode>();
        if(root==null) return res;
        queue.offer(root);
        while(!queue.isEmpty()){
            int size=queue.size();
            List<Integer> subres=new LinkedList<>();
            for(int i=0;i<size;i++){
                TreeNode tmp=queue.pop();
                subres.add(tmp.val);
                if(tmp.left!=null)
                    queue.offer(tmp.left);
                if(tmp.right!=null)
                    queue.offer(tmp.right);
            }
            res.add(subres);
        }
        return res;
    }
}
