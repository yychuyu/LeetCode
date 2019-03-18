#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;				//栈顶指针
}Sqstack;
void InitStack(Sqstack *&s) {				//初始化线性栈
	s = (Sqstack *)malloc(sizeof(Sqstack));
	s->top = -1;
}
void DestroyStack(Sqstack *&s) {					//销毁顺序栈
	free(s);
}
bool StackEmpty(Sqstack *s) {					//判断栈空否
	return(s->top == -1);
}
bool Push(Sqstack *&s, ElemType e) {			//进栈
	if (s->top == MaxSize - 1)					//栈满，即栈上溢出
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(Sqstack *&s, ElemType &e) {			//出栈
	if (s->top == -1)							//栈空，即栈下溢出
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(Sqstack *s, ElemType &e) {					//取栈顶元素
	if (s->top == -1)									//栈下溢出
		return false;
	e = s->data[s->top];
	return true;
}
int main() {
	ElemType e;
	Sqstack *s;
	printf("顺序栈s的基本运算如下：\n");
	printf("  (1)初始化栈s\n");
	InitStack(s);
	printf("  (2)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (3)依次进栈顺序1,2,3,4,5\n");
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	Push(s, 5);
	printf("  (4)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (5)出栈序列：");
	while (!StackEmpty(s)) {
		Pop(s, e);
		printf("%d", e);
	}
	printf("\n");
	printf("  (6)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (7)释放栈\n");
	DestroyStack(s);
	system("pause");
	return 1;
}
	
