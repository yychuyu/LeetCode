/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 这题很巧
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *p, *q, *t;
        p = head;
        q = head->next;
        head->next = NULL;
        while (q){
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }
};
