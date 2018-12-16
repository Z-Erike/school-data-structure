#pragma once
//循环顺序队列
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

#define MAXNUM 10
#define ElemType int

typedef struct
{
	ElemType queue[MAXNUM];
	int front;
	int rear;
}SqQueue;

int SqAppend(SqQueue *q, ElemType x);

//建立顺序队列
void SetSqQueue(SqQueue *q)
{
	int n, i = 0, m;
	printf("请输入你要输入的数据个数：");
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf("第%d个数据是：", i + 1);
		scanf("%d", &m);
		if (!SqAppend(q, m)) break;
	}
}
//初始化
int initSqQueue(SqQueue *q)
{
	if (!q) return 0;
	q->front = -1;
	q->rear = -1;
	return 1;
}
//入队
int SqAppend(SqQueue *q, ElemType x)
{
	if ((q->rear + 1) % MAXNUM == q->front) return 0;
	q->queue[q->rear] = x;
	q->rear = (q->rear + 1) % MAXNUM;
	return 1;
}
//出队
ElemType SqDelete(SqQueue *q)
{
	ElemType x;
	if (q->front == q->rear) return 0;
	x = q->queue[q->front];
	q->front = (q->front + 1) % MAXNUM;
	return x;
}
//读取队头元素
ElemType SqGethead(SqQueue *q)
{
	ElemType x;
	if (q->front == q->rear) return 0;
	x = q->queue[q->front];
	return x;
}
//遍历队列
void SqDisplay(SqQueue *q)
{
	int s, i = 0;
	s = q->front;
	if (q->front == q->rear)
		printf("队列为空！\n");
	else
		while (s != q->rear)
		{
			printf("第%d个元素是:%d\n", i + 1, q->queue[s++]);
			i++;
		}
}