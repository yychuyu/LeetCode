ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pHead = new ListNode(0);
        ListNode *p1 = l1,*p2 = l2,*p3 = pHead;
        ListNode *pNext;
        int sum = 0,temp = 0;
        while(p1 != NULL || p2 != NULL)
        {
            int x = (p1 != NULL) ? p1->val : 0;
            int y = (p2 != NULL) ? p2->val : 0;
            sum = x + y + temp;
            temp = sum / 10;   
            p3->next = new ListNode (sum % 10);    
            p3 = p3->next;
            if(p1 != NULL)
                p1 = p1->next;
            if(p2 != NULL)
                p2 = p2->next;
        }
        if(temp == 1)
        {
            p3->next = new ListNode(1);
        }
        return pHead->next;
    }
this file is added by shyshy
