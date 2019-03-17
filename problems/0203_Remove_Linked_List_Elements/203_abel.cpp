class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){//判定是否为空
            return nullptr;
        }//if
        ListNode *dummy = new ListNode(0);
        dummy->next = head;//
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* tmp;
        while(cur){
            if(cur->val == val){
                tmp = cur;
                pre->next = cur->next;
                delete tmp;
                cur = pre->next;
            }//if
            else{
                pre = cur;
                cur = cur->next;
            }//else
        }//while
        return dummy->next;
    }
};