/*
 * add_two_numbers.c
 *
 * April 6,2019 
 *
 * Author:lkk789@aliyun.com
 *
 */
 
 /*

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

 */
 
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *p1=l1;
    struct ListNode *p2=l2;
    struct ListNode *result=(struct ListNode *)malloc(sizeof(struct ListNode));
    result->val=0;
 
    struct ListNode *p=NULL;
    int c=0;
    while (p1!=NULL || p2!=NULL || c!=0)
    {
        if(p == NULL)
        {
            p=result;
        }
        else
        {
            p->next=(struct ListNode*)malloc(sizeof(struct ListNode)); //这里写成p会出错
            p->next->val=0;
            p=p->next;
        }
        int a=(p1==NULL ? 0:p1->val);
        int b=(p2==NULL ? 0:p2->val);
        int s=(a+b+c)%10;
        c=(a+b+c)/10;
        p->val=s;     
        p->next=NULL;
   
        p1=(p1==NULL ? NULL : p1->next);
        p2=(p2==NULL ? NULL : p2->next);
 
    }
    return result;
} 


 