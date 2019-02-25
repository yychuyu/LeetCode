#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*List;

bool isPalindrome(List plist)
{
	if(plist == NULL || plist->next == NULL)//���ͷ�ڵ�ΪNULL������ֻ��һ���ڵ㣬�������ǻ�������
	{
		return true;
	}
	Node * slow = plist;
	Node * fast = plist;

	while(fast != NULL && fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}//�������Ϊż���Ļ�����ָ��ָ��len/2,��ָ��ָ�����ڶ������

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