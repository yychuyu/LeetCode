
class Solution {

public:

    ListNode *partition(ListNode *head, int x) {  

        //创建两个临时头结点

        ListNode *leftHead = (ListNode*)malloc(sizeof(ListNode));  

        ListNode *rightHead = (ListNode*)malloc(sizeof(ListNode)); 

        //小的都存lpre后面，其余的都存rpre后面。之后把这俩链接就可以了

        ListNode *lpre = leftHead,*rpre = rightHead;  

        while(head != NULL){  

            if(head->val < x){  

                lpre->next = head;  

                //使得lpre指向head，新的小点都查到lpre后面

                lpre = head;  

            }  

            else{  

                rpre->next = head;  

                rpre = head;  

            }  

            head = head->next;  

        }  

        rpre->next = NULL;  

        lpre->next = rightHead->next;  

        return leftHead->next;  

    }  

};
