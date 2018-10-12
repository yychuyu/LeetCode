
/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ?Torres Ng
*   Create Time ?2018/10/08
*
***************************************************************/
/**************************************************************
Given a sorted linked list, delete all duplicates such that each element appear only once.
Example 1:
Input: 1->1->2
Output: 1->2
Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
***************************************************************/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) {
            return head;   
        }
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur) {
            if(pre->val == cur->val) {
                ListNode* p = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete p;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
