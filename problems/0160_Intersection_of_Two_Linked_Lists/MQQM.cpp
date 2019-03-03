/*
  题目：
  编写一个程序，找到两个单链表相交的起始节点。
  
  参考：
  https://blog.csdn.net/qq_27060423/article/details/82917378
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
    
        ListNode* pA = headA;
        ListNode* pB = headB;
        stack<ListNode*> stkA;
        stack<ListNode*> stkB;
        while(pA != NULL){
            stkA.push(pA);
            pA = pA->next;                
        }
        while(pB != NULL){
            stkB.push(pB);
            pB = pB->next;
        }
    
        ListNode* rst = NULL;
        while( !stkA.empty() && !stkB.empty() && stkA.top() == stkB.top()){
            rst = stkA.top();
            stkA.pop();                
            stkB.pop();
        }
        
        return rst;
    }
};
