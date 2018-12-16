#pragma once
//����ͷ�ļ� 2018.10.4
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define NUll 0
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

void TravelList(LinkList head)
{
	LinkList p;
	printf("�������е�Ԫ��Ϊ��");
	p = head->next;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}

void CreatList(LinkList L, int n)//β�巨����������
{
	int i;
	LinkList p, q;
	q = L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		printf("�������Ա�ĵ�%d��Ԫ��:", i + 1);
		scanf("%d", &p->data);
		p->next = q->next;
		q->next = p;
		q = q->next;
	}
}

void CreatList_(LinkList L, int n)//ǰ�巨����������
{
	int i;
	LinkList p;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		printf("�������Ա�ĵ�%d��Ԫ�أ�", i + 1);
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}


/*��������ĺϲ�*/
void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	pc = Lc;
	while (pa&&pb)
	{
		if (pa->data == pb->data)        //�ظ���������
			pa = pa->next;
		else if (pa->data > pb->data)
		{
			//swap(pa, pb);
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}

/*������ɾ���ظ�����*/
void DeleteSameNode(LinkList h)
{
	LinkList q, p, s;
	q = h->next;
	p = q;
	s = q;
	q = q->next;
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (p->data != q->data)
			{
				s = q;
			}
			else
			{
				s->next = q->next;
				free(q);
			}
			q = s->next;
		}
		p = p->next;
		s = p;
		/* ���Դ���
		TravelList(h);
		system("pause");
		*/
	}
}