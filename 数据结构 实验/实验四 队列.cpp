#include"SqQueue.h"
#include"LinkQueue.h"

int main()
{
	printf("===============||ѭ�����и��ֻ�������||===============\n");
	SqQueue *head;
	int n;
	head = (SqQueue*)malloc(sizeof(SqQueue));
	initSqQueue(head);
	printf("��ʼ����ϣ�\n");
	printf("=====����ѭ������=====\n");
	SetSqQueue(head);
	printf("=====�������=====\n");
	SqDisplay(head);
	printf("=====���Ӳ���=====\n");
	SqDelete(head);
	printf("=====�������=====\n");
	SqDisplay(head);
	printf("=====��Ӳ���=====\n");
	printf("������Ҫ��ӵ�Ԫ�أ�");
	scanf("%d", &n);
	SqAppend(head, n);
	printf("=====�������=====\n");
	SqDisplay(head);
	printf("===============||********************||===============\n");
	printf("=== �ݲ�171 1708090134 Ԭ��һ ===");
	system("pause");
	printf("===============||�����и��ֻ�������||===============\n");
	Lqueue *p;
	int n;
	p = (Lqueue*)malloc(sizeof(Lqueue));
	printf("=====����˳������=====\n");
	initLQueue(p);
	printf("=====�������=====\n");
	LDisplay(p);
	printf("=====���Ӳ�������в���=====\n");
	LDelete(p);
	LDisplay(p);
	printf("=====��Ӳ���=====\n");
	printf("������Ҫ��ӵ�Ԫ�أ�");
	scanf("%d", &n);
	Lappend(p, n);
	printf("=====�������=====\n");
	LDisplay(p);
	printf("===============||********************||===============\n");
	printf("=== �ݲ�171 1708090134 Ԭ��һ ===");
	system("pause");
	return 0;
}