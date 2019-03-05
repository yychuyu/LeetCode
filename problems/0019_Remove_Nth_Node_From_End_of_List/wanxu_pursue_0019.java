/**
 * Author: Json Wan
 * Created at: 2019/3/5 23:00
 * Description:
 * 19. Remove Nth Node From End of List
 Medium
 Given a linked list, remove the n-th node from the end of list and return its head.
 Example:
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 思路：先求长度，然后顺序删除，需要注意的点：
（1） 循环遍历时必须考虑两端的边界情况，注意是两端，严防空指针异常；
 （2）对需要保存的头指针备份。
 **/
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class wanxu_pursue_0019 {

    //AC，0.9893
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null){
            return null;
        }
        int l=0;
        ListNode pHead=head;
        while(pHead!=null){
            l++;
            pHead=pHead.next;
        }
        n=l-n;
        if(n<0){
            return head;
        }else if(n==0){
            return head.next;
        }else{
            pHead=head;
            n--;
            while(n>0){
                head=head.next;
                n--;
            }
            if(head.next!=null) {
                head.next = head.next.next;
            }else{
                head.next=null;
            }
        }
        return pHead;
    }

    private static void printLinkedList(ListNode root){
        while(root!=null){
            System.out.print(root.val);
            root=root.next;
            if(root!=null)
                System.out.print("-->");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        wanxu_pursue_0019 instance=new wanxu_pursue_0019();
        ListNode n1=new ListNode(1);
        ListNode n2=new ListNode(2);
        ListNode n3=new ListNode(3);
        ListNode n4=new ListNode(4);
        ListNode n5=new ListNode(5);
        n1.next=n2;
        n2.next=n3;
        n3.next=n4;
        n4.next=n5;
        printLinkedList(n1);
        printLinkedList(instance.removeNthFromEnd(n1,5));
        printLinkedList(instance.removeNthFromEnd(n1,4));
        printLinkedList(instance.removeNthFromEnd(n1,3));
        printLinkedList(instance.removeNthFromEnd(n1,2));
        printLinkedList(instance.removeNthFromEnd(n1,1));
        printLinkedList(instance.removeNthFromEnd(n1,0));
    }
}
