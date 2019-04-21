/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
/* 最笨算法之两次遍历法*/
//特别注意的是给的链表是无头结点的，TMD就这一点告诉我搞清楚题意有多重要 
    struct ListNode* pt = (struct ListNode *)malloc(sizeof(struct ListNode));
    pt->next = head;
    struct ListNode* last = head;
    int count= 0;
    while(last!=NULL)//求出链表长度为count
    {
        ++count;
        last = last->next;
    }
    count-=n;
    last = pt;    
    while(count>0) //跳转到要删除节点的前继节点
    {
        --count;
        last = last->next;
    }
    struct ListNode* tmp=last->next;//执行删除操作
    last->next = tmp->next;
    free(tmp);
    return pt->next; //返回值需特别注意，不可返回head，因为head若删除了第一个节点则指向NULL，此时会发生堆……
}
