struct ListNode* removeElements(struct ListNode* head, int val) 
{
        if(head == NULL)            //if(!head) 同样效果，判尾停止作用
        return head;
        
        head->next = removeElements(head->next, val); //递归展开链表调用
        
        if(head->val == val)     //节点为目标变量则返回下个节点，这种方法没释内存，有泄漏隐患

	return head->next;
        else
            return head;
}
