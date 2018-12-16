#pragma once
#include"LinkStack.h"
#include"SqStack.h"

void sqstack_test()  //˳���ջ����
{
	printf("|===================||˳���ջ����||===================|\n");
	SqStack *s;
	int a, n, i;
	s = (SqStack*)malloc(sizeof(SqStack));
	InitSqStack(s);
	printf("������Ҫѹ��ջ�����ݸ�����");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("�������%d�����ݣ�", i + 1);
		scanf("%d", &a);
		Push(s, a);
	}
	printf("* * * * *˳��ջ�ı���* * * * *\n");
	OutStack(s);
	printf("* * * * *˳��ջ��ȫ���ջ* * * * *\n");
	for (i = 0; i<n; i++)
		printf("��%d��Ԫ��Ϊ%d\n", i + 1, Pop(s));
	printf("|===================||************||===================|\n");
}

void lstack_test()  //����ջ����
{
	printf("|===================||����ջ����||===================|\n");
	LinkStack *s;
	int a, n, i;
	s = (LinkStack*)malloc(sizeof(LinkStack));
	InitLStack(s);
	printf("������Ҫѹ��ջ�����ݸ�����");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("�������%d�����ݣ�", i + 1);
		scanf("%d", &a);
		pushLstack(s, a);
	}
	printf("* * * * *��ջ�ı���* * * * *\n");
	Disp(s);
	printf("* * * * *��ջ��ȫ���ջ* * * * *\n");
	for (i = 0; i<n; i++)
		printf("��%d��Ԫ��Ϊ%d\n", i + 1, popLstack(s));
	printf("|===================||**********||===================|\n");
}

int main()
{
	sqstack_test();
	lstack_test();
	system("pause");
	return 0;
}