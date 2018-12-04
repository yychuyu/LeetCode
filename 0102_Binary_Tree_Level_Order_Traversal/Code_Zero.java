/**

Exam:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        if (root == null) 
            return result;
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
            queue.offer(root);
        while(!queue.isEmpty()) {
            int size = queue.size();
            LinkedList<Integer> list = new LinkedList<Integer>();
            for (int i = 0; i < size; ++i) {
                TreeNode node = queue.pop();
                list.add(node.val);
                if (node.left != null) 
                    queue.offer(node.left);
                if (node.right != null) 
                    queue.offer(node.right);
            }
            result.add(list);
        }
        return result;
    }
}
