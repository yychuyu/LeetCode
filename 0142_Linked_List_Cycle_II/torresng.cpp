
/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/16
*
***************************************************************/
/**************************************************************
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
***************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) {
            return NULL;
        }
        size_t len = 1;
        ListNode *slow = head->next;
        while(slow && slow != head) {
            slow = slow->next;
            len++;
        }
        cout << "slow: " << slow->val << endl;
        ListNode *fast = head;
        do {
            fast = fast->next;
            if(!fast) return NULL;
            fast = fast->next;
            slow = slow->next;
        } while(fast && (slow != fast));
        cout << "len: " << len << endl;

        // has circle
        size_t circle_len = 0;
        do {
            circle_len++;
            slow = slow->next;
        } while(slow != fast) ;

        while(len != circle_len) {
            head = head->next;
            len--;
        }
        
        return head;
    }
};

int main(void) {
    ListNode *head = new ListNode(3);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(0);
    ListNode *p3 = new ListNode(-4);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p1;
    Solution s;
    ListNode *p = s.detectCycle(head);
    cout << "value: " << p->val << endl;

    return 0;
}
