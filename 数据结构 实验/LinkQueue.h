#pragma once
//������
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

//���
void Lappend(Lqueue *q, ElemType x)
{
	Qnodetype *s;
	s = (Qnodetype*)malloc(sizeof(Qnodetype));
	s->data = x;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
}

//��ʼ������������
void initLQueue(Lqueue *q)
{
	Qnodetype *h;
	int i, x, n;
	printf("������Ҫ��������ݸ�����");
	scanf("%d", &n);
	h = (Qnodetype*)malloc(sizeof(Qnodetype));
	h->next = NULL;
	q->front = h;
	q->rear = h;
	for (i = 0; i < n; i++)
	{
		printf("��%d�������ǣ�", i + 1);
		scanf("%d", &x);
		Lappend(q, x);
	}
}

//����
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
//��ȡ��ͷԪ��
ElemType LGethead(Lqueue *q)
{
	ElemType x;
	if (q->front == q->rear) return 0;
	x = q->front->next->data;
	return x;
}
//��������
void LDisplay(Lqueue *q)
{
	int i = 0;
	Qnodetype *s;
	s = q->front;
	if (q->front == q->rear)
		printf("����Ϊ�գ�\n");
	else
		while (s != q->rear)
		{
			s = s->next;
			printf("��%d��Ԫ����:%d\n", i + 1, s->data);
			i++;
		}
}