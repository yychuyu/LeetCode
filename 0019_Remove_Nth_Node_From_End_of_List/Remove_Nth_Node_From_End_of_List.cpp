/*
  题目：
  给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点（只进行一次扫描）。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* feakHead=new ListNode(0);
        feakHead->next=head;
    
        ListNode* p=head;
        while( n>0 && p!=NULL ){
            p=p->next;
            n--;
        }
        ListNode* q1=head;
        ListNode* q2=feakHead;
        
        while(p!=NULL){
            p=p->next;
            q1=q1->next;
            q2=q2->next;
        }        
        q2->next=q1->next;
        free(q1);
        
        return feakHead->next;
    }
};
