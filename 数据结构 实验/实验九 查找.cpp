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
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <windows.h>

#define MAXSIZE 100
typedef int KeyType;
typedef char InfoType;

typedef struct node
{
	KeyType key;
	InfoType data;
	struct node *lchild, *rchild;
}BSTNode;

int path[MAXSIZE];  //����·��
void DispBST(BSTNode *b);

//����ؼ���k�ĺ���
int InsertBST(BSTNode* p, KeyType k)
{
	if (p == NULL)
	{
		p = (BSTNode*)malloc(sizeof(BSTNode));
		p->key = k;
		printf("%d\n", p->key);
		p->lchild = NULL;
		p->rchild = NULL;
		return 1;
	}
	else if (k == p->key)
		return 0;
	else if (k < p->key)
		InsertBST(p->lchild, k);
	else
		InsertBST(p->rchild, k);
}

//������A��������������
BSTNode *CreatBST(KeyType A[], int n)
{
	BSTNode *bt = NULL;
	int i = 0, flag;
	printf("����������������");
	while (i < n)
	{
		flag = InsertBST(bt, A[i]);
		if (flag)
		{
			//printf(".");
			printf("��%d��������%d\n", i + 1, A[i]);
			DispBST(bt);
			printf("\n");
			i++;
			Sleep(200);
		}
	}
	return bt;
}

//ɾ���ڵ�ʱ������������
void Delete_lr(BSTNode *p, BSTNode *r)
{
	BSTNode *q;
	if (r->rchild != NULL)
		Delete_lr(p, r->rchild);  //�ҵ���������
	else
	{
		p->key = r->key;
		q = r;
		r = r->lchild;
		free(q);
	}
}

//ɾ�������������е�p�ڵ�
void Delete(BSTNode *p)
{
	BSTNode *q;
	if (p->rchild == NULL)  //ȱʧ������
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL)//ȱʧ������
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else
		Delete_lr(p, p->lchild);  //��û��ȱʧ

}

//ɾ��bt�йؼ���Ϊk�Ľ��
int DeleteBST(BSTNode *bt, KeyType k)
{
	if (bt == NULL)return 0;
	else
	{
		if (k < bt->key)
			return DeleteBST(bt->lchild, k);
		else if (k > bt->key)
			return DeleteBST(bt->rchild, k);
		else
			Delete(bt);
		return 1;
	}
}

//������ڵ㵽���ҵ��Ľڵ��·��(�ݹ�
int SearchBST(BSTNode *bt, KeyType k)
{
	if (bt == NULL)return 0;
	else if (k == bt->key)
	{
		printf("%3d", bt->key);
		return 1;
	}
	else if (k < bt->key)
		SearchBST(bt->lchild, k);
	else
		SearchBST(bt->rchild, k);
	printf("%3d", bt->key);
}

//���ű�ʾ���������������bt
void DispBST(BSTNode *bt)
{
	//	printf("!!!!!!!!!\n");
	if (bt != NULL)
	{
		printf("%d", bt->key);
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			printf("(");
			DispBST(bt->lchild);
			if (bt->rchild != NULL)
				printf(",");
			DispBST(bt->rchild);
			printf(")");
		}
	}
}

KeyType predt = -32767; //���浱ǰ�ڵ�����ǰ����ֵ

