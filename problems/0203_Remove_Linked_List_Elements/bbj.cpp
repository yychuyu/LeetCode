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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * head_node = new ListNode(0);
        head_node->next = head;
        ListNode * p = head_node;
        while (p->next){
            if (p->next->val == val)
                p->next = p->next->next;
            else 
                p = p->next;
        }
        return head_node->next;
    }
};
