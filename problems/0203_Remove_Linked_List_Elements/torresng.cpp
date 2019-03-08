/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2019/03/08
*
***************************************************************/
/**************************************************************
Remove all elements from a linked list of integers that have value val.

Example:

	Input:  1->2->6->3->4->5->6, val = 6
	Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
		if(head == nullptr) return head;
		ListNode *cur = head, *pre = nullptr;
		while(cur) {
			if(cur->val == val) {
				if(pre == nullptr) {
					head = head->next;
					cur = head;
				} else {
					cur = cur->next;
					pre->next = cur;
				}
			} else {
				pre = cur;
				cur = cur->next;
			}
		}
		return head;
    }
};

void test_case1() {
	Solution s = Solution();
	ListNode *head = new ListNode(1);
	ListNode *p1 = new ListNode(2);
	ListNode *p2 = new ListNode(6);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *p6 = new ListNode(6);
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = nullptr;
	
	ListNode *res = s.removeElements(head, 6);

	ListNode *exp_head = new ListNode(1);
	ListNode *exp_p1 = new ListNode(2);
	ListNode *exp_p2 = new ListNode(3);
	ListNode *exp_p3 = new ListNode(4);
	ListNode *exp_p4 = new ListNode(5);
	exp_head->next = exp_p1;
	exp_p1->next = exp_p2;
	exp_p2->next = exp_p3;
	exp_p3->next = exp_p4;
	exp_p4->next = nullptr;

	while(res || exp_head) {
		assert(res->val == exp_head->val);
		res = res->next;
		exp_head = exp_head->next;
	}
}

int main(void) {
	test_case1();
    return 0;
}
