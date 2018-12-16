#pragma once
///////////////////////////˳���ջͷ�ļ�SqStack.h  /////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 100
#define ElemType int

typedef struct
{
	ElemType stack[MAXNUM];
	int top;
}SqStack;

//��ʼ��
void InitSqStack(SqStack *p)
{
	if (!p)
		printf("Eorror!\n");
	p->top = -1;
}

//��ջ
void Push(SqStack *p, ElemType x)
{
	if (p->top < MAXNUM - 1)
	{
		p->top = p->top + 1;
		p->stack[p->top] = x;
	}
	else
		printf("Overflow!\n");
}

//��ջ
ElemType Pop(SqStack *p)
{
	ElemType x;
	if (p->top != -1)
	{
		x = p->stack[p->top];
		printf("��ջ�ɹ���\n");
		p->top = p->top - 1;
		return x;
	}
	else
	{
		printf("Underflow!\n");
		return 0;
	}
}

//��ȡջ��Ԫ��
ElemType GetTop(SqStack *p)
{
	ElemType x;
	if (p->top != -1)
	{
		x = p->stack[p->top];
		return x;
	}
	else
	{
		printf("Unerflow!\n");
		return 0;
	}
}

//˳�����ջ
void OutStack(SqStack *p)
{
	int i;
	if (p->top != -1)
	{
		printf("====================================\n");
		for (i = 0; i < p->top + 1; i++)
			printf("��%d������Ԫ����%6d\n", i + 1, p->stack[i]);
		printf("====================================\n");
	}
	else
		printf("����һ����ջ��\n");
}
//���ջ
void setEmpty(SqStack *p)
{
	p->top = -1;
}