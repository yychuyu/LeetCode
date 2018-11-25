/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void finalinsernum(struct ListNode* l1,int len)
{
    int i = 0;
    struct ListNode* p = l1;
    struct ListNode* fnNode  = malloc(sizeof(struct ListNode));
    fnNode->val = 1;
    fnNode->next = NULL;
    
    while(1)
    {
        i++;
        if(i == len-1)
        {
            p->next = fnNode;
            break;
        }
           
        p = p->next;
        
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int val = 0,len = 0;
    struct ListNode* l1_back = l1;
    struct ListNode* l2_back = l2;

    while(1)
    {
        len++;
        if(l1==NULL)
        {
            if(val > 9)
            {
                if(l2==NULL)
                {
                    finalinsernum(l2_back,len);
                }              
                else
                {              
                    while(l2!=NULL)
                    {
                        if(val > 9)
                        {
                            l2->val += 1;
                            if(l2->val > 9)
                            {
                            len++;
                            l2->val = 0;
                            l2 = l2->next;
                            if(l2==NULL)
                            {
                               finalinsernum(l2_back,len);
                               break;
                            }
                               
                        }else
                            break;  
                        }
                        else
                            break;
                                        
                    }
                }
                  
            }            
            return l2_back;
        } 
        
        if(l2==NULL)
        {
          if(val > 9)
          {
               if(l1==NULL)
                {
                    finalinsernum(l1_back,len);
                }              
                else
                {              
                    while(l1!=NULL)
                    {
                        if(val > 9)
                        {
                            l1->val += 1;
                            if(l1->val > 9)
                            {
                                len++;
                                l1->val = 0;
                                l1 = l1->next;
                                if(l1==NULL)
                                {
                                   finalinsernum(l1_back,len);
                                   break;
                                }

                            }else
                                break; 
                        }else
                            break;

                    }
                 }
           }
            return l1_back;
        }
        
        if(val > 9)
        {
            l2->val += 1;
        }
        
        val = l1->val + l2->val;
//        printf("val = %d\n",val);
        l1->val = val%10;
        l2->val = val%10;

        l1 = l1->next;
        l2 = l2->next;
        
    }
    
}