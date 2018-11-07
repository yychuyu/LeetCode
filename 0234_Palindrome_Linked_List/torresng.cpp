/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/06
*
***************************************************************/
/**************************************************************
Given a singly linked list, determine if it is a palindrome.

Example 1:

    Input: 1->2
    Output: false

Example 2:

    Input: 1->2->2->1
    Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
***************************************************************/
#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true; //only one element
        ListNode *p1 = head; //slow pointer
        ListNode *p2 = head; // fast pointer
        ListNode *pre = NULL, *p = NULL;
        while(p2 && p2->next) {
            p = p1;
            p1 = p1->next;
            p2 = p2->next;
            if(p2) p2 = p2->next;
            p->next = pre;
            pre = p;
        }
        if(p2 == NULL) {
            p2 = p1;
        } else {
            p2 = p1->next;
        }
        p1 = pre;
        while(p1) {
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

int main(void) {
    Solution s = Solution();
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    head->next = node1;
    cout << "1->2: " << boolalpha << s.isPalindrome(head) << endl;

    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    cout << "1->2->2->1: " << boolalpha << s.isPalindrome(head) << endl;

    cout << "NULL: " << boolalpha << s.isPalindrome(NULL) << endl;
    
    ListNode *node4 = new ListNode(1);
    head->val = 1;
    node1->val = 1;
    node2->val = 0;
    node3->val = 0;

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    cout << "1->1->0->0->1: " << boolalpha << s.isPalindrome(head) << endl;
    return 0;
}


