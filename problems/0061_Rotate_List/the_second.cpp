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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;

        ListNode *p = head;

        int len = 0;
        while (p)
        {
            len++;
            p = p->next;
        }

        k %= len;

        if (k <= 0)
            return head;

        int index = 1;      
        p = head;
        while (index < (len - k) && p->next != NULL)
        {
            index++;
            p = p->next;
        }

        ListNode *ret = p->next, *q = p;

        while (p->next)
            p = p->next;
        p->next = head;
        q->next = NULL;
        return ret;

    }
};
