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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(NULL == l1 || NULL == l2){
            return (NULL == l1) ? l2:l1;
        }
        ListNode resultList(0);
        ListNode * r = NULL;
        ListNode * p = NULL;
        ListNode * q = NULL;
        r = &resultList;
        p = l1;
        q = l2;
        int carry = 0;
        while( NULL != p || NULL != q || carry>0 ){
            if(NULL == p){
                p = new ListNode(0);
            }
            if(NULL == q){
                q = new ListNode(0);
            }
            ListNode * temp = new ListNode(0);
            int sum = 0;
            int numA = p ? p->val : 0;
            int numB = q ? q->val : 0;
            sum = (carry + numA + numB)%10;
            carry = (carry + numA + numB)/10;
            temp->val = sum;
            r->next = temp;
            r = r->next;
            p = p->next;
            q = q->next;
        }
        return resultList.next;
    }
};