/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if(head == null){
            return null;
        }
        //2、对以 head.next 开头的链重新执行一遍 removeElements()
        head.next = removeElements(head.next, val);
        //1、对以 head 开头的链进行去除处理；
        return head.val == val ? head.next : head;
    }
}