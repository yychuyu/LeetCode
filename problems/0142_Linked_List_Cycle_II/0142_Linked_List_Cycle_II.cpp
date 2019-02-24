/*
  题目：
  给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* encounter=NULL;
        bool existCycle=false;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                encounter=fast;
                existCycle=true;
                break;
            }
        }
        
        if( existCycle ){
            ListNode* p=head;
            while(p!=encounter){
                p=p->next;
                encounter=encounter->next;
            }
            return p;
        }
        
        return NULL;
    }
};
