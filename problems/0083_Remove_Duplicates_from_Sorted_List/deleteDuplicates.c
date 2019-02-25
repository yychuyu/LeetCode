/**给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2

示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
**/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    if(NULL == head)return NULL;
    struct ListNode*phead = head;
    struct ListNode*pnext = head->next;

    while( NULL != pnext)
    {
        if(pnext->val == phead->val)
        {
            phead->next = pnext->next;
            free (pnext);
            pnext = phead->next;
        }
        else
        {
            phead = pnext;
            pnext = phead->next;
        }
    }
    return head;
}
