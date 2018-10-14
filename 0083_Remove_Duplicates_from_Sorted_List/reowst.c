#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}listnode;
listnode * createlist(int a[],int n)
{
	listnode *head, *q;
	int i = 0;
	head = (listnode *)malloc(sizeof(listnode));
	head->next = NULL;
	q = head;
	while(i < n)
	{
		q->next = (listnode *)malloc(sizeof(listnode));
		q = q->next;
		q->data = a[i];
		q->next = NULL;
		i++;
	}
	return head;
}
void RemoveDuplicates(listnode *head)
{
	listnode *p, *q;
	p = head->next;
	if(!p) return;
	q = p->next;
	while(q)
	{
		if(p->data == q->data)
		{
			p->next = q->next;
			free(q);
		}
		else p = q;
		q = p->next;
	}
	return;
}
void printlist(listnode *head)
{
	while(head->next)
	{
		head = head->next;
		printf("%d	",head->data);
	}
	return;
}
int main()
{
	int a[]={0,0,1,2,2,3};
	int n;
	listnode *head;
	n = sizeof(a)/sizeof(int);
	head = createlist(a,n);
	RemoveDuplicates(head);
	printlist(head);
	return 0;
}
