/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k == 0 || head.next == null) {
            return head;
        }
        ListNode p = head;
        //遍历出链表长度
        int length = 0;
        ListNode tail = head;
        for (; tail.next != null; tail = tail.next) {
            length++;
        }
        length++;

        //找到需要反转的节点的前置节点
        for (int i = 1; i < length - k % length; i++) {
            p = p.next;
        }
        //如果反转节点的前置节点是最后一个节点则不需要反转直接返回原头节点
        if (p.next == null) {
            return head;
        } else {
            //新翻转后的头节点指向刚才遍历出的反转节点的前置节点的next节点
            ListNode newHead = p.next;
            //尾节点next指向原head节点
            tail.next = head;
            p.next = null;
            return newHead;
        }
    }
}
