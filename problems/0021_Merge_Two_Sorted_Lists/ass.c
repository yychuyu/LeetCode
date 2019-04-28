/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* L = (struct ListNode *)malloc(sizeof(struct ListNode));
    L->next = NULL;
    struct ListNode* mn=L,*x;
    while(l1!=NULL&&l2!=NULL)
    {
        if(l1->val <= l2->val)
        {
            x = l1->next;
            l1->next = L->next;
            L->next = l1;
            l1 = x;
            L = L->next;
        }
        else
        {
            x = l2->next;
            l2->next = L->next;
            L->next = l2;
            l2 = x;
            L = L->next;            
        }
    }
    if(l1==NULL&&l2!=NULL)
    {
        L->next = l2;
        l2 = NULL;
    }
    else if(l2==NULL&&l1!=NULL)
    {
        L->next = l1;
        l1 = NULL;
    }
    return mn->next;
}
