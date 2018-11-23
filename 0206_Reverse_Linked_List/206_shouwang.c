/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
struct ListNode* reverseList(struct ListNode* head) {
    if(NULL == head)
        return NULL;
     struct ListNode* p = head;
    struct ListNode* value = NULL;
    struct ListNode* ret = value;
    while(NULL != p)
    {
        value =(struct ListNode*) malloc(sizeof(struct ListNode));
        if(NULL == value)
        {
            return NULL;
        }
        memset(value,0,sizeof(struct ListNode));
        value->val = p->val;
        value->next = ret;
        ret = value;
        p = p->next;
    }
    return ret;
}*/
struct ListNode* reverseList(struct ListNode* head) {
    if(NULL == head)
        return NULL;
    
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    struct ListNode* nextNode = head->next;
    while(NULL != cur)
    {
        cur->next = pre;
        pre = cur;
        cur = nextNode;
        if(NULL != nextNode)
        {
            nextNode = nextNode->next;
        }
    }
    head = pre;
    return head;
}
