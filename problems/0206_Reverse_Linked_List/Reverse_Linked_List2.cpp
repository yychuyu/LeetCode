/*
  题目：
  反转一个单链表。
 
  示例:
  输入: 1->2->3->4->5->NULL
  输出: 5->4->3->2->1->NULL
  
  进阶:
  你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){       
            return head;     
        }   
       
        ListNode* h=reverseList(head->next);        
        head->next->next=head;       
        head->next=NULL;
        return h;
    }
};
