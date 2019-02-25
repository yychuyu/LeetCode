/*
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
        ListNode feakHead=ListNode(0);
        feakHead.next=head;
        
        ListNode* h1;
        ListNode* h2;
        int idx=0;
        for(ListNode* p=&feakHead; p!=NULL; p=p->next,idx++){
            if(idx==m-1){
                h1=p;
            }
            if(idx==m){
                h2=p;
            }
            if(idx>m && idx<=n){
                h2->next=p->next;
                
                p->next=h1->next;
                h1->next=p;
                
                p=h2;
            }
        }
        
        return feakHead.next;
    }
};
