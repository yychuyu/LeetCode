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
        ListNode* temp = head;
        queue<int> storage;
        while(temp){
            storage.push(temp->val);
            temp = temp->next;
        }
        ListNode* temp2 = new ListNode(0);
        ListNode* ans = temp2;
        while(!storage.empty()){
            if(storage.front()!=val){ 
                temp2->next = new ListNode(storage.front());
                temp2=temp2->next;
            }
            storage.pop();
        }
        return ans->next;
    }
};