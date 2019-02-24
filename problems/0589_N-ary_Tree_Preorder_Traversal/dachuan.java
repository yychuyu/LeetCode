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
    public List<Integer> preorder(Node root) {
        List<Integer> list = new ArrayList<>();
        perform(list, root);
        return list;
    }

    public void perform(List<Integer> list, Node root) {
        if(root != null) {
            list.add(root.val);
            List<Node> children = root.children;
            for (int i = 0; i < children.size(); i++) {
                Node node = children.get(i);
                perform(list, node);
            }
        }
    }
}