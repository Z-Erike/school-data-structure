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
	printf("* * * * * * *����������ĺϲ�����* * * * * * *\n");
	printf("����Ҫ��������La�ĳ��ȣ�");
	scanf("%d", &n1);
	CreatList(La, n1);
	printf("* * * * * * *���������La�е�Ԫ��* * * * * * *\n");
	TravelList(La);
	Lb = (LinkList)malloc(sizeof(LNode));
	Lb->next = NULL;
	printf("����Ҫ��������Lb�ĳ��ȣ�");
	scanf("%d", &n2);
	CreatList(Lb, n2);
	printf("* * * * * * *���������Lb�е�Ԫ��* * * * * * *\n");
	TravelList(Lb);
	printf("* * * * * * *����ִ�кϲ�����* * * * * * *\n");
	Lc = La;
	MergeList_L(La, Lb, Lc);
	printf("����ϲ�֮���˳���\n");
	TravelList(Lc);
	printf("* * * * * * *ɾ��������Lc���ظ���Ԫ��* * * * * * *\n");
	DeleteSameNode(Lc);
	printf("���ɾ��֮���˳���\n");
	TravelList(Lc);
	system("pause");
	return 0;
}