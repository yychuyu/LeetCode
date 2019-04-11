/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode request = new ListNode(0);
        ListNode nextNode = request;

        int l1_len = 0;
        int l2_len = 0;
        ListNode temp_l1 = l1;
        ListNode temp_l2 = l2;


        while (temp_l1 != null) {
            l1_len++;
            temp_l1 = temp_l1.next;
        }
        l1_len ++;
        while (temp_l2 != null) {
            l2_len++;
            temp_l2 = temp_l2.next;
        }
        l2_len ++;

        ListNode max = l1_len >= l2_len ? l1 : l2;
        ListNode min = l1_len < l2_len ? l1 : l2;

        int quotients = 0;

        while (max != null){
            if (min != null){
                nextNode.val = (max.val + min.val + quotients) % 10 ;
                quotients = (max.val + min.val + quotients) / 10 ;
                min = min.next;
            }else {
                nextNode.val = (max.val + quotients) % 10 ;
                quotients = (max.val + quotients ) / 10 ;
            }
            max = max.next;
            if (quotients == 0 && max == null){
                break;
            }else {
                nextNode.next = new ListNode(quotients);
                nextNode = nextNode.next;
            }


        }
        
        return request;

       
    }
}