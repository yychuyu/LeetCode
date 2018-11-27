/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       /* vector<ListNode*>vec;//�ռ临�Ӷȴ��ˣ�ʹ�ö���Ŀռ�
        if(head == NULL)return NULL;
        ListNode*s = head;
        while(head != NULL)
        {
            vec.push_back(head);
            head = head->next;
        }
        int size = vec.size();
        if(n < 1 || n > size)return NULL;
        if(n == 1 && s->next != NULL)
        {
            vec[size-1-n]->next = NULL;
            return s;
        }
        if(n == 1 && s->next == NULL)
        {
            return NULL;
        }
        if(n == size)
        {
            return s->next;
        }
        
        vec[size-n-1]->next = vec[size-n]->next;
        return s;*/
        //////////////////////////////////////////
        //ʱ�临�Ӷ�O��L���ռ临�Ӷ�O��1��
        if(head == NULL || n < 1)return NULL;
        ListNode*pre = head,*tmp = head;
        for(int i = 0;i < n;++i)
        {
            tmp = tmp->next;
        }
        if(tmp == NULL)
        {
            return head->next;
        }
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
            pre =  pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
