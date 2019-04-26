package LeetCodePart4;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * @author 刘云生
 * @date 2019/3/2610:50
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环
 */
public class HasCycle {
    public static void main(String[] args) {
        ListNode listNode=new ListNode(1);
        ListNode listNode2=new ListNode(2);
//        ListNode listNode3=new ListNode(3);
//        ListNode listNode4=new ListNode(4);
//        ListNode listNode5=new ListNode(5);
        listNode.next=listNode2;
//        listNode2.next=listNode3;
//        listNode3.next=listNode4;
//        listNode4.next=listNode5;
        HasCycle hasCycle=new HasCycle();
        System.out.println(hasCycle.hasCycle(listNode));

    }
//给定的链表有可能是一个单链表，有可能是一个环形链表，需要自己做判断
    public boolean has(ListNode head){
        Set<ListNode> node = new HashSet<>();
        boolean flag=false;
        while (head!=null){
            if (node.contains(head)){
                flag=true;
                break;
            }else {
//                这一步就是筛选
                node.add(head);
            }
            head=head.next;
        }
        return flag;
    }
//    快慢指针
    public boolean hasCycle(ListNode head){
            ListNode slow=head;
            ListNode fast=head;
            while (slow!=null&&fast!=null&&fast.next!=null){
                slow=slow.next;
                fast=fast.next.next;
                if (slow==fast){
                    return true;
                }
            }
            return false;
    }
}
