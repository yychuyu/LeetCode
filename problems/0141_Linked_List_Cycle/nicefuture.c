/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head;
    struct ListNode *q = head;
    if (q != NULL) q = q->next;
    while (p != NULL && q != NULL) {
        if (p == q) return true;
        p = p->next;
        q = q->next;
        if (q != NULL) q = q->next;
        else break;
    }
    return false;
}
