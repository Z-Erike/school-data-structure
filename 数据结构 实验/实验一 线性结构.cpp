#include<stdio.h>
#include"SqList.h"
#include<stdlib.h>

void main()
{
	int n, i;
	ElemType x;
	SqList a;
	SqList *l = &a;
	if (!InitList_Sq(l))
		printf("��Ǹ��˳����ʼ��ʧ�ܣ�����\n");
	else
	{
		/*˳�������뼰����*/
		printf("��ϲ�㣬˳����ʼ���ɹ���\n");
		printf("* * * * * * *����˳���* * * * * * *\n");
		printf("������Ҫ������˳����ȣ�");
		scanf("%d", &n);
		CreatList_Sq(l, n);
		printf("* * * * * * *���˳���* * * * * * *\n");
		TraverList_Sq(l);
		/*˳������*/
		printf("* * * * * * *�������˳���Ĳ������* * * * * * *\n");
		printf("���������λ��i��");
		scanf("%d", &i);
		printf("������Ҫ�����Ԫ�أ�");
		scanf("%d", &x);
		if (ListInsert_Sq(l, i, x))
		{
			printf("��ϲ�㣬��������ɹ���\n");
			printf("* * * * * * *���˳���* * * * * * *\n");
			TraverList_Sq(l);
		}//if
		else
			printf("���ź����������ṩ�Ĳ���λ�ò��Ϸ�������˳���Ĳ���ʧ�ܣ�����\n");
		/*˳����ɾ��*/
		printf("* * * * * * *�������˳����ɾ������* * * * * * *\n");
		printf("������ɾ��λ�ã�");
		scanf("%d", &i);
		if (ListDelete_Sq(l, i, x))
		{
			printf("��ϲ�㣬ɾ�������ɹ���\n");
			printf("ɾ����Ԫ���ǣ�%d\n", x);
			printf("* * * * * * *���˳���* * * * * * *\n");
			TraverList_Sq(l);
		}
		else
			printf("���ź����������ṩ��ɾ��λ�ò��Ϸ���ǰ˳���Ϊ�գ�����˳����ɾ��ʧ�ܣ�\n");
		system("pause");
	}
}