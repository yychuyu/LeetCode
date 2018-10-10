/*
 * author: NiceFuture
 * time  : 2018.10.10
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

void deleteNextNode(struct ListNode* node) 
{
    struct ListNode* p = node->next;

    node->next = node->next->next;
    free(p);
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* p = head;

    if (p != NULL) {
        while (NULL != p->next) {
            if (p->next->val == p->val) {
                deleteNextNode(p);
            } else {
                p = p->next;
            }
        }
    }

    return head;
}
