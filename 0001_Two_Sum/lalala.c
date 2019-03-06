
#include<stdio.h>
#include<malloc.h>
#define Maxsize 50
#define NumType int
typedef struct
{
	NumType data[Maxsize];	//存放数据
	int length;		//存放长度
}SqList;
void InitList(SqList *L)
{
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
int ListInsert(SqList *L,int i,NumType e)
{
	int j;
	if (i< 1||i>L->length+1)
		return 0;
	i--;
	for (j=L->length;j>i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;
}
void LocateNum(SqList *L,NumType e, int* a)
{
	int i,j;
	for(i=0;i<L->length;i++)
		for(j=i+1;i<L->length;j++)
			if(L->data[i]+L->data[j]==e)
			{
				int b[2] = {i,j};
				a=b;
			}
}
void DestroyList(SqList *L)
{
	free(L);
}
void main()
{
	SqList *L;
	int *a;
	InitList(L);
	ListInsert(L,1,2);
        ListInsert(L,2,7);
        ListInsert(L,3,11);
        ListInsert(L,4,15);
	LocateNum(L,9,a);
	printf("序号为[%d,%d]",a[0],a[1]);
	DestroyList(L);
}
