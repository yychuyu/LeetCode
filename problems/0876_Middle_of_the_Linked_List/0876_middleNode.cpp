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
    ListNode* middleNode(ListNode* head) {
        ListNode*p1 = head;
        ListNode*p2 = head;
      
        while(p2 != NULL && p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
      
            return p1;
        
    }
};
