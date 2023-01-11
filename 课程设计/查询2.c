#define _CRT_SECURE_NO_WARNINGS 1
#define DAY1 20//历史数据存储天数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"菜单.h"
extern int DAY, u;
extern int str0[DAY1], str2[DAY1][20], str3[DAY1][20];
extern char str1[DAY1][20];
void INQ1(int num[6], int num1[6])
{
	if (DAY < 7)
	{
		printf("时间小于一周无法进行查询\n");
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
void INQ2(int num[6], int daily2[6])
{
	if (DAY < 7)
	{
		printf("时间小于一周无法进行查询\n");
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
void INQ3()
{
	if (DAY < 1)//错误提示
	{
		printf("便条信息未录入，无法查询历史数据");
		return 0;
	}
	printf("现在是第%d天\n", DAY);
	printf("\n");
	printf("=======================================================\n");
	printf("||时间 || 员工代号 || 产品代号 || 销售额                 \n");
	for (int i = 1; i <= DAY; i++)
	{
		for (int j = 1; str2[i][j] != 0; j++)
		{
			
			printf("||%d    ||    %c     ||     %d    ||   %d  \n", str0[i],str1[i][j],str2[i][j],str3[i][j]);
		}
	}
	printf("=======================================================\n");
}
void choose5(int line)
{
	system("cls");
	menu2();
	switch (line)
	{
	case 1:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   近一周每种产品销量表\033[0m");
		break;
	}
	case 2:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[B]   近一周销售员的产品销售任务表\033[0m");
		break;
	}
	case 3:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[C]   历史数据表\033[0m");
		break;
	}
	case 4:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[D]   退出\033[0m");
	}
	}
}
void choose6(int line, int num[6], int num1[6], int daily2[6])
{
	switch (line)
	{
	case 1:
	{
		INQ1(num, num1);
		system("pause");
		break;
	}
	case 2:
	{
		INQ2(num, daily2);
		system("pause");
		break;
	}
	case 3:
	{
		INQ3();
		system("pause");
		break;
	}
	}
}
void INQ()
{
	int daily1[6] = { 0 }, daily2[6] = { 0 }, num[6] = { 0,1,2,3,4,5 }, num1[6] = { 0 }, box1 = 0, box2 = 0, line = 0;//daily为每种产品的销售额
	char a, b;
	for (int i = DAY - 6; i <= DAY; i++)
	{
		for (int j = 1; j <= u - 1; j++)
		{
			if (str2[i][j] == 1)
			{
				daily1[1] = daily1[1] + str3[i][j];
				daily2[1] = daily2[1] + str3[i][j];
				num1[1]++;
			}
			if (str2[i][j] == 2)
			{
				daily1[2] = daily1[2] + str3[i][j];
				daily2[2] = daily2[2] + str3[i][j];
				num1[2]++;
			}
			if (str2[i][j] == 3)
			{
				daily1[3] = daily1[3] + str3[i][j];
				daily2[3] = daily2[3] + str3[i][j];
				num1[3]++;
			}
			if (str2[i][j] == 4)
			{
				daily1[4] = daily1[4] + str3[i][j];
				daily2[4] = daily2[4] + str3[i][j];
				num1[4]++;
			}
			if (str2[i][j] == 5)
			{
				daily1[5] = daily1[5] + str3[i][j];
				daily2[5] = daily2[5] + str3[i][j];
				num1[5]++;
			}
		}
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
		menu2();
		line = 1;
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   近一周每种产品销量表\033[0m");//高亮变色；
		while ((a = _getch()) != '\r')
		{
			if (a == -32)//进入方式1
			{
				b = _getch();
				if (b == 72 && line != 1)//上
				{
					line--;
					choose5(line);
				}
				else if (b == 72 && line == 1)//上
				{
					line = 4;
					choose5(line);
				}
				else if (b == 80 && line != 4)//下
				{
					line++;
					choose5(line);
				}
				else if (b == 80 && line == 4)//下
				{
					line = 1;
					choose5(line);
				}
			}
			else
				break;
		}
		if (a == 65 || a == 97)//进入方式2
		{
			system("cls");
			INQ1(num, num1);
			system("pause");
			continue;
		}
		else if (a == 66 || a == 98)
		{
			system("cls");
			INQ2(num, daily2);
			system("pause");
			continue;
		}
		else if (a == 67 || a == 99)
		{
			system("cls");
			INQ3();
			system("pause");
			return 0;
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
		choose6(line, num, num1, daily2);
	}
}
