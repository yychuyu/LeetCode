/*
  题目：
  将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
  
  做法：递归
  
  参考：
  https://www.cnblogs.com/leavescy/p/5879625.html
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }else{           
            if(l1 == NULL){            
                return l2;        
            }       
            if(l2 == NULL){           
                return l1;       
            }
        }        
        
        ListNode* head = NULL;
        if(l1->val > l2->val){
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }else{
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }       
 
        return head;
    }
};
