/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/23
*
***************************************************************/
/**************************************************************
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 
***************************************************************/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *slowp = head;
        ListNode *fastp = head;
        while(fastp->next && fastp->next->next) {
            slowp = slowp->next;
            fastp = fastp->next->next;
            if(slowp == fastp) {
                return true;
            }
        }
        return false;
    }
};

int main(void) {
    Solution s = Solution();
    ListNode *head = new ListNode(1),
        *node1 = new ListNode(2),
        *node2 = new ListNode(3),
        *node3 = new ListNode(4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    cout << "head->node1->node2->node3->NULL: " << boolalpha << s.hasCycle(head) << endl;
    
    node3->next = node1;
    cout << "head->node1->node2->node3->node1: " << boolalpha << s.hasCycle(head) << endl;
    return 0;
}
