#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//++++++++++++++++++++++++++++++++++++++++++++++顺序查找+++++++++++++++++++++++++++++++++++++++++++++++//
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];

/*顺序表查找*/
int SeqSearch(SeqList R, int n, KeyType k)
{
	int i = n;
	R[0].key = k;
	while (R[i].key != k)  //防止循环嵌套，将第一位用要查找的数填补，从后往前查找
	{
		printf("%d", R[i].key);
		i--;
	}
	printf("%d", R[i].key);
	return i;
}

//链表查找
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, *LinkList;

/*链表查找*/
int LinkSearch(LinkList L, int n, KeyType k)
{
	int i = n + 1;
	LinkList p;
	p = L;
	while (p->data != k)
	{
		i--;
		p = p->next;
	}
	return i;
}


///////////////主函数////////////////
int main()
{
	int key;
	printf("顺序查找（顺序表查找扣1 链表查找请扣2）：");
	scanf_s("%d", &key);
	if (key == 1)
	{
		SeqList R;
		int n, i;
		KeyType k;
		printf("请输入表长:");
		scanf_s("%d", &n);
		printf("请输入要查找的关键字:");
		scanf_s("%d", &k);
		printf("请输入%d个关键字:\n", n);
		for (i = 1; i <= n; i++)
			scanf_s("%d", &R[i].key);
		if ((i = SeqSearch(R, n, k)) != 0)
			printf("\n元素%d的位置是:%d\n", k, i);
		else
			printf("\n元素%d不在表中！\n", k);
	}
	else if (key == 2)
	{
		LinkList L, p;
		int i, n, k;
		L = (LinkList)malloc(sizeof(LNode));
		L->next = NULL;
		printf("请输入表长:");
		scanf_s("%d", &n);
		printf("请输入要查找的关键字:");
		scanf_s("%d", &k);
		printf("请输入%d个关键字:\n", n);
		for (i = 0; i < n; i++)
		{
			p = (LinkList)malloc(sizeof(LNode));
			scanf_s("%d", &p->data);
			p->next = L->next;
			L->next = p;
		}
		if ((i = LinkSearch(L, n, k)) != 0)
			printf("\n元素%d的位置是:%d\n", k, i);
		else
			printf("\n元素%d不在表中！\n", k);
	}
	else
		printf("？？？\n");
	system("pause");
	return 0;
}


//++++++++++++++++++++++++++++++++++++++++++++++二分查找++++++++++++++++++++++++++++++++++++++++++++++++++//
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];

/*二分查找*/
int BinSearch(SeqList R, int n, KeyType k)
{
	int left = 0, right = n - 1, mid, count = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		printf("第%d次查找：在【%d，%d】中查找到元素R[%d]:%d\n",
			++count, left, right, mid, R[mid].key);
		if (R[mid].key == k)
			return mid;
		if (R[mid].key > k)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}

///////////////主函数////////////////
int main()
{
	SeqList R;
	int n, i;
	KeyType k;
	printf("请输入表长:");
	scanf_s("%d", &n);
	printf("请输入要查找的关键字:");
	scanf_s("%d", &k);
	printf("请输入%d个关键字:\n", n);
	for (i = 1; i <= n; i++)
		scanf_s("%d", &R[i].key);
	if ((i = BinSearch(R, n, k)) != 0)
		printf("\n元素%d的位置是:%d\n", k, i);
	else
		printf("\n元素%d不在表中！\n", k);
	system("pause");
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++二叉排序树++++++++++++++++++++++++++++++++++++++//
