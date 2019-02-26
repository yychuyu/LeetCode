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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 10

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    unsigned sizeA = 0, sizeB = 0;
    struct ListNode *pA = headA, *pB = headB;
    while(pA) {
        sizeA++;
        pA = pA->next;
    }
    while(pB) {
        sizeB++;
        pB = pB->next;
    }
    pA = headA;
    pB = headB;
    if(sizeA > sizeB) {
        unsigned distance = sizeA - sizeB;
        while(distance) {
            pA = pA->next;
            distance--;
        }
    } else if(sizeB > sizeA) {
        unsigned distance = sizeB - sizeA;
        while(distance) {
            pB = pB->next;
            distance--;
        }
    }
    while(pA && pB && pA != pB) {
        pA = pA->next;
        pB = pB->next;
    }
    return pA;
}

/*
 *  Hash
 */
struct KV {
    struct ListNode *key;
    char *value;
    struct KV *next;
};

struct HashTable {
    struct KV **kv;
    unsigned len;
};


struct HashTable* initHashTable(struct HashTable *ht) {
    ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->len = 0;
    if(ht == NULL) {
        return ht;
    }
    ht->kv = (struct KV**)malloc(sizeof(struct KV*) * HASH_TABLE_SIZE);
    if(ht->kv == NULL) {
        free(ht);
        return NULL;
    }
    memset(ht->kv, 0, HASH_TABLE_SIZE);
    ht->len = HASH_TABLE_SIZE;
    return ht;
}

unsigned hash(struct ListNode *key) {
    unsigned hash = 0;
    unsigned k = (int)key;
    while(k) {
        hash += (k % 10);
        k /= 10;
    }

    return hash;
}

int insert(struct HashTable *ht, struct ListNode *key, char *value) {
    int idx = hash(key) % HASH_TABLE_SIZE;
    struct KV *p = ht->kv[idx];
    struct KV *pre = p;
    while(p) {
        if(p->key == key) break;
        pre = p;
        p = p->next;
    }
    size_t len = strlen(value);
    if(p) {
        if(strcmp(p->value, value) != 0) {
            free(p->value);
            char *newp = (char*)malloc(sizeof(char) * len + 1);
            p->value = strncpy(newp, value, len + 1);
        }
    } else {
        struct KV *new_node = (struct KV*)malloc(sizeof(struct KV));
        new_node->next = NULL;
        new_node->key = key;
        char *newp = (char*)malloc(sizeof(char) * len + 1);
        new_node->value = strncpy(newp, value, len + 1);
        if(pre) {
            pre->next = new_node;
        } else {
            ht->kv[idx] = new_node;
        }
    }
    return 0;
}

char* getValue(struct HashTable *ht, struct ListNode *key) {
    int idx = hash(key) % HASH_TABLE_SIZE;
    struct KV *p = ht->kv[idx];
    while(p) {
        if(p->key == key) return p->value;
        p = p->next;
    }
    return NULL;
}

int main(void) {
    struct ListNode *head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head1->next = node1;
    node1->next = node2;
    node2->next = node3;
    node4->next = node5;
    node5->next = NULL;

    struct ListNode *head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head2->next = node6;
    node6->next = node7;
    node7->next = node2;

    struct HashTable* ht = NULL;
    ht = initHashTable(ht);
    insert(ht, head1, "a1");
    insert(ht, node1, "a2");
    insert(ht, node2, "c1");
    insert(ht, node3, "c2");
    insert(ht, node4, "c3");
    insert(ht, node5, "b1");
    insert(ht, node6, "b2");
    insert(ht, node7, "b3");
    printf("%s\n", getValue(ht, head1));
    return 0;

    printf("A:          a1 → a2\n");
    printf("                   ↘\n");
    printf("                    c1 → c2 → c3\n");
    printf("                   ↗\n");
    printf("B:     b1 → b2 → b3\n");

    struct ListNode *res = getIntersectionNode(head1, head2);
    //printf("%s\n", getValue(ht, res));

    return 0;
}

