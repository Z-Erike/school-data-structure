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
		printf("抱歉，顺序表初始化失败！！！\n");
	else
	{
		/*顺序表的输入及建立*/
		printf("恭喜你，顺序表初始化成功！\n");
		printf("* * * * * * *创建顺序表* * * * * * *\n");
		printf("请输入要建立的顺序表长度：");
		scanf("%d", &n);
		CreatList_Sq(l, n);
		printf("* * * * * * *输出顺序表* * * * * * *\n");
		TraverList_Sq(l);
		/*顺序表插入*/
		printf("* * * * * * *下面进行顺序表的插入操作* * * * * * *\n");
		printf("请输入插入位置i：");
		scanf("%d", &i);
		printf("请输入要插入的元素：");
		scanf("%d", &x);
		if (ListInsert_Sq(l, i, x))
		{
			printf("恭喜你，插入操作成功！\n");
			printf("* * * * * * *输出顺序表* * * * * * *\n");
			TraverList_Sq(l);
		}//if
		else
			printf("很遗憾，由于您提供的插入位置不合法，导致顺序表的插入失败！！！\n");
		/*顺序表的删除*/
		printf("* * * * * * *下面进行顺序表的删除操作* * * * * * *\n");
		printf("请输入删除位置：");
		scanf("%d", &i);
		if (ListDelete_Sq(l, i, x))
		{
			printf("恭喜你，删除操作成功！\n");
			printf("删除的元素是：%d\n", x);
			printf("* * * * * * *输出顺序表* * * * * * *\n");
			TraverList_Sq(l);
		}
		else
			printf("很遗憾，由于您提供的删除位置不合法或当前顺序表为空，导致顺序表的删除失败！\n");
		system("pause");
	}
}