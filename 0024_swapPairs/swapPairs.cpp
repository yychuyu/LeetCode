/**
 *¡¿
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    
     /*   if(head == NULL)return NULL;
        if(head->next == NULL)return head;
        ListNode* p =  new ListNode(0);
        p->next = head;
        ListNode*slow = p,*fast = p;
        while(p->next != NULL && fast != NULL)
        {
            slow = p->next;
            fast = p->next->next;
            if(slow == head)
            {
                head = fast;
            }
            if(slow->next != NULL)
            { 
                
                slow->next = fast->next;
                fast->next = slow;
                p->next = fast;
                p = slow;
            }
           
        }
        return head;
        */
        
        ListNode*pos = new ListNode(-1),*pre = pos;
        pos->next = head;
        while(pre->next != NULL && pre->next->next != NULL)
        {
            ListNode*s = pre->next->next;
            pre->next->next = s->next;
            s->next = pre->next;
            pre->next = s;
            pre = s->next;
            
        }
        return pos->next;
    
    }
};
