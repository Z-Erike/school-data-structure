#pragma once
//链表头文件 2018.10.4
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
	printf("单链表中的元素为：");
	p = head->next;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}

void CreatList(LinkList L, int n)//尾插法创建单链表
{
	int i;
	LinkList p, q;
	q = L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		printf("输入线性表的第%d个元素:", i + 1);
		scanf("%d", &p->data);
		p->next = q->next;
		q->next = p;
		q = q->next;
	}
}

void CreatList_(LinkList L, int n)//前插法创建单链表
{
	int i;
	LinkList p;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		printf("输入线性表的第%d个元素：", i + 1);
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}


/*有序单链表的合并*/
void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	pc = Lc;
	while (pa&&pb)
	{
		if (pa->data == pb->data)        //重复数字跳过
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

/*单链表删除重复数据*/
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
		/* 测试代码
		TravelList(h);
		system("pause");
		*/
	}
}