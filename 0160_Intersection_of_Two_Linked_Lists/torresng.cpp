/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/05
*
***************************************************************/
/**************************************************************
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    * If the two linked lists have no intersection at all, return null.
    * The linked lists must retain their original structure after the function returns.
    * You may assume there are no cycles anywhere in the entire linked structure.
    * Your code should preferably run in O(n) time and use only O(1) memory.
***************************************************************/
#include <iostream>
#include <unordered_map>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unsigned sizeA = 0, sizeB = 0;
        ListNode *p1 = headA, *p2 = headB;
        while(p1) {
            sizeA++;
            p1 = p1->next;
        }
        while(p2) {
            sizeB++;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        if(sizeA > sizeB ) {
            int distance = sizeA - sizeB;
            while(distance) {
                p1 = p1->next;
                distance--;
            }
        } else if(sizeB > sizeA) {
            int distance = sizeB - sizeA;
            while(distance) {
                p2 = p2->next;
                distance--;
            }
        }
        while(p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main(void) {
    Solution s = Solution();
    ListNode *head1 = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    head1->next = node1;
    node1->next = node2;
    node2->next = node3;

    ListNode *head2 = new ListNode(6);
    ListNode *node5 = new ListNode(7);
    ListNode *node6 = new ListNode(8);
    head2->next = node5;
    node5->next = node6;
    node6->next = node2;

    unordered_map<ListNode*, string> mapping;
    mapping.insert({head1, "a1"});
    mapping.insert({node1, "a2"});
    mapping.insert({node2, "c1"});
    mapping.insert({node3, "c2"});
    mapping.insert({node4, "c3"});
    mapping.insert({head2, "b1"});
    mapping.insert({node5, "b2"});
    mapping.insert({node6, "b3"});

    cout << "A:          a1 → a2" << endl;
    cout << "                   ↘" << endl;
    cout << "                    c1 → c2 → c3" << endl;
    cout << "                   ↗" << endl;
    cout << "B:     b1 → b2 → b3" << endl;

    ListNode *res = s.getIntersectionNode(head1, head2);
    if(res) {
        unordered_map<ListNode*, string>::iterator iter = mapping.find(res);
        cout << "Intersection Node: " << iter->second << endl;
    } else {
        cout << "Intersection Node: " << endl;
    }

    return 0;
}
