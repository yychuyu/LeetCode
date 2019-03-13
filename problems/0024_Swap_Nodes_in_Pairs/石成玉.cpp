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
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;
        while(head && head->next) {
            ListNode* next = head->next->next;
            
            pre->next = head->next;
            head->next->next = head;
            head->next = next;
            
            pre = head;
            head = head->next;
        }
        return new_head->next;
    }
};
