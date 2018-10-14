 /**
   * Definition for singly-linked list.
   * public class ListNode {
   *     int val;
   *     ListNode next;
   *     ListNode(int x) { val = x; }
   * }
   */
  class Solution {
      public ListNode deleteDuplicates(ListNode head) {
          
          if (head == null || head.next == null ) {
              return head;
          }
          
          // 记录前一个节点的值
          ListNode before = head;
          for (ListNode i = head.next; i != null; i = i.next) {
              
              if (i.val == before.val) {
                  before.next = i.next;
              } else {
                  before = i;
              }
          }
          
          return head;
      }
  }