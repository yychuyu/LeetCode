//不合题意，但是能通过，4ms
/*
  题目:
  反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
  
  说明:
  1 ≤ m ≤ n ≤ 链表长度。

  示例:
  输入: 1->2->3->4->5->NULL, m = 2, n = 4
  输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        stack<int> stk;
        
        int idx=1;
        for(ListNode* p=head; p!=NULL; p=p->next){
            if(idx>=m && idx<=n){
                stk.push(p->val);
            }
            if(idx>=n){
                break;
            }
            
            idx++;
        }
        
        idx=1;
        for(ListNode* p=head; p!=NULL; p=p->next){
            if(idx>=m && idx<=n){
                p->val=stk.top();
                stk.pop();
            }
            if(idx>=n){
                break;
            }
            
            idx++;
        }
        
        return head;
    }
};
