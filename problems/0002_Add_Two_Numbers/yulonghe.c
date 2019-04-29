/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
       struct ListNode* l3 = NULL; 
    struct ListNode* q,*tmp_l1,*tmp_l2;
    tmp_l1 = l1;    //tmp_l1用来遍历链表l1
    tmp_l2 = l2;    //遍历链表l2
    int up = 0;
    int r,add;
    
    //如果有一个是空链表
    if(l1 == NULL || l2 == NULL)
    {
        return (l1 == NULL ? l2 :l1);
    }
    
    //如果链表均不为空
    while(tmp_l1 != NULL && tmp_l2 != NULL)
    {
        struct ListNode* pnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        add = tmp_l1->val + tmp_l2->val + up;
        up = add/10;
        r = add%10;
        pnode->val = r;
        if(l3 == NULL)       //如果处理的是第一个节点
        {
            l3 = q = pnode;
        }
        else
        {
            q->next = pnode;
            q = q->next;
        }
        tmp_l1 = tmp_l1->next;
        tmp_l2 = tmp_l2->next;
    }
    
    //如果链表l1还有没处理完的数据
    while(tmp_l1!=NULL)
    {
        struct ListNode* pnode = (struct ListNode*)malloc(sizeof(struct ListNode));
  add = tmp_l1->val + up;
        up = add/10;
        r = add%10;
        pnode->val = r;
        q->next = pnode;
        q = q->next;
        tmp_l1 = tmp_l1->next;
    }
    
     //如果链表l2还有没处理完的数据
    while(tmp_l2!=NULL)
    {
        struct ListNode* pnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        add = tmp_l2->val + up;
        up = add/10;
        r = add%10;
        pnode->val = r;
        q->next = pnode;
        q = q->next;
        tmp_l2 = tmp_l2->next;
    }
    
    //处理最后的进位问题
    if(up > 0)
    {
        struct ListNode* pnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        pnode->val = up;
        q->next = pnode;
        q = q->next;
    }
    q->next = NULL;    //结束指针
    return l3;
    
}
