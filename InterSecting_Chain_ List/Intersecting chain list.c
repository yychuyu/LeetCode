struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
     
     //有一个列表为空，则交点为空
        if(headA==NULL||headB==NULL){
            return NULL;
        }
        //头节点就相等
        if(headA==headB) return headA;
        struct ListNode* pA = headA, *pB = headB;
        int count = 0;
        while(pA!=pB&&count<3){                        
            if(pA->next==NULL) {
                pA = headB;
                count++;
            }
            else pA = pA->next;
            if(pB->next==NULL){                
                pB = headA;
                count++;
            }
            else pB = pB->next;            
        }
        if(pA==pB) return pA;
        else return NULL;
    }
