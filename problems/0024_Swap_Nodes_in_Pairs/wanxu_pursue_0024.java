/**
 * Author: Json Wan
 * Created at: 2019/3/27 0:45
 * Description:
 * 24. Swap Nodes in Pairs
 * Medium
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * <p>
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 思路：遍历，交换即可。
 **/
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class wanxu_pursue_0024 {

    //AC,1.00,nice!
    public ListNode swapPairs(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }
        ListNode tail=null;
        ListNode p1=head;
        ListNode p2=head.next;
        head=p2;
        while(p1!=null&&p2!=null){
            p1.next=p2.next;
            p2.next=p1;
            if(tail!=null){
                tail.next=p2;
            }
            tail=p1;
            p1=p1.next;
            if(p1!=null){
                p2=p1.next;
            }
        }
        return head;
    }


    public static void printList(ListNode root) {
        while (root != null) {
            System.out.print(root.val);
            root = root.next;
            if (root != null) {
                System.out.print("-->");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        ListNode node6 = new ListNode(6);
        ListNode node7 = new ListNode(7);
        ListNode node8 = new ListNode(8);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        node5.next = node6;
        node6.next = node7;
        node7.next = node8;
        printList(node1);
        wanxu_pursue_0024 instance = new wanxu_pursue_0024();
        printList(instance.swapPairs(node1));
    }
}
