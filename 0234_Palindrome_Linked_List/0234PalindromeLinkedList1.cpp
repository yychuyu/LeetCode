/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
*解题思路：1->2->2->1
*       1.遍历中间节点,区分左右链表
*       2.反转链表
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode *pslow = head, *pfast = head;
        if(!head)
            return true;
        //1.slow移动到中间节点
        while (pfast&&pfast->next&&pfast->next->next) {
            pslow = pslow->next;
            pfast = pfast->next->next;
        }
        //2.反转链表
        pslow->next = reverse(pslow->next);
        ListNode *pre = head;
        while (pslow->next) {
            pslow = pslow->next;
            if (pre->val != pslow->val) return false;
            pre = pre->next;
        } 
        return true;

    }
    ListNode* reverse(ListNode* head){
        if(!head)
            return NULL;
        ListNode* q = head->next;   //下一节点
        ListNode* p = head;         //前一节点
        ListNode* pr;
        head->next = NULL;  //头节点指向空
        while(q){
            pr = q->next;   //先保存节点值
            q->next = p;    //指向q
            p = q;          //指向反转节点     
            q = pr;         //指向下一节点
        }
        head = p;           //最后q必然指向NULL，所以返回了p作为新的头指针 
        return head;
   }
    
};
