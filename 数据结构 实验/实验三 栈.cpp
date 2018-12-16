#pragma once
#include"LinkStack.h"
#include"SqStack.h"

void sqstack_test()  //顺序表栈测试
{
	printf("|===================||顺序表栈操作||===================|\n");
	SqStack *s;
	int a, n, i;
	s = (SqStack*)malloc(sizeof(SqStack));
	InitSqStack(s);
	printf("请输入要压入栈的数据个数：");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个数据：", i + 1);
		scanf("%d", &a);
		Push(s, a);
	}
	printf("* * * * *顺序栈的遍历* * * * *\n");
	OutStack(s);
	printf("* * * * *顺序栈的全体出栈* * * * *\n");
	for (i = 0; i<n; i++)
		printf("第%d个元素为%d\n", i + 1, Pop(s));
	printf("|===================||************||===================|\n");
}

void lstack_test()  //链表栈测试
{
	printf("|===================||链表栈操作||===================|\n");
	LinkStack *s;
	int a, n, i;
	s = (LinkStack*)malloc(sizeof(LinkStack));
	InitLStack(s);
	printf("请输入要压入栈的数据个数：");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个数据：", i + 1);
		scanf("%d", &a);
		pushLstack(s, a);
	}
	printf("* * * * *链栈的遍历* * * * *\n");
	Disp(s);
	printf("* * * * *链栈的全体出栈* * * * *\n");
	for (i = 0; i<n; i++)
		printf("第%d个元素为%d\n", i + 1, popLstack(s));
	printf("|===================||**********||===================|\n");
}

int main()
{
	sqstack_test();
	lstack_test();
	system("pause");
	return 0;
}