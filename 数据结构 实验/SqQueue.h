#pragma once
//ѭ��˳�����
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

//����˳�����
void SetSqQueue(SqQueue *q)
{
	int n, i = 0, m;
	printf("��������Ҫ��������ݸ�����");
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf("��%d�������ǣ�", i + 1);
		scanf("%d", &m);
		if (!SqAppend(q, m)) break;
	}
}
//��ʼ��
int initSqQueue(SqQueue *q)
{
	if (!q) return 0;
	q->front = -1;
	q->rear = -1;
	return 1;
}
//���
int SqAppend(SqQueue *q, ElemType x)
{
	if ((q->rear + 1) % MAXNUM == q->front) return 0;
	q->queue[q->rear] = x;
	q->rear = (q->rear + 1) % MAXNUM;
	return 1;
}
//����
ElemType SqDelete(SqQueue *q)
{
	ElemType x;
	if (q->front == q->rear) return 0;
	x = q->queue[q->front];
	q->front = (q->front + 1) % MAXNUM;
	return x;
}
//��ȡ��ͷԪ��
ElemType SqGethead(SqQueue *q)
{
	ElemType x;
	if (q->front == q->rear) return 0;
	x = q->queue[q->front];
	return x;
}
//��������
void SqDisplay(SqQueue *q)
{
	int s, i = 0;
	s = q->front;
	if (q->front == q->rear)
		printf("����Ϊ�գ�\n");
	else
		while (s != q->rear)
		{
			printf("��%d��Ԫ����:%d\n", i + 1, q->queue[s++]);
			i++;
		}
}