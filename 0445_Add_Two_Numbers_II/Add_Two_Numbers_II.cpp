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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        stack<int> s1, s2;
    
        // 将链表l1中的数据压入栈s1
        // 将链表l2中的数据压入栈s2
        while (p1 != nullptr || p2 != nullptr)
        {
            if (p1 != nullptr)
            {
                s1.push(p1->val);
                p1 = p1->next;
            }
            
            if (p2 != nullptr)
            {
                s2.push(p2->val);
                p2 = p2->next;
            }
        }
        
        // 将栈s1、栈s2中的元素进行加法操作
        // 将相加后的元素压入栈s中
        stack<int> s;
        int carryBit = 0;
        while (!s1.empty() && !s2.empty())
        {
            int cur = s1.top() + s2.top() + carryBit;
            int digit = cur % 10;
            carryBit = cur / 10; 
            s.push(digit);
            
            s1.pop();
            s2.pop();
        }
        
        while (!s1.empty())
        {
            int cur = s1.top() + carryBit;
            int digit = cur % 10;
            carryBit = cur / 10;
            s.push(digit);
            
            s1.pop();
        }
        
        while (!s2.empty())
        {
            int cur = s2.top() + carryBit;
            int digit = cur % 10;
            carryBit = cur / 10;
            s.push(digit);
            
            s2.pop();
        }
        
        if (carryBit != 0)  s.push(carryBit);
        
        
        // 进行链表的赋值操作
        ListNode *head = nullptr;
        ListNode *p = nullptr;
        while (!s.empty())
        {
            ListNode *pTemp = new ListNode(s.top());
            if (head == nullptr)
            {
                head = pTemp;
                p = head;
            }
            else
            {
                p->next = pTemp;
                p = p->next;
            }
            
            s.pop();
        }
        
        return head;
    }
};
