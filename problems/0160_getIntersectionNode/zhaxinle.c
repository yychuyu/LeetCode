/**
 
���磬�������������

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3

�ڽڵ� c1 ��ʼ�ཻ��

 

ע�⣺

    �����������û�н��㣬���� null.
    �ڷ��ؽ���������������뱣��ԭ�еĽṹ��
    �ɼٶ���������ṹ��û��ѭ����
    ���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档

 
 
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
