/**
*0206
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* p1 = head;
		ListNode* p2 = head->next;
		ListNode* next = head;

		p1->next = NULL;
		while (p2 != NULL) {
			next = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = next;
		}
		return p1;
	}
};