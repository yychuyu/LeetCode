
/***************************************************************
*   
*
*   文件名称：0092_Reverse_Linked_List_II_persiststudy.cpp
*   创 建 者：persiststudy
*   创建日期：2018年11月29日
*   描    述：区间迭代法逆置链表
*
***************************************************************/
/* 0092 
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
                                                  
说明:                                             
1 ≤ m ≤ n ≤ 链表长度。                         
                                                  
示例:                                             
                                                  
输入: 1->2->3->4->5->NULL, m = 2, n = 4           
输出: 1->4->3->2->5->NULL                         
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(NULL);
    return NULL;
}();
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


class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        int numsOfNeedReversed = n - m + 1;
        ListNode *prehead = NULL;
        ListNode *result = head;

        while (head && --m)
        {
            prehead = head;
            head = head->next;
        }
        ListNode *newMNtail = head;
        ListNode *newhead = NULL;
        while (head && numsOfNeedReversed--)
        {
            ListNode *next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }
        newMNtail->next = head;
        if (prehead)
        {
            prehead->next = newhead;
        }
        else
        {
            result = newhead;
        }
        return result;
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
    head = s.reverseBetween(head, 2, 4);
    printSingleLinkListval(head);
    return 0;
}
