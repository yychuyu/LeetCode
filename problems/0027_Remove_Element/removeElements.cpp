/*

 题目：删除链表中给定值val的所有节点
 
*/

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
    ListNode* removeElements(ListNode* head, int val) {
        
      
          while(head != NULL )
        {
            if(head->val == val)
            {
                head = head->next;
            }
            else
                break;
        }
        
        ListNode*s = head;
        ListNode*p = head;
        while(s != NULL)
        {
            if(s->val == val)
            {
                p->next = s->next;
                s = p->next;
                continue;
            }
            p = s;
            s = s->next;
        }
        return head;
    }
};
