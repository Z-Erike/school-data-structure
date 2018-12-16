#pragma once
//线性表头文件SqList.h         18.9.28
#include<stdio.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFERFLOW -1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;



/*顺序表的初始化*/
Status InitList_Sq(SqList *L)
{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) return (OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

/*顺序表的建立*/
Status CreatList_Sq(SqList *L, int n)
{
	int i;
	L->length = n;
	printf("请输入%d个整数;\n", n);
	for (i = 0; i < n; i++)
	{
		printf("第%d个元素为：", i + 1);
		scanf("\n%d", &L->elem[i]);
	}
	return OK;
}

/*顺序表的输出*/
void TraverList_Sq(SqList *L)
{
	int i;
	printf("顺序表的长度为：%d\n", L->length);
	printf("顺序表中的元素为：");
	for (i = 0; i < L->length; i++)
		printf("%5d", L->elem[i]);
	printf("\n");
}

/*顺序表的插入*/
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	ElemType *newbase, *q, *p;
	if (i<1 || i>L->length + 1)
		return ERROR;
	if (L->length >= L->listsize)
	{
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			return OVERFLOW;
		L->elem = newbase;
		L->length = +LISTINCREMENT;
	}//if
	q = &(L->elem[i = 1]);
	for (p = &(L->elem[L->length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L->length;
	return OK;
}

/*顺序表的删除*/
Status ListDelete_Sq(SqList *L, int i, ElemType &e)
{
	ElemType *q, *p;
	if (i<1 || i>L->length)return ERROR;
	if (L->length == 0)return ERROR;
	e = L->elem[i - 1];
	p = &(L->elem[i - 1]);
	for (q = &(L->elem[L->length - 1]); p < q; ++p)
		*p = *(p + 1);
	*q = e;
	--L->length;
	return OK;
}