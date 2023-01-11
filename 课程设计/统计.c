#define _CRT_SECURE_NO_WARNINGS 1
#define DAY1 20//历史数据存储天数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern struct data* head;
extern int DAY, u;
extern int  str2[DAY1][20];
struct data
{
	char n;//员工代号
	int m;//产品代号
	int sale;//销售额
	struct data* next;
};
void cencus1(struct data* p)//统计当天的数据
{
	FILE* fp;
	int daily[6] = { 0 };
	printf("将数据存放在daily.txt中\n");
	if ((fp = fopen("daily.txt", "w+")) == NULL)
	{
		printf("无法打开该文件,将退出程序\n");
		exit(0);
	}
	while (p != NULL)
	{
		if (p->m == 1)
			daily[0] = daily[0] + p->sale;
		if (p->m == 2)
			daily[1] = daily[1] + p->sale;
		if (p->m == 3)
			daily[2] = daily[2] + p->sale;
		if (p->m == 4)
			daily[3] = daily[3] + p->sale;
		if (p->m == 5)
			daily[4] = daily[4] + p->sale;
		daily[5] = daily[0] + daily[1] + daily[2] + daily[3] + daily[4];//每天销售员总销售额
		p = p->next;
	}
	fprintf(fp, "第%d天\n", DAY);
	fprintf(fp, "从左到右依次是代号为1,2,3,4,5的产品的销售额，销售员的总销售额\n");
	for (int j = 0; j < 6; j++)
		fprintf(fp, "%d  ", daily[j]);
	printf("数据已存放在daily.txt中\n");
	fclose(fp);
}

void cencus2()//统计近一周历史数据
{
	FILE* fp;
	int arr1[6] = { 0 };
	if (DAY < 7)
	{
		printf("时间小于一周无法完成统计\n");
		return 0;
	}
	printf("将历史数据存放在cencus2.txt中\n");
	if ((fp = fopen("cencus2", "w+")) == NULL)
	{
		printf("无法打开该文件,将退出程序\n");
		exit(0);
	}
	for (int i = DAY - 6; i <= DAY; i++)
	{
		for (int j = 1; j <= u - 1; j++)
			arr1[str2[i][j]]++;
	}
	fprintf(fp, "近一周每种产品销量(从左到右依次是产品代号为1,2,3,4,5的销量\n");
	for (int i = 1; i <= 5; i++)
		fprintf(fp, "%d ", arr1[i]);
	fprintf(fp, "\n ");
	fprintf(fp, "近一周销售员的产品销售任务表\n");
	for (int i = 1; i <= 5; i++)
	{
		if (arr1[i] != 0)
			fprintf(fp, "产品代号为%d ", i);
	}
	printf("历史数据已存放在cencus2.txt中\n");
	fclose(fp);
}