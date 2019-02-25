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
    //不释放
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* temp=head;
        ListNode* first=head;
        //bool mark =False;
        while(temp->next){//已经到尾部
            if(temp->next->val!=first->val){
                first->next=temp->next;
                first=temp->next;
            }
            temp=temp->next;
        }
        if(first->val==temp->val)//讨论尾部相同元素的情况
            first->next=NULL;
        return head;
    }
};