//�ж�bt�Ƿ�ΪBST
int JudgeBST(BSTNode *bt)
{
	int b1, b2;
	if (bt == NULL)
		return 1;
	else
	{
		b1 = JudgeBST(bt->lchild);
		if (b1 == 0 || predt >= bt->key)
			return 0;
		predt = bt->key;
		b2 = JudgeBST(bt->rchild);
		return b2;
	}
}
///////////////������////////////////
int main()
{
	BSTNode *bt;

	int n = 10, a[] = { 4,9,0,1,8,6,3,5,2,7 };
	KeyType k = 6;
	printf("+++++++++++++++����һ��BST��+++++++++++++\n");
	bt = CreatBST(a, n);
	printf("\nBST:");
	DispBST(bt);
	printf("\n");
	printf("�жϣ�bt%s\n", (JudgeBST(bt) ? "��һ��BST" : "����һ��BST"));
	Sleep(500);
	printf("++++++++++++++++���ҹؼ���%d(�ݹ飩++++++++++++++++\n", k);
	SearchBST(bt, k);
	Sleep(500);
	printf("++++++++++++++++ɾ������++++++++++++++ \n");
	printf("ԭBST��");
	DispBST(bt);
	printf("\nɾ���ڵ�4��");
	DeleteBST(bt, 4);
	DispBST(bt);
	printf("\nɾ���ڵ�5��");
	DeleteBST(bt, 5);
	DispBST(bt);
	printf("\n");
	//	printf("%d", bt->lchild->key);
	system("pause");
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++��ϣ��++++++++++++++++++++++++++++++++++++++++//
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <windows.h>

#define MAXSIZE 100 //����ϣ��
#define NULLKEY -1 //�չؼ���ֵ
#define DELKEY -2  //���屻ɾ�ؼ���ֵ
typedef int KeyType;
typedef char InfoType;

typedef struct node
{
	KeyType key;
	InfoType data;
	int count;
}HashTable[MAXSIZE];

//��k���뵽��ϣ����
int InsertHT(HashTable ha, int n, KeyType k, int p)
{
	int i, adr;
	adr = k % p;
	if (ha[adr].key == NULLKEY || ha[adr].key == DELKEY)
	{
		ha[adr].key = k;
		ha[adr].count = 1;
	}
	else //������ͻʱ��������̽�ⷨ�����ͻ
	{
		i = 0;
		do
		{
			adr = (adr + 1) % p;
			i++;
		} while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY);
		ha[adr].key = k;
		ha[adr].count = i;
	}
	n++;
	return n;
}

//������ϣ��
void CreateHT(HashTable ha, KeyType x[], int n, int m, int p)
{
	int i, n1 = 0;
	for (i = 0; i < m; i++)
	{
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}
	for (i = 0; i < n; i++)
		n1 = InsertHT(ha, n1, x[i], p);
}

//��ϣ����ҹؼ���k
int SearchHT(HashTable ha, int p, KeyType k)
{
	int i = 0, adr;
	adr = k % p;
	while (ha[adr].key != NULLKEY && ha[adr].key != k)
	{
		i++;
		adr = (adr + 1) % p;
	}
	if (ha[adr].key == k)
		return adr;
	else
		return -1;
}

//ɾ����ϣ���йؼ���
int DeleteHT(HashTable ha, int p, int k, int n)
{
	int adr;
	adr = SearchHT(ha, p, k);
	if (adr != -1)
	{
		ha[adr].key = DELKEY;
		n--;
		return n;
	}
	else
		return 0;
}

//�����ϣ��
void DispHT(HashTable ha, int n, int m)
{
	float avg = 0;
	int i;
	printf("��ϣ���ַ��\t");
	for (i = 0; i < m; i++)
		printf("%3d", i);
	printf("\n");
	printf("��ϣ��ؼ��֣�\t");
	for (i = 0; i < m; i++)
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
			printf("   ");
		else
			printf("%3d", ha[i].key);
	printf("\n");
	printf("����������\t");
	for (i = 0; i < m; i++)
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
			printf("   ");
		else
			printf("%3d", ha[i].count);
	printf("\n");
	for (i = 0; i < m; i++)
		if (ha[i].key != NULLKEY && ha[i].key != DELKEY)
			avg = avg + ha[i].count;
	avg = avg / n;
	printf("ƽ����������ASL(%d)=%g\n", n, avg);
}
int main()
{
	int x[] = { 16,74,60,43,54,90,46,31,29,88,77 };
	int n = 11, m = 13, p = 13, i, k = 29, n1;
	HashTable ha;
	CreateHT(ha, x, n, m, p);
	printf("\n");
	DispHT(ha, n, m);
	i = SearchHT(ha, p, k);
	if (i != -1)
		printf("ha[%d].key=%d\n", i, k);
	else
		printf("δ�ҵ�%d\n", k);
	k = 77;
	printf("ɾ���ؼ���%d\n", k);
	n1 = DeleteHT(ha, p, k, n);
	DispHT(ha, n1, m);
	i = SearchHT(ha, p, k);
	if (i != -1)
		printf("ha[%d].key=%d\n", i, k);
	else
		printf("δ�ҵ�%d\n", k);
	printf("����ؼ���%d\n", k);
	n1 = InsertHT(ha, n1, k, p);
	DispHT(ha, n1, m);
	printf("\n");
	system("pause");
	return 0;
}