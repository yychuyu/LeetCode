/**
 * Author: Json Wan
 * Created at: 2019/3/27 1:07
 * Description:
 * 25. Reverse Nodes in k-Group
 Hard
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

 Example:
 Given this linked list: 1->2->3->4->5
 For k = 2, you should return: 2->1->4->3->5
 For k = 3, you should return: 3->2->1->4->5

 Note:
 Only constant extra memory is allowed.
 You may not alter the values in the list's nodes, only nodes itself may be changed.
 思路：有长度限制的反转链表，依次反转就行。
 **/
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class wanxu_pursue_0025 {

    //AC,1.00,nice!
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null||head.next==null||k<=1){
            return head;
        }
        //新链表头
        ListNode pHead=null;
        //新链表尾
        ListNode tail=null;
        ListNode p1=head;
        ListNode p2=head.next;
        ListNode p3=p2.next;
        ListNode counter=head;
        int count=0;
        while(counter!=null){
            count++;
            counter=counter.next;
            if(count==k){
                break;
            }
        }
        while(count>=k){
            count=k-1;
            //记录下反转得到的尾节点
            ListNode newTail = p1;
            //根据k的数值反转k个节点
            while(count>0) {
                p2.next = p1;
                p1 = p2;
                p2 = p3;
                if(p3!=null) {
                    p3 = p3.next;
                }
                count--;
            }
            //记录反转得到的头结点
            ListNode newHead=p1;
            //整个链表头记录
            if(pHead==null){
                pHead=newHead;
            }
            //将反转这一段的头接到整个新链表的尾上
            if(tail!=null) {
                tail.next = newHead;
            }
            //更新新链表的尾
            tail=newTail;
            //向前推移
            p1=p2;
            p2=p3;
            if(p3!=null) {
                p3 = p3.next;
            }
            //考察前面的节点数看是否需要下一次反转
            counter=p1;
            while(counter!=null){
                count++;
                counter=counter.next;
                if(count==k){
                    break;
                }
            }
        }
        //需要注意k比较大时一次都不反转的情况
        if(tail==null){
            return head;
        }
        //最后一次反转完成之后将新链表尾接到剩余链表头
        tail.next=p1;
        return pHead;
    }

    //递归解法
    public ListNode bestReverseKGroup(ListNode head, int k) {
        ListNode curr = head;
        int count = 0;
        while (curr != null && count != k) { // find the k+1 node
            curr = curr.next;
            count++;
        }
        if (count == k) { // if k+1 node is found
            curr = bestReverseKGroup(curr, k); // reverse list with k+1 node as head
            // head - head-pointer to direct part,
            // curr - head-pointer to reversed part;
            while (count-- > 0) { // reverse current k-group:
                ListNode tmp = head.next; // tmp - next head in direct part
                head.next = curr; // preappending "direct" head to the reversed list
                curr = head; // move head of reversed part to a new node
                head = tmp; // move "direct" head to the next node in direct part
            }
            head = curr;
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
        wanxu_pursue_0025 instance = new wanxu_pursue_0025();
//        printList(instance.reverseKGroup(node1,2));
//        printList(instance.reverseKGroup(node1,3));
//        printList(instance.reverseKGroup(node1,4));
//        printList(instance.reverseKGroup(node1,5));
        printList(instance.reverseKGroup(node1,6));
    }
}
