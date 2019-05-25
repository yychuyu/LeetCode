/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2){
        ListNode * head = new ListNode(0);  // create head node as the head point
        ListNode * now = head;  
        int carry = 0;  // if the sum is greater than ten, carry is 1
        while(l1 || l2 || carry){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            ListNode * node = new ListNode((x + y + carry) % 10);
            now->next = node;
            now = node; // move overc
            carry = (x + y + carry) / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head->next;  // final linked list
    }
};

