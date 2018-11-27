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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;     // 链表为空时，返回true
        
        int cnt = 0;        // 统计链表结点个数
        ListNode *p = head;
        while (p != nullptr)
        {
            cnt++;
            p = p->next;
        }
        
        if (1 == cnt) return true;    // 链表只有一个结点时，返回true
        
        int mid = cnt / 2;            // 求链表节点个数的中位数 
        
        p = head;
        for (int i = 1; i < mid; ++i)   // p指向链表的中位数节点
        {
            p = p->next;
        }
        
        ListNode *pHead = nullptr;     // 将链表中位数后的结点进行逆置，并形成一个新的链表，用pHead指向新链表的头结点
        ListNode *pTemp = p;
        if (cnt & 1 == 1)   // 链表个数为奇数
        {
            if (pTemp->next != nullptr)     // 向后移动一个单位
                pTemp = pTemp->next;
        }
       
        while (pTemp->next != nullptr)    // 对中位数后的结点进行逆置，形成pHead指向头结点的新链表
        {
            ListNode *pr = pTemp->next;
            pTemp->next = pr->next;
            pr->next = pHead;
            pHead = pr;
        }
        
        // 将原链表的前半部分和逆置形成的新链表进行值比对
        for (int i = 1; i <= mid; ++i)
        {
            if (pHead != nullptr && head != nullptr)  // 若比对过程中，对应位置值不等，则返回false
            {
                if (pHead->val != head->val)    return false;
            }
            
            pHead = pHead->next;
            head = head->next;
        }
        
        //比对结束后，返回true.即该链表为回文数链表
        return true;
    }
};
