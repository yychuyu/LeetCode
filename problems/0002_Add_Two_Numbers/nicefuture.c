#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* NewNode(int val)
{
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));

    p->val = val;
    p->next = NULL;

    return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *p1 = l1, *p2 = l2, *p3 = NULL, *head = NULL, *rear = NULL;
    int num, num1, num2, flag = 0;  //flag表示当前要进的位数

    while (1) {
        if (p1 == NULL && p2 == NULL && flag == 0) break;
        //计算数据
        num1 = (p1 == NULL) ? 0 : p1->val;
        num2 = (p2 == NULL) ? 0 : p2->val;
        num = num1 + num2;

        if (flag > 0) {
            num += flag;
        }
        if (num > 9) {
            flag = num/10;
            num %= 10;
        } else {
            flag = 0;  //不然要成为死循环
        }
        p3 = NewNode(num);
        
        //添加数据
        if (head == NULL) head = rear = p3;
        else {
            rear->next = p3;
            rear = rear->next;
        }

        //指针后移
        if (p1 != NULL) p1 = p1->next;
        if (p2 != NULL) p2 = p2->next;
    }

    return head;
}

/*这种方式并不可取……它平台测试的时候给了个30位数来算。。
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    long num1 = 0, num2 = 0, num3 = 0, weight;
    struct ListNode* p = NULL;

    weight = 1;
    p = l1;
    while (p != 0) {
        num1 += ((p->val)*weight);
        weight *= 10;
        p = p->next;
    }

    weight = 1;
    p = l2;
    while (p != 0) {
        num2 += ((p->val)*weight);
        weight *= 10;
        p = p->next;
    }

    num3 = num2+num1;
    weight = 10;

    struct ListNode *head = NULL, *rear = NULL;
    long num = -1;

    while(num != num3) {
        num = num3 % weight;
        struct ListNode* p = NewNode((int)(num/(weight/10)));
        if (head == NULL) head = rear = p;
        else {
            rear->next = p;
            rear = rear->next;
        }
        weight *= 10;
    }

    return head;
}*/
