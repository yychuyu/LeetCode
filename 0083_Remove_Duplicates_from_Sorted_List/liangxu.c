struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    if (head == NULL)
        return NULL;

    struct ListNode* p = head;
    while (p->next != NULL) {
        if (p->val == p->next->val)
            p->next = p->next->next;
        else
            p = p->next;
    }

    return head;
}
