class Solution {
public:
    ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointer1 = headA;
        ListNode* pointer2 = headB;
        while (pointer1 != NULL && pointer2 != NULL) {
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }
        ListNode* walk1 = headA;
        ListNode* walk2 = headB;
        if (pointer1 != NULL) {
            while (pointer1->next != NULL) {
                pointer1 = pointer1->next;
                walk1 = walk1->next;
            }
            walk1 = walk1->next;
        }
        else if (pointer2 != NULL) {
            while (pointer2->next != NULL) {
                pointer2 = pointer2->next;
                walk2 = walk2->next;
            }
            walk2 = walk2->next;
        }
        while (walk1 != NULL && walk2 != NULL) {
            if (walk1 == walk2)
                return walk1;
            walk1 = walk1->next;
            walk2 = walk2->next;
        }
        return NULL;
    }
};
