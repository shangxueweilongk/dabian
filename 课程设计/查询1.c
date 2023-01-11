#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"菜单.h"
#include"控制面板.h"
extern DAY;
struct data
{
	char n;//员工代号
	int m;//产品代号
	int sale;//销售额
	struct data* next;
};
void inquire1(int num[6], int daily2[6])
{
	if (DAY < 1)//错误提示
	{
		printf("便条信息未录入，无法查询历史数据");
		return 0;
	}
	printf("现在是第%d天\n", DAY);
	printf("\n");
	printf("==================\n");
	printf("产品代号    销售额\n");
	for (int i = 1; i <= 5; i++)
	{
		printf(" %d             %d \n", num[i], daily2[num[i]]);
	}
	printf("==================\n");
	printf("\n");
}
void inquire2(int num[6], int daily2[6])
{
	if (DAY < 1)//错误提示
	{
		printf("便条信息未录入，无法查询历史数据");
		return 0;
	}
	printf("现在是第%d天\n", DAY);
	printf("\n");
	printf("==================\n");
	printf("====产品任务表====\n");
	for (int i = 1; i <= 5; i++)
	{
		if (daily2[num[i]] == 0)
			break;
		printf("===产品代号为%d====\n", num[i]);
	}
	printf("==================\n");
	printf("\n");
}
void inquire3(int num[6], int num1[6])
{
	if (DAY < 1)//错误提示
	{
		printf("便条信息未录入，无法查询历史数据");
		return 0;
	}
	printf("现在是第%d天\n", DAY);
	printf("\n");
	printf("==================\n");
	printf("产品代号    销售量\n");
	for (int i = 1; i <= 5; i++)
	{
		printf(" %d             %d \n", num[i], num1[num[i]]);
	}
	printf("==================\n");
	printf("\n");
}
void choose3(int line)
{
	system("cls");
	menu1();
	switch (line)
	{
	case 1:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   每种产品销售员当天的销售额表\033[0m");
		break;
	}
	case 2:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[B]   销售员当天的产品任务表\033[0m");
		break;
	}
	case 3:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[C]   产品当天的销量表\033[0m");
		break;
	}
	case 4:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[F]   退出\033[0m");
	}
	}
}
void choose4(int line, int num[6], int num1[6], int daily2[6])
{
	switch (line)
	{
	case 1:
	{
		inquire1(num, daily2);
		system("pause");
		break;
	}
	case 2:
	{
		inquire2(num, daily2);
		system("pause");
		break;
	}
	case 3:
	{
		inquire3(num, num1);
		system("pause");
		break;
	}
	}
}
void inquire(struct data* p)//每种产品销售员当天的销售额表（按金额降序）
{
	int daily1[6] = { 0 }, daily2[6] = { 0 }, num[6] = { 0,1,2,3,4,5 }, num1[6] = { 0 }, box1 = 0, box2 = 0, line = 0;
	char a, b;
	while (p != NULL)
	{
		if (p->m == 1)
		{
			daily1[1] = daily1[1] + p->sale;
			daily2[1] = daily2[1] + p->sale;
			num1[1]++;
		}
		if (p->m == 2)
		{
			daily1[2] = daily1[2] + p->sale;
			daily2[2] = daily2[2] + p->sale;
			num1[2]++;
		}
		if (p->m == 3)
		{
			daily1[3] = daily1[3] + p->sale;
			daily2[3] = daily2[3] + p->sale;
			num1[3]++;
		}
		if (p->m == 4)
		{
			daily1[4] = daily1[4] + p->sale;
			daily2[4] = daily2[4] + p->sale;
			num1[4]++;
		}
		if (p->m == 5)
		{
			daily1[5] = daily1[5] + p->sale;
			daily2[5] = daily2[5] + p->sale;
			num1[5]++;
		}
		p = p->next;
	}
	for (int i = 1; i <= 5; i++)//冒泡排序
	{
		for (int j = i + 1; j <= 5; j++)
		{
			if (daily1[i] < daily1[j])
			{
				box2 = num[j];
				num[j] = num[i];
				num[i] = box2;
				box1 = daily1[i];
				daily1[i] = daily1[j];
				daily1[j] = box1;
			}
		}
	}
	while (1)
	{
		system("cls");//清屏
		Beep(2000, 250);//声音
		hide();
		menu1();
		line = 1;
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   每种产品销售员当天的销售额表\033[0m");//高亮变色；
		while ((a = _getch()) != '\r')
		{
			if (a == -32)//进入方式1
			{
				b = _getch();
				if (b == 72 && line != 1)//上
				{
					line--;
					choose3(line);
				}
				else if (b == 72 && line == 1)//上
				{
					line = 4;
					choose3(line);
				}
				else if (b == 80 && line != 4)//下
				{
					line++;
					choose3(line);
				}
				else if (b == 80 && line == 4)//下
				{
					line = 1;
					choose3(line);
				}
			}
			else
				break;
		}
		if (a == 65 || a == 97)//进入方式2
		{
			system("cls");
			inquire1(num, daily2);
			system("pause");
			continue;
		}
		else if (a == 66 || a == 98)
		{
			system("cls");
			inquire2(num, daily2);
			system("pause");
			continue;
		}
		else if (a == 67 || a == 99)
		{
			system("cls");
			inquire3(num, num1);
			system("pause");
			continue;
		}
		else if (a == 68 || a == 100)
		{
			system("cls");
			return 0;
		}
		else if (a != '\r')
		{
			system("cls");
			printf("输入按键有误，请重新输入\n");
			system("pause");
			continue;
		}
		system("cls");
		if (line == 4)
			return 0;
		choose4(line, num, num1, daily2);
	}
}