#pragma once
/////////////////////////////////����ջͷ�ļ�LinkStack.h ////////////////////////////
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

//��ʼ��
void InitLStack(LinkStack *s)
{
	s->top = NULL;
	printf("��ջ��ʼ����ɣ�\n");
}
//���ջ
void setEmpty(LinkStack *s)
{
	s->top = NULL;
	printf("��ջ����գ�\n");
}

//��ջ
void pushLstack(LinkStack *s, ElemType x)
{
	StackNode *p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = x;
	p->next = s->top;
	s->top = p;
}

//��ջ
ElemType popLstack(LinkStack *s)
{
	ElemType x;
	StackNode *p;
	p = s->top;
	if (s->top == 0)
	{
		printf("ջΪ�գ����ܳ�ջ\n");
		exit(-1);
	}
	x = p->data;
	s->top = p->next;
	free(p);
	return x;
}

//ȡջ��
ElemType StackTop(LinkStack *s)
{
	if (s->top == 0)
	{
		printf("��ջΪ�գ�\n");
		exit(-1);
	}
	return s->top->data;
}

//������ջ
void Disp(LinkStack *s)
{
	printf("===============================\n");
	StackNode *p;
	int i = 1;
	p = s->top;
	if (s->top == NULL)
	{
		printf("����һ����ջ��\n");
		exit(-1);
	}
	while (p != NULL)
	{
		printf("��%d��Ԫ����%6d\n", i++, p->data);
		p = p->next;
	}
	printf("===============================\n");
}