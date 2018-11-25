
//想了好一会都没有解决这道题，感谢torresng 的代码。
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct ListNode *result,*p;
    if(l1->val <= l2->val) {
        result = p = l1;
        l1 = l1->next;
    } else {
        result = p = l2;
        l2 = l2->next;
    }
    while(l1 && l2) {
        if(l1->val <= l2->val) {
            p->next = l1; 
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return result; 
}