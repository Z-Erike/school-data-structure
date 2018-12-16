#pragma once
//链队列
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

#define ElemType int

typedef struct Qnode
{
	ElemType data;
	struct Qnode *next;
}Qnodetype;

typedef struct
{
	Qnodetype *front;
	Qnodetype *rear;
}Lqueue;

//入队
void Lappend(Lqueue *q, ElemType x)
{
	Qnodetype *s;
	s = (Qnodetype*)malloc(sizeof(Qnodetype));
	s->data = x;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
}

//初始化并建立队列
void initLQueue(Lqueue *q)
{
	Qnodetype *h;
	int i, x, n;
	printf("请输入要输入的数据个数：");
	scanf("%d", &n);
	h = (Qnodetype*)malloc(sizeof(Qnodetype));
	h->next = NULL;
	q->front = h;
	q->rear = h;
	for (i = 0; i < n; i++)
	{
		printf("第%d个数据是：", i + 1);
		scanf("%d", &x);
		Lappend(q, x);
	}
}

//出队
ElemType LDelete(Lqueue *q)
{
	ElemType x;
	Qnodetype *p;
	if (q->front == q->rear) return 0;
	p = q->front->next;
	x = p->data;
	q->front->next = p->next;
	free(p);
	return x;
}
//读取队头元素
ElemType LGethead(Lqueue *q)
{
	ElemType x;
	if (q->front == q->rear) return 0;
	x = q->front->next->data;
	return x;
}
//遍历队列
void LDisplay(Lqueue *q)
{
	int i = 0;
	Qnodetype *s;
	s = q->front;
	if (q->front == q->rear)
		printf("队列为空！\n");
	else
		while (s != q->rear)
		{
			s = s->next;
			printf("第%d个元素是:%d\n", i + 1, s->data);
			i++;
		}
}