#define _CRT_SECURE_NO_WARNINGS 1
#define LEN sizeof(struct data)
#define DAY1 20//历史数据存储天数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern struct data* head;
extern int DAY, u;
extern int str0[DAY1], str2[DAY1][20], str3[DAY1][20];
extern char str1[DAY1][20];
struct data
{
	char n;//员工代号
	int m;//产品代号
	int sale;//销售额
	struct data* next;
};
void creat()//创建链表录入信息
{
	DAY++;
	str0[DAY] = DAY;
	int n = 1;
	struct data* p1, * p2;
	p2 = p1 = (struct data*)malloc(LEN);
	printf("现在是第%d天\n", DAY);
	printf("\n");
	printf("请输入员工代号\n");
	p1->n = getchar();
	if (p1->n < 49 || p1->n>52)//错误提示
	{
		printf("员工代号输入错误，将退出程序\n");
		exit(0);
	}
	printf("输入产品代号\n");
	scanf("%d", &p1->m);
	if (p1->m < 1 || p1->m>5)//错误提示
	{
		printf("产品代号输入错误，将退出程序\n");
		exit(0);
	}
	printf("输入当天销售额\n");
	scanf("%d", &p1->sale);
	while (p1->n != '\n')
	{
		printf("代号为%c的员工信息录入成功\n", p1->n);
		printf("\n");
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		n++;
		p2 = p1;
		p1 = (struct data*)malloc(LEN);
		getchar();
		printf("请输员工代号\n");
		p1->n = getchar();
		if ((p1->n < 49 || p1->n>52) && p1->n != '\n')//错误提示
		{
			printf("员工代号输入错误，将退出程序\n");
			exit(0);
		}
		if (p1->n != '\n')
		{
			printf("输入产品代号\n");
			scanf("%d", &p1->m);
			if (p1->m < 1 || p1->m>5)//错误提示
			{
				printf("产品代号输入错误，将退出程序\n");
				exit(0);
			}
			printf("输入当天销售额\n");
			scanf("%d", &p1->sale);
		}
	}
	p2->next = NULL;
	save(head);
	historycalsave(head);
}
