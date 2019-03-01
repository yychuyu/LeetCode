/*
  给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
  要求返回这个链表的深度拷贝。 
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL){
            return NULL;
        }
        
        for(RandomListNode* p=head;p!=NULL;p=p->next){
            RandomListNode* tmp=(RandomListNode*)malloc(sizeof(struct RandomListNode));
            tmp->label=p->label;
            tmp->next=p->next;
            p->next=tmp;            
            p=tmp;
        }
                
        for(RandomListNode* p=head;p!=NULL;p=p->next){
            RandomListNode* q=p->next;
            if( p->random == NULL ){
                q->random=NULL;
            }else{            
                q->random=(p->random)->next;
            }
            p=q;
        }
        
        RandomListNode* copy_head=head->next;
        
        RandomListNode* p=head;
        RandomListNode* q=copy_head;
        while(p&&q){
            p->next=q->next;    p=p->next;
            if(p==NULL)
                break;
            q->next=p->next;    q=q->next;
        }
        
        return copy_head;
    }
};
