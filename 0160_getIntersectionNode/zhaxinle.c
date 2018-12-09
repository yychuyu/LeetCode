/**
 
例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

在节点 c1 开始相交。

 

注意：

    如果两个链表没有交点，返回 null.
    在返回结果后，两个链表仍须保持原有的结构。
    可假定整个链表结构中没有循环。
    程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

 
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    struct ListNode*h1 = NULL;
    struct ListNode*h2 = NULL;
    struct ListNode*p = headA;
    struct ListNode*q =headB;
    
    if(q == NULL || p == NULL)
    {
        return NULL;
    }
    else
    {
        int m=1,n=1;
        while(p->next)
        {
            m++;
            p = p->next;
        }
        while(q->next)
        {
            n++;
            q = q->next;
        }
        if(p != q)
        {
            return NULL;
        }
        if(m > n)
        {
            h1 = headA;
            h2 = headB;
        }
        else
        {
            h1 = headB;
            h2 = headA;
        }
        
        m = abs(m-n);
        for(int i=0;i<m;++i)
        {
            h1 = h1->next;
        }
        
        while(h1 != h2)
        {
            h1 = h1->next;
            h2 = h2->next;
        }
        return h1;
        
    }
    
    
}
