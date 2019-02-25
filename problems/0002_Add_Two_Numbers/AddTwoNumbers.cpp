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
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        int carry = 0;                              //进位用
        while(l1 != NULL || l2 != NULL){
            int x = (l1 != NULL) ? l1 -> val :0;
            int y = ( l2 != NULL) ? l2 -> val : 0;
            int sum = carry + x + y;
            carry = sum / 10;                         //进位
            cur -> next = new ListNode(sum % 10);     //指向下一节点
            cur = cur -> next;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(carry>0)
            cur->next = new ListNode(carry);    //加上进位
        return dummyHead->next;
    }
};
