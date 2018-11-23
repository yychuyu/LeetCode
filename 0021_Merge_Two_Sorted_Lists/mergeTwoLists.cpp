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
        
        if(l1 == NULL && l2 == NULL)return NULL;
        if(l1 == NULL && l2 != NULL)return l2;
        if(l1 != NULL && l2 == NULL)return l1;
        if(l1->val > l2->val)
        {
            ListNode*tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        ListNode*head = l1;
        ListNode*lnext = l1->next;
      while(l1->next != NULL && l2 != NULL)
      {
          if((l2->val > l1->val || l2->val == l1->val) && (l2->val < lnext->val || l2->val == lnext->val ))
          {
              ListNode*p = l2;
              l2 = l2->next;
              l1->next = p;
              p->next = lnext;
              l1 = p;
          }
          else if(l2->val > l1->val && l2->val > lnext->val)
          {
              l1 = lnext;
              lnext = l1->next;
          }
      }
        if(l1->next == NULL && l1 != head && l2 != NULL)
        {
            l1->next = l2;
            l2 = l2->next;
            l1 = l1->next;
        }
        if(l1 == head && l2 != NULL)
        {
            while(l1->next!= NULL && l1->val < l2->val)
            {
                l1 = l1->next;
            }
             l1->next = l2;
        }
        return head;
        
    }
};
