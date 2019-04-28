//	Merge_Two_Sorted_Lists 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode *mergelist;

        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val<l2->val) {
            mergelist = l1;
            mergelist->next = mergeTwoLists(l1->next, l2);
        }
        else{
            mergelist = l2;
            mergelist->next = mergeTwoLists(l2->next, l1);
        }
        return mergelist;
    }
};
