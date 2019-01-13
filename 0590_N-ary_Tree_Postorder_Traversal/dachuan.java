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
    public List<Integer> postorder(Node root) {
        List<Integer> list = new ArrayList<>();
        return perform(root, list);
    }

    private List<Integer> perform(Node root, List<Integer> list) {
        if (root != null) {
            if(root.children != null) {
                for (Node node : root.children) {
                    perform(node, list);
                }
            }
            list.add(root.val);
        }
        return list;
    }
}