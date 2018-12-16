#include"SqQueue.h"
#include"LinkQueue.h"

int main()
{
	printf("===============||循环队列各种基本运算||===============\n");
	SqQueue *head;
	int n;
	head = (SqQueue*)malloc(sizeof(SqQueue));
	initSqQueue(head);
	printf("初始化完毕！\n");
	printf("=====建立循环队列=====\n");
	SetSqQueue(head);
	printf("=====输出队列=====\n");
	SqDisplay(head);
	printf("=====出队操作=====\n");
	SqDelete(head);
	printf("=====输出队列=====\n");
	SqDisplay(head);
	printf("=====入队操作=====\n");
	printf("请输入要入队的元素：");
	scanf("%d", &n);
	SqAppend(head, n);
	printf("=====输出队列=====\n");
	SqDisplay(head);
	printf("===============||********************||===============\n");
	printf("=== 惠测171 1708090134 袁恒一 ===");
	system("pause");
	printf("===============||链队列各种基本运算||===============\n");
	Lqueue *p;
	int n;
	p = (Lqueue*)malloc(sizeof(Lqueue));
	printf("=====建立顺序表队列=====\n");
	initLQueue(p);
	printf("=====输出队列=====\n");
	LDisplay(p);
	printf("=====出队并输出队列操作=====\n");
	LDelete(p);
	LDisplay(p);
	printf("=====入队操作=====\n");
	printf("请输入要入队的元素：");
	scanf("%d", &n);
	Lappend(p, n);
	printf("=====输出队列=====\n");
	LDisplay(p);
	printf("===============||********************||===============\n");
	printf("=== 惠测171 1708090134 袁恒一 ===");
	system("pause");
	return 0;
}