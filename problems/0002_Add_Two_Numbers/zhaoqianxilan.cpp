#include <stdio.h>
#include "malloc.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
	int a, b, c;
	c = 0;

	struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *p = result;

	while (1){
		if (p1 == NULL && p2 == NULL){
			if (c){
				struct ListNode* t = (struct ListNode *)malloc(sizeof(struct ListNode));
				t->val = 1;
				t->next = NULL;
				p->next = t;
			}
			break;
		}
		else{
			struct ListNode* t = (struct ListNode *)malloc(sizeof(struct ListNode));
			t->next = NULL;
			p->next = t;
			p = t;
		}

		if (p1 == NULL){
			a = 0;
			b = p2->val;
			p2 = p2->next;
		}
		else if (p2 == NULL){
			a = p1->val;
			b = 0;
			p1 = p1->next;
		}
		else{
			a = p1->val;
			b = p2->val;
			p1 = p1->next;
			p2 = p2->next;
		}
		p->val = (a + b + c) % 10;
		c = (a + b + c) / 10;

	}
	return result->next;
}

int main(){
	ListNode n1, n2, n3,m1,m2,m3,*r1;
	n1.val = 2;  n1.next = &n2;
	n2.val = 2;  n2.next = &n3;
	n3.val = 3;  n3.next = NULL;

	m1.val = 8;  m1.next = NULL;

	r1 = addTwoNumbers(&n1, &m1);
	return 0;
}
