#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*List;

bool isPalindrome(List plist)
{
	if(plist == NULL || plist->next == NULL)//如果头节点为NULL或链表只有一个节点，此链表是回文链表
	{
		return true;
	}
	Node * slow = plist;
	Node * fast = plist;

	while(fast != NULL && fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}//如果链表为偶数的话，慢指针指向len/2,快指针指向倒数第二个结点

	if(fast->next != NULL)
	{
		fast = fast->next;
	}

	Node * pre = NULL;
	while(slow != NULL)
	{
		Node *pnext = slow->next;
		slow->next = pre;
		pre = slow;
		slow = pnext;
	}

	while(head != NULL)
	{
		if(head->data != pre.data)
		{
			return false;
		}
		head = head->next;
		pre = pre->next;
	}
	return true;
}