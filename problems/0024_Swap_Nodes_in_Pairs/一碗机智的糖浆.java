/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode pre=new ListNode(0);
        pre.next=head;
        ListNode temp=pre;
        //考虑链表长度为奇数的情况
        while(temp.next!=null&&temp.next.next!=null){
            ListNode start=temp.next;
            ListNode end=temp.next.next;
            temp.next=end;
            start.next=end.next;
            end.next=start;
            temp=start;
        }
        //返回链表
        return pre.next;
    }
}