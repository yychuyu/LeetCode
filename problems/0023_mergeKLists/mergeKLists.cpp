/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
  * 实现多个链表的合并，可以分解为多次的两个链表合并，所以核心思想是实现两个链表的有序合并
  * /
class Solution {
public:
    ListNode* merge(ListNode*l1,ListNode*l2)
    {
        if(l1 == NULL && l2 != NULL)return  l2;
        if(l1 != NULL && l2 == NULL)return l1;
        if(l1 == NULL && l2 == NULL)return NULL;
        if(l1->val > l2->val)
        {
            ListNode*tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        ListNode*p1 = l1,*p2 = l2;
        ListNode*s = l1;
        while(l2 != NULL && l1 != NULL)
        {
            if(l1->val <= l2->val)
            {
                s = l1;
                l1 = l1->next;
            }
            else
            {
                ListNode*q = l2;
                s->next = q;
                l2 = l2->next;
                q->next = l1;
                s = q;
            }
        }
        if(l2 != NULL && l1 == NULL)
        {
            s->next = l2;
        }
        return p1;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<1)return NULL;
        if(lists.size() == 1)return lists[0];
        int i =1;
        for( i ;i < lists.size();++i)
        {
            lists[i] = merge(lists[i-1],lists[i]);
        }
        return lists[i-1];
    }
};
