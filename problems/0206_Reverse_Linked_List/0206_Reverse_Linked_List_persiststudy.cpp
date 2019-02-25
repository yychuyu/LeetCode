/***************************************************************
*   
*
*   文件名称：0206_Reverse_Linked_List_persiststudy.cpp
*   创 建 者：persiststudy
*   创建日期：2018年11月26日
*   描    述：迭代法逆置链表
*
***************************************************************/

/* 0206
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstdio>
#if 1
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
#endif 

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *newhead = NULL;
        while (head)
        {
            ListNode *next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }
        return newhead;
    }
};

void printSingleLinkListval(ListNode *head)
{
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode *head = &a;

    printSingleLinkListval(head);
    Solution s;
    head = s.reverseList(head);
    printSingleLinkListval(head);
    return 0;
}
