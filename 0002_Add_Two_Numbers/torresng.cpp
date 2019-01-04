/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/17
*
***************************************************************/
/**************************************************************
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
***************************************************************/
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode tmp(0);
        ListNode *cur = &tmp;
        unsigned carry = 0;
        unsigned sum = 0;
        while(l1 || l2 || carry) {
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return tmp.next;
    }
};

void printLink(ListNode *head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << "->";
        head = head->next;
    }
}

void deleteLink(ListNode *head) {
    ListNode *p = nullptr;
    while(head) {
        p = head;
        head = head->next;
        delete p;
    }
}

void example1() {
    Solution s = Solution();
    ListNode *l1 = new ListNode(2);
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(3);
    l1->next = node1;
    node1->next = node2;
    ListNode *l2 = new ListNode(5);
    ListNode *node3 = new ListNode(6);
    ListNode *node4 = new ListNode(4);
    l2->next = node3;
    node3->next = node4;

    ListNode *res = s.addTwoNumbers(l1, l2);
    cout << "Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)" << endl;
    cout << "Output: ";
    printLink(res);
    cout << endl;

    deleteLink(l1);
    deleteLink(l2);
    deleteLink(res);
}

void example2() {
    Solution s = Solution();
    ListNode *l1 = new ListNode(1);
    ListNode *node1 = new ListNode(8);
    ListNode *l2 = new ListNode(0);
    l1->next = node1;
    
    ListNode *res = s.addTwoNumbers(l1, l2);
    cout << "Input: (1->8) + (0)" << endl;
    cout << "Output: ";
    printLink(res);
    cout << endl;
}

void example3() {
    Solution s = Solution();
    ListNode *l1 = new ListNode(9);
    ListNode *node1 = new ListNode(8);
    ListNode *l2 = new ListNode(1);
    l1->next = node1;
    
    ListNode *res = s.addTwoNumbers(l1, l2);
    cout << "Input: (9->8) + (1)" << endl;
    cout << "Output: ";
    printLink(res);
    cout << endl;

    deleteLink(l1);
    deleteLink(l2);
    deleteLink(res);
}

void example4() {
    Solution s = Solution();
    ListNode *l1 = new ListNode(0);
    ListNode *node1_1 = new ListNode(8);
    ListNode *node1_2 = new ListNode(6);
    ListNode *node1_3 = new ListNode(5);
    ListNode *node1_4 = new ListNode(6);
    ListNode *node1_5 = new ListNode(8);
    ListNode *node1_6 = new ListNode(3);
    ListNode *node1_7 = new ListNode(5);
    ListNode *node1_8 = new ListNode(7);
    l1->next = node1_1;
    node1_1->next = node1_2;
    node1_2->next = node1_3;
    node1_3->next = node1_4;
    node1_4->next = node1_5;
    node1_5->next = node1_6;
    node1_6->next = node1_7;
    node1_7->next = node1_8;
    ListNode *l2 = new ListNode(6);
    ListNode *node2_1 = new ListNode(7);
    ListNode *node2_2 = new ListNode(8);
    ListNode *node2_3 = new ListNode(0);
    ListNode *node2_4 = new ListNode(8);
    ListNode *node2_5 = new ListNode(5);
    ListNode *node2_6 = new ListNode(8);
    ListNode *node2_7 = new ListNode(9);
    ListNode *node2_8 = new ListNode(7);
    l2->next = node2_1;
    node2_1->next = node2_2;
    node2_2->next = node2_3;
    node2_3->next = node2_4;
    node2_4->next = node2_5;
    node2_5->next = node2_6;
    node2_6->next = node2_7;
    node2_7->next = node2_8;

    ListNode *res = s.addTwoNumbers(l1, l2);
    cout << "Input: (0->8->6->5->6->8->3->5->7) + (6->7->8->0->8->5->8->9->7)" << endl;
    cout << "Output: ";
    printLink(res);
    cout << endl;

    deleteLink(l1);
    deleteLink(l2);
    deleteLink(res);
}

int main(void) {
    example1();
    example2();
    example3();
    example4();
    return 0;
}

