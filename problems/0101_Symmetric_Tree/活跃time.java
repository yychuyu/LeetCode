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
        
        // �ֶ�����ջ����
        LinkedList<TreeNode> l = new LinkedList<TreeNode>();
        LinkedList<TreeNode> r = new LinkedList<TreeNode>();
        
        // ����������ѹջ
        l.push(root.left);
        r.push(root.right);
       
       	// ��ѭ���дӾ���˳���������������ֵ��ͬ����������򷵻�false,������ɷ���true 
        while(true){
        	// ���� ��ջ
            if(l.peek() == null){
                if(r.peek() == null) {
                    TreeNode cl,cr;
                    do{// ����ǰ�ֱ��ں���ڵ㣬���ε�ջ
                        cl = l.pop();
                        cr = r.pop();
                        if(l.isEmpty() && r.isEmpty()) return true;// �������
                    } while(l.peek().right == cl && r.peek().left == cr);
                    l.push(l.peek().right);// �ֱ𽫺���ڵ�ѹջ
                    r.push(r.peek().left);
                }
                else return false;// ����ڵ㲻���
            }else{
                if(r.peek() != null && r.peek().val == l.peek().val) {
                    l.push(l.peek().left);// �ֱ�����ڵ�ѹջ
                    r.push(r.peek().right);
                }
                else return false;// ����ڵ㲻���
            }
        }
        
        
    }
    
}

