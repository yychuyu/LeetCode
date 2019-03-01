/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/27
*
***************************************************************/
/**************************************************************
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
***************************************************************/

#include <iostream>
#include <vector>
#include <string>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *result, *p;
        if(l1->val <= l2->val) {
            result = p = l1;
            l1 = l1->next;
        } else {
            result = p = l2;
            l2 = l2->next;
        }
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                p->next = l1; 
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return result; 
    }
};

int main(void) {
	Solution s = Solution();
    ListNode *head1 = new ListNode(1), 
             *node1 = new ListNode(2), 
             *node2 = new ListNode(4);
    head1->next = node1;
    node1->next = node2;
    ListNode *head2 = new ListNode(1), 
             *node3 = new ListNode(3), 
             *node4 = new ListNode(4);
    head2->next = node3;
    node3->next = node4;
    
    ListNode *result = s.mergeTwoLists(head1, head2);
    while(result) {
        cout << result->val;
        result = result->next;
        if(result) cout << "->";
    }
    cout << endl;
	return 0;
}
