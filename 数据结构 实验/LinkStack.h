#pragma once
/////////////////////////////////链表栈头文件LinkStack.h ////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ElemType int

typedef struct stacknode
{
	ElemType data;
	stacknode *next;
}StackNode;

typedef struct
{
	stacknode *top;
}LinkStack;

//初始化
void InitLStack(LinkStack *s)
{
	s->top = NULL;
	printf("链栈初始化完成！\n");
}
//清空栈
void setEmpty(LinkStack *s)
{
	s->top = NULL;
	printf("链栈已清空！\n");
}

//入栈
void pushLstack(LinkStack *s, ElemType x)
{
	StackNode *p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = x;
	p->next = s->top;
	s->top = p;
}

//出栈
ElemType popLstack(LinkStack *s)
{
	ElemType x;
	StackNode *p;
	p = s->top;
	if (s->top == 0)
	{
		printf("栈为空！不能出栈\n");
		exit(-1);
	}
	x = p->data;
	s->top = p->next;
	free(p);
	return x;
}

//取栈顶
ElemType StackTop(LinkStack *s)
{
	if (s->top == 0)
	{
		printf("链栈为空！\n");
		exit(-1);
	}
	return s->top->data;
}

//遍历链栈
void Disp(LinkStack *s)
{
	printf("===============================\n");
	StackNode *p;
	int i = 1;
	p = s->top;
	if (s->top == NULL)
	{
		printf("这是一个空栈！\n");
		exit(-1);
	}
	while (p != NULL)
	{
		printf("第%d个元素是%6d\n", i++, p->data);
		p = p->next;
	}
	printf("===============================\n");
}