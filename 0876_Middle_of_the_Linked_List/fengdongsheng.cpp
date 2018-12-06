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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        while(head){
                count++;
                head=head->next;
        }
        int count_=count/2;
        for(int i=0;i!=count_&&temp;i++){
            cout<<temp->val<<endl;
            temp=temp->next;
        }
        return temp;
    }
};
