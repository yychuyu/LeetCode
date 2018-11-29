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

/**************************************************************
當鍵表為單數時，在第一個while循環結束後慢指針會指向中間的那個元素，
而快指針會指向最後一個元素，pre會指向第一個鏈表的頭結點。
例：1->2->3->4->5
執行完第一個while循環後:
    1<-2->3->4->5
       ^  ^     ^
    prev  p1    p2
所以在比較兩個分開後的鏈表時，將p2指向p1->next，將p1指向prev。


當鍵表為雙數時，在第一個while循環結束後慢指針會指向第二個鏈表的頭結點，
而快指針會指向NULL，pre會指向第一個鏈表的頭結點。
例：1-2->3->4->5->6
執行完第一個while循環後:
    1<-2->3->4->5->6
          ^  ^       ^
       prev  p1      p2
所以在比較兩個分開後的鏈表時，將p2指向p1，將p1指向prev。
***************************************************************/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *p1 = head; //slow pointer
        ListNode *p2 = head; // fast pointer
        ListNode *prev = NULL, *p = NULL;
        while(p2 && p2->next) {
            p = p1;
            p1 = p1->next;
            p2 = p2->next->next;
            p->next = prev;
            prev = p;
        }
        // p2 point to list2
        if(p2 == NULL) {
            p2 = p1;
        } else {
            p2 = p1->next;
        }
        // p1 point to list1
        p1 = prev;
        // compare
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


