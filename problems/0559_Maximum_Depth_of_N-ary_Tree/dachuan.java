/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }else if(root.children.size() > 0){
            int num = 1;
            for (int i = 0; i < root.children.size(); i++) {
                num = Math.max(num, maxDepth(root.children.get(i)));
            }
            return num + 1;
        }else{
            return 1;
        }
    }
}