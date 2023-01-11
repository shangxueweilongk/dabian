#define _CRT_SECURE_NO_WARNINGS 1
#define DAY1 20//历史数据存储天数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
extern int DAY,u;
extern int str0[DAY1], str2[DAY1][20], str3[DAY1][20];
char str1[DAY1][20];
struct data
{
	char n;//员工代号
	int m;//产品代号
	int sale;//销售额
	struct data* next;
};
void save(struct data* p)//保存数据
{
	FILE* fp;
	printf("将当天数据存放在data.txt中\n");
	if ((fp = fopen("data.txt", "w+")) == NULL)
	{
		printf("无法打开该文件,将退出程序\n");
		exit(0);
	}
	fprintf(fp, "第%d天\n", DAY);
	while (p != NULL)
	{
		fprintf(fp, "员工代号%c ", p->n);
		fprintf(fp, "产品代号%d ", p->m);
		fprintf(fp, "销售额%d ", p->sale);
		fprintf(fp, "\n");
		p = p->next;
	}
	printf("当天数据已保存在data.txt中\n");
	fclose(fp);
}

void historycalsave(struct data* p)
{
	FILE* fp;
	printf("将历史数据存放在history.txt中\n");
	if ((fp = fopen("history.txt", "w+")) == NULL)
	{
		printf("无法打开该文件,将退出程序\n");
		exit(0);
	}
	for (u=1; p != NULL; u++)//u为纸条数
	{
		str1[DAY][u] = p->n;
		str2[DAY][u] = p->m;
		str3[DAY][u] = p->sale;
		p = p->next;
	}
	for (int i = 1; i < 20; i++)
	{
		if (str0[i] == 0)
			break;
		fprintf(fp, "第%d天\n", str0[i]);
		for (int j = 1; j <= u - 1; j++)
		{
			if (str2[str0[i]][j] != 0)
				fprintf(fp, "员工代号%c 产品代号%d 销售额%d\n", str1[str0[i]][j], str2[str0[i]][j], str3[str0[i]][j]);
		}

	}
	printf("历史数据已保存在history.txt中\n");
	fclose(fp);
}
