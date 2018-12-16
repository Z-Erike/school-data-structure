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

int path[MAXSIZE];  //储存路径
void DispBST(BSTNode *b);

//插入关键字k的函数
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

//以数组A建立二叉排序树
BSTNode *CreatBST(KeyType A[], int n)
{
	BSTNode *bt = NULL;
	int i = 0, flag;
	printf("创建二叉排序树中");
	while (i < n)
	{
		flag = InsertBST(bt, A[i]);
		if (flag)
		{
			//printf(".");
			printf("第%d步，插入%d\n", i + 1, A[i]);
			DispBST(bt);
			printf("\n");
			i++;
			Sleep(200);
		}
	}
	return bt;
}

//删除节点时存在左右子树
void Delete_lr(BSTNode *p, BSTNode *r)
{
	BSTNode *q;
	if (r->rchild != NULL)
		Delete_lr(p, r->rchild);  //找到最右子树
	else
	{
		p->key = r->key;
		q = r;
		r = r->lchild;
		free(q);
	}
}

//删除二叉排序树中的p节点
void Delete(BSTNode *p)
{
	BSTNode *q;
	if (p->rchild == NULL)  //缺失右子树
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL)//缺失左子树
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else
		Delete_lr(p, p->lchild);  //都没有缺失

}

//删除bt中关键字为k的结点
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

//输出根节点到查找到的节点的路径(递归
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

//括号表示法输出二叉排序树bt
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

KeyType predt = -32767; //保存当前节点中序前趋的值

//判断bt是否为BST
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
///////////////主函数////////////////
int main()
{
	BSTNode *bt;

	int n = 10, a[] = { 4,9,0,1,8,6,3,5,2,7 };
	KeyType k = 6;
	printf("+++++++++++++++创建一棵BST树+++++++++++++\n");
	bt = CreatBST(a, n);
	printf("\nBST:");
	DispBST(bt);
	printf("\n");
	printf("判断：bt%s\n", (JudgeBST(bt) ? "是一颗BST" : "不是一颗BST"));
	Sleep(500);
	printf("++++++++++++++++查找关键字%d(递归）++++++++++++++++\n", k);
	SearchBST(bt, k);
	Sleep(500);
	printf("++++++++++++++++删除操作++++++++++++++ \n");
	printf("原BST：");
	DispBST(bt);
	printf("\n删除节点4：");
	DeleteBST(bt, 4);
	DispBST(bt);
	printf("\n删除节点5：");
	DeleteBST(bt, 5);
	DispBST(bt);
	printf("\n");
	//	printf("%d", bt->lchild->key);
	system("pause");
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++哈希表++++++++++++++++++++++++++++++++++++++++//
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <windows.h>

#define MAXSIZE 100 //最大哈希表
#define NULLKEY -1 //空关键字值
#define DELKEY -2  //定义被删关键字值
typedef int KeyType;
typedef char InfoType;

typedef struct node
{
	KeyType key;
	InfoType data;
	int count;
}HashTable[MAXSIZE];

//将k插入到哈希表中
int InsertHT(HashTable ha, int n, KeyType k, int p)
{
	int i, adr;
	adr = k % p;
	if (ha[adr].key == NULLKEY || ha[adr].key == DELKEY)
	{
		ha[adr].key = k;
		ha[adr].count = 1;
	}
	else //发生冲突时采用线性探测法解决冲突
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

//创建哈希表
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

//哈希表查找关键字k
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

//删除哈希表中关键字
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

//输出哈希表
void DispHT(HashTable ha, int n, int m)
{
	float avg = 0;
	int i;
	printf("哈希表地址：\t");
	for (i = 0; i < m; i++)
		printf("%3d", i);
	printf("\n");
	printf("哈希表关键字：\t");
	for (i = 0; i < m; i++)
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
			printf("   ");
		else
			printf("%3d", ha[i].key);
	printf("\n");
	printf("搜索次数：\t");
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
	printf("平均搜索长度ASL(%d)=%g\n", n, avg);
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
		printf("未找到%d\n", k);
	k = 77;
	printf("删除关键字%d\n", k);
	n1 = DeleteHT(ha, p, k, n);
	DispHT(ha, n1, m);
	i = SearchHT(ha, p, k);
	if (i != -1)
		printf("ha[%d].key=%d\n", i, k);
	else
		printf("未找到%d\n", k);
	printf("插入关键字%d\n", k);
	n1 = InsertHT(ha, n1, k, p);
	DispHT(ha, n1, m);
	printf("\n");
	system("pause");
	return 0;
}