#include"LinkList.h"

void swap(LinkList &a, LinkList &b)
{
	LinkList c;
	c = a;
	a = b;
	b = c;
}

int main()
{
	LinkList La, Lb, Lc, p;
	int n1, n2;
	La = (LinkList)malloc(sizeof(LNode));
	La->next = NUll;
	printf("* * * * * * *两个单链表的合并操作* * * * * * *\n");
	printf("输入要建立链表La的长度：");
	scanf("%d", &n1);
	CreatList(La, n1);
	printf("* * * * * * *输出单链表La中的元素* * * * * * *\n");
	TravelList(La);
	Lb = (LinkList)malloc(sizeof(LNode));
	Lb->next = NULL;
	printf("输入要建立链表Lb的长度：");
	scanf("%d", &n2);
	CreatList(Lb, n2);
	printf("* * * * * * *输出单链表Lb中的元素* * * * * * *\n");
	TravelList(Lb);
	printf("* * * * * * *下面执行合并操作* * * * * * *\n");
	Lc = La;
	MergeList_L(La, Lb, Lc);
	printf("输出合并之后的顺序表：\n");
	TravelList(Lc);
	printf("* * * * * * *删除单链表Lc中重复的元素* * * * * * *\n");
	DeleteSameNode(Lc);
	printf("输出删除之后的顺序表：\n");
	TravelList(Lc);
	system("pause");
	return 0;
}