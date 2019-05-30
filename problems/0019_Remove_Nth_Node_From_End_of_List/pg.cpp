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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL == head->next && 1==n)
        {
            return NULL;
        }
        ListNode* p = NULL;
        ListNode* q = NULL;
        int index = 0;
        p = head;
        q = head;
        while(p->next != NULL)
        {
            if(index >= n)
            {
                q = q->next;
            }
            index++;
            p = p->next;
        }
        if(index+1 == n)
        {
            return head->next;
        }
        q->next = q->next->next;
        return head;
    }
};