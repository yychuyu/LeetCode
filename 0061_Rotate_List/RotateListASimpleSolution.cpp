/*
 wechat: fanshengluck2
 email:  fansluck@qq.com
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)return head;
        
        int length=1;      
        ListNode* tempNode= head;
        while (tempNode->next){
            length++;
            tempNode=tempNode->next;
        }    
        int seg=length-k%length;
        if (seg==0 || seg==length) return head;
        tempNode->next=head;
        tempNode=head;
       for(int i=0;i<seg-1;i++){
            tempNode=tempNode->next;
        }
        
        ListNode* start=tempNode->next;
        tempNode->next=NULL;
        
        tempNode=head;
        head=start;
        return head;
        
    }
};