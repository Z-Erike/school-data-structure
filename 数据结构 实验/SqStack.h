#pragma once
///////////////////////////顺序表栈头文件SqStack.h  /////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 100
#define ElemType int

typedef struct
{
	ElemType stack[MAXNUM];
	int top;
}SqStack;

//初始化
void InitSqStack(SqStack *p)
{
	if (!p)
		printf("Eorror!\n");
	p->top = -1;
}

//入栈
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

//出栈
ElemType Pop(SqStack *p)
{
	ElemType x;
	if (p->top != -1)
	{
		x = p->stack[p->top];
		printf("出栈成功！\n");
		p->top = p->top - 1;
		return x;
	}
	else
	{
		printf("Underflow!\n");
		return 0;
	}
}

//获取栈顶元素
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

//顺序遍历栈
void OutStack(SqStack *p)
{
	int i;
	if (p->top != -1)
	{
		printf("====================================\n");
		for (i = 0; i < p->top + 1; i++)
			printf("第%d个数据元素是%6d\n", i + 1, p->stack[i]);
		printf("====================================\n");
	}
	else
		printf("这是一个空栈！\n");
}
//清空栈
void setEmpty(SqStack *p)
{
	p->top = -1;
}