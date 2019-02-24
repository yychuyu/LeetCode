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
    void reorderList(ListNode* head) {
        if (nullptr == head) return;
        
        int count = 0;      // 统计链表节点个数
        ListNode *p = head;
        while (nullptr != p)
        {
            count++;
            p = p->next;
        }
        
        if (count <= 2) return;
        
        int mid = count / 2;
        ListNode *pNew = nullptr;
        p = head;
        for (int i = 1; i < mid; ++i)       // 将指针p指向中间结点
        {
            p = p->next;
        }
        
        // 指针pTemp指向中间结点的下一个节点
        // 中间结点的next指针域指向nullptr
        ListNode *pTemp = p->next;
        p->next = nullptr;
        
        // 构建以pNew为头结点的新链表
        while (nullptr != pTemp)
        {
            p = pTemp->next;
            
            pTemp->next = pNew;
            pNew = pTemp;
            
            pTemp = p;
        }
        
        
        // 将以pNew为头结点的链表和head为头结点的链表进行组合
        // 形成所求链表
        p = head;
        pTemp = pNew;
        
        while (nullptr != p)
        {
            ListNode *cur = p;
            if (nullptr != cur->next)
            {
                p = p->next;
                pNew = pNew->next;
                
                pTemp->next = cur->next;
                cur->next = pTemp;
                
                pTemp = pNew;
            }
            else
            {
                cur->next = pTemp;
                break;
            }
        }
    }
};
