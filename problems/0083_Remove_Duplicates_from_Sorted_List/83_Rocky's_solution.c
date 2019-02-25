/**
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 示例 1:
 * 输入: 1->1->2
 * 输出: 1->2
 * 示例 2:
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 */
#include <stdio.h>
#include <stdlib.h>
 
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (NULL == head)
        return head;
    struct ListNode* p = head;
    while (NULL != p->next) {
        if (p->val == p->next->val) {
            p->next = p->next->next;
        }
        else {
            p = p->next;
        }
    }
    return head;
}

int main(void) {
	int input[] = {1, 1, 1, 2, 2, 2, 3, 4, 5, 8, 8};
	struct ListNode *head, *p;
	int length, i;
	
	length = sizeof(input) / sizeof(int);
	head = (struct ListNode *) malloc(sizeof(struct ListNode));
	p = head;
	
	/* Create a list and delete duplicates*/
	for (i = 0; i < length - 1; i++) {
		p->val = input[i];
		p->next = (struct ListNode *) malloc(sizeof(struct ListNode));
		p = p->next;
	}
	p->val = input[length - 1];
	p->next = NULL;
	p = deleteDuplicates(head);
	
	/* Print the result */
	while (NULL != p->next) {
		printf("%d->", p->val);
		p = p->next;
	}
	printf("%d\n\n", p->val);
	
	system("pause");
	return 0;
}