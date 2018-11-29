/*
  题目：
  删除链表中等于给定值 val 的所有节点。
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
        ListNode* feakHead=new ListNode(0);   
        feakHead->next=head;
        
        ListNode* p1=feakHead;
        ListNode* p2=head;
        while(p2){
            if(p2->val == val){
                p1->next = p2->next;
                free(p2);
                p2=p1->next;                   
                continue;
            }
            p1=p2;
            p2=p2->next;
        }
        
        return feakHead->next;
    }
};
