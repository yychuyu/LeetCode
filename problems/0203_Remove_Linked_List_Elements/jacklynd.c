struct ListNode* removeElements(struct ListNode* head, int val) 
{
        if(head == NULL)            //if(!head) ͬ��Ч������βֹͣ����
        return head;
        
        head->next = removeElements(head->next, val); //�ݹ�չ���������
        
        if(head->val == val)     //�ڵ�ΪĿ������򷵻��¸��ڵ㣬���ַ���û���ڴ棬��й©����

	return head->next;
        else
            return head;
}
