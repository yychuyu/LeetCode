/*
  题目：
  删除单链表中的某个节点（只给定该待删除的节点，不给定链表头指针）。
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
    void deleteNode(ListNode* node) {
        if(node==NULL){
            return;
        }
        if(node->next!=NULL){
            ListNode* p=node->next;
            node->val = p->val;
            node->next = p->next;
            free(p);
        }    
    }
};
