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
        ListNode* p = head;
        // 当头为空指针时
        if (p == NULL) return NULL;
        
        // 当头只有一个结点，并且为要删除的值时
        if (p->val == val && p->next == NULL){
            //free (p);
            return NULL;
        }
        
        for (ListNode* q = p->next; q != NULL; q = q->next){     
            if (q->val == val){
                p->next = q->next;
                //free(q);
                q = p;  
            }else{
                p = p->next;
            }
        }
        if (head->val == val){
            head = head->next;
        }
        return head;  
    }
};
