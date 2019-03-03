/**����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ�� 1:

����: 1->1->2
���: 1->2

ʾ�� 2:

����: 1->1->2->3->3
���: 1->2->3
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
