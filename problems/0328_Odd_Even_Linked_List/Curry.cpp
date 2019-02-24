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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode *oddHead = nullptr;
        ListNode *pOdd = nullptr;
        ListNode *evenHead = nullptr;
        ListNode *pEven = nullptr;
        
        int i = 0;
        ListNode *cur = head;
        while (nullptr != cur)
        {
            i++;
            ListNode *p = cur->next;
            if ( i & 1 == 1)    // i为奇数时
            {
                if (nullptr == oddHead)
                {
                    oddHead = cur;
                    pOdd = oddHead;
                    pOdd->next = nullptr;
                }
                else
                {
                    pOdd->next = cur;
                    pOdd = pOdd->next;
                    pOdd->next = nullptr;
                }
            }
            else
            {
                if (nullptr == evenHead)
                {
                    evenHead = cur;
                    pEven = evenHead;
                    pEven->next = nullptr;
                }
                else
                {
                    pEven->next = cur;
                    pEven = pEven->next;
                    pEven->next = nullptr;
                }
            }
            
            cur = p;
        }
        
        pOdd->next = evenHead;
        
        return head;
    }
};
