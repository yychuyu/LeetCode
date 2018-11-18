/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//反转链表
struct ListNode* LinkListReversion(struct ListNode* pHead)
{
	struct ListNode* p ;
    struct ListNode* q ;
    struct ListNode* r ;
	p = pHead;
	q = p->next;
	pHead->next = NULL;
	while (q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	return p;
}


bool isPalindrome(struct ListNode* head) {
    int len = 0;
    struct ListNode* backhead = head;
    struct ListNode* Reversionhead=head;
    int i = 0;
    
    while(head != NULL)
    {
        head = head->next;
        len++;
    }

    if(len == 0)
        return true;
    
    //利用反转链表的解法，降低空间复杂度，但会改变链表的结构
    for(i = 0;i < len/2;i++)
    {
        Reversionhead = Reversionhead->next;
    }
        
    Reversionhead = LinkListReversion(Reversionhead);//反转单链表
    for(i = 0;i < len/2;i++)
    {
        if(Reversionhead->val != backhead->val)
            return false;
         backhead = backhead->next;
         Reversionhead = Reversionhead->next;
    }
/*    
    //暴力解法，空间复杂度为O（n）
    int val[len];
    int i = 0;
    
    while(backhead != NULL)
    {
        val[i] = backhead->val;
        backhead = backhead->next;
        i++;
    }
    
    for(i = 0;i < len/2;i++)
    {
        if(val[i] != val[len-i-1])
            return false;
    }
  */  
    return true;
}