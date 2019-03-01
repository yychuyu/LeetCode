/**
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

class Solution{
    public List<List<Integer>> levelOrder(TreeNode root){

        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if(root == null){
            return list;
        }

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);

        while(queue.size() != 0){
            List<Integer> alist = new ArrayList<Integer>();
            for (TreeNode child: queue)
                alist.add(child.val);

                list.add(new ArrayList<Integer>(alist));
                Queue<TreeNode> queue2 = queue;
                queue = new LinkedList<TreeNode>();

                for (TreeNode child:queue2) {
                    if (child.left != null)
                        queue.add(child.left);
                    if (child.right != null)
                        queue.add(child.right);
                }
        }
        return list;
    }
}
