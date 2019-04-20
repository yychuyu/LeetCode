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
        ListNode * temp = head; // 指向 head 的首地址
        int len = 0;
        while (temp != NULL){
            len++;
            temp = temp->next;
        }
        if (n <0 || n > len)
            return head;
        if (n == len)
            return head->next;
        
        temp = head;
        len = len - n;
        // while(len -1){
        //     temp = temp->next;
        //     len--;
        // }
        while(--len){   // --操作符放在这里更快
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
