package Tree;

/**
 * @Author 宋宗垚
 * @Date 2018/12/15 11:51
 * @Description 109. 有序链表转换二叉搜索树
 */
/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
 */
class TreeNode {
      int val;
     TreeNode left;
     TreeNode right;
     TreeNode(int x) { val = x; }
}
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
public class ConvertSortedListtoBinarySearchTree_109 {
    public TreeNode sortedListToBST(ListNode head) {
        if(head==null){
            return null;
        }
        if(head.next==null){
            return new TreeNode(head.val);
        }


        // 快速移动节点
        ListNode fast = head.next.next;
        ListNode mid = head;
        while (fast!=null && fast.next!=null){
            mid = mid.next;
            fast = fast.next.next;
        }
        TreeNode root = new TreeNode(mid.next.val);
        root.right = sortedListToBST(mid.next.next);

        ListNode midNext = mid.next;
        // 断开单链表（会破坏原来单链表的结构）
        mid.next = null;
        // 构建左子树
        root.left = sortedListToBST(head);
        return root;


    }
}
