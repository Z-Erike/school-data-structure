#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//++++++++++++++++++++++++++++++++++++++++++++++˳�����+++++++++++++++++++++++++++++++++++++++++++++++//
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];

/*˳������*/
int SeqSearch(SeqList R, int n, KeyType k)
{
	int i = n;
	R[0].key = k;
	while (R[i].key != k)  //��ֹѭ��Ƕ�ף�����һλ��Ҫ���ҵ�������Ӻ���ǰ����
	{
		printf("%d", R[i].key);
		i--;
	}
	printf("%d", R[i].key);
	return i;
}

//�������
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, *LinkList;

/*�������*/
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


///////////////������////////////////
int main()
{
	int key;
	printf("˳����ң�˳�����ҿ�1 ����������2����");
	scanf_s("%d", &key);
	if (key == 1)
	{
		SeqList R;
		int n, i;
		KeyType k;
		printf("�������:");
		scanf_s("%d", &n);
		printf("������Ҫ���ҵĹؼ���:");
		scanf_s("%d", &k);
		printf("������%d���ؼ���:\n", n);
		for (i = 1; i <= n; i++)
			scanf_s("%d", &R[i].key);
		if ((i = SeqSearch(R, n, k)) != 0)
			printf("\nԪ��%d��λ����:%d\n", k, i);
		else
			printf("\nԪ��%d���ڱ��У�\n", k);
	}
	else if (key == 2)
	{
		LinkList L, p;
		int i, n, k;
		L = (LinkList)malloc(sizeof(LNode));
		L->next = NULL;
		printf("�������:");
		scanf_s("%d", &n);
		printf("������Ҫ���ҵĹؼ���:");
		scanf_s("%d", &k);
		printf("������%d���ؼ���:\n", n);
		for (i = 0; i < n; i++)
		{
			p = (LinkList)malloc(sizeof(LNode));
			scanf_s("%d", &p->data);
			p->next = L->next;
			L->next = p;
		}
		if ((i = LinkSearch(L, n, k)) != 0)
			printf("\nԪ��%d��λ����:%d\n", k, i);
		else
			printf("\nԪ��%d���ڱ��У�\n", k);
	}
	else
		printf("������\n");
	system("pause");
	return 0;
}


//++++++++++++++++++++++++++++++++++++++++++++++���ֲ���++++++++++++++++++++++++++++++++++++++++++++++++++//
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

/*���ֲ���*/
int BinSearch(SeqList R, int n, KeyType k)
{
	int left = 0, right = n - 1, mid, count = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		printf("��%d�β��ң��ڡ�%d��%d���в��ҵ�Ԫ��R[%d]:%d\n",
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

///////////////������////////////////
int main()
{
	SeqList R;
	int n, i;
	KeyType k;
	printf("�������:");
	scanf_s("%d", &n);
	printf("������Ҫ���ҵĹؼ���:");
	scanf_s("%d", &k);
	printf("������%d���ؼ���:\n", n);
	for (i = 1; i <= n; i++)
		scanf_s("%d", &R[i].key);
	if ((i = BinSearch(R, n, k)) != 0)
		printf("\nԪ��%d��λ����:%d\n", k, i);
	else
		printf("\nԪ��%d���ڱ��У�\n", k);
	system("pause");
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++����������++++++++++++++++++++++++++++++++++++++//
