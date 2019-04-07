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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* now = head;
        while (l1 && l2){
            int x = l1 ? l1->val :0;
            int y = l2 ? l2->val : 0;
            if (x < y){
                now->next = l1;
                now = l1;
                l1 = l1->next;
            }
            else {
                now->next = l2;
                now = l2;
                l2 = l2->next;
            }
        }
        // if length of l1 and l2 are not equal
        if (l1) now->next = l1;
        if (l2) now->next = l2;
        return head->next;
    }
};
