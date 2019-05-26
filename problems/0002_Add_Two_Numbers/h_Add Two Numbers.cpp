class Solution {public:
    ListNode* 	addTwoNumbers(ListNode* l1, ListNode* l2) {
   	    ListNode *p, *q, *head;
   	    head = p  = l1;
   	    q = l2;
		vector<int> v1(10,0);
		vector<int>::iterator it;
		it = v1.begin();
    	while(p != NULL && q!= NULL){
    		*it += p->val + q->val;
    		if( *it >= 10){
    			*(it + 1) = *it / 10;
    			*it = *it % 10;
			} 
			it++;
			p = p->next;
			q = q->next;
		}
		it = v1.begin(); 
		
		while(l1 != NULL){
			l1->val = *it++;
			l1 = l1->next;
		}
		
        return head;
    }
