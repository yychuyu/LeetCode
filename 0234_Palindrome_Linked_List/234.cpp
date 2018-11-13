/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    思路：递归算法：
    T(n)=T(n-1)+O(1);
    在本例子中，本质上是比较一个链表数组中处于对称位置的两个node值是否相同。这个算法每个对称位置检查了两次；
    而空间复杂度为O(1)
*/
class Solution {
public:
    ListNode** temp;
    bool isPalindrome(ListNode* head) {
        temp=&head;
        return isP(head);
    }
    bool isP(ListNode* head){
        
        if (head==NULL) return true; 
               
        bool re=isP(head->next); 
        if (re==false) return false;
        if ((*temp)->val!=(head->val)) return false;
        *temp=(*temp)->next;
        return true ;      
    }
    
};