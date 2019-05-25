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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* last;
       // ListNode* last = head -> next;
        while(cur!=NULL)
        {
            last = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = last;           
        }
        return pre;
    }
};