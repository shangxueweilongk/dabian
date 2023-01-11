#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"菜单.h"
#include"创建.h"
#include"保存数据.h"
#include"查询1.h"
#include"查询2.h"
#include"统计.h"
extern struct data* head;
void hide()//隐藏光标
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);

}
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
void choose1(int line)
{
	system("cls");
	menu();
	switch (line)
	{
	case 1:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   便条信息录入\033[0m");
		break;
	}
	case 2:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[B]   查询当天数据\033[0m");
		break;
	}
	case 3:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[C]   查询历史数据\033[0m");
		break;
	}
	case 4:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[D]   统计当天数据\033[0m");
		break;
	}
	case 5:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[E]   统计近一周数据\033[0m");
		break;
	}
	case 6:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[F]   退出\033[0m");
	}
	}
}
void choose2(int line)
{
	switch (line)
	{
	case 1:
	{
		creat();
		system("pause");
		break;
	}
	case 2:
	{
		inquire(head);
		system("pause");
		break;
	}
	case 3:
	{
		INQ();
		system("pause");
		break;
	}
	case 4:
	{
		cencus1(head);
		system("pause");
		break;
	}
	case 5:
	{
		cencus2();
		system("pause");
		break;
	}
	}
}

void menucontrol()
{
	int line;
	char a, b;
	while (1)
	{
		system("cls");//清屏
		Beep(2000, 250);//声音
		hide();
		menu();
		line = 1;
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   便条信息录入\033[0m");//高亮变色；
		while ((a = _getch()) != '\r')
		{
			if (a == -32)//进入方式1
			{
				b = _getch();
				if (b == 72 && line != 1)//上
				{
					line--;
					choose1(line);
				}
				else if (b == 72 && line == 1)//上
				{
					line = 6;
					choose1(line);
				}
				else if (b == 80 && line != 6)//下
				{
					line++;
					choose1(line);
				}
				else if (b == 80 && line == 6)//下
				{
					line = 1;
					choose1(line);
				}
			}
			else
				break;
		}
		if (a == 65 || a == 97)//进入方式2
		{
			system("cls");
			creat();
			system("pause");
			continue;
		}
		else if (a == 66 || a == 98)
		{
			system("cls");
			inquire(head);
			system("pause");
			continue;
		}
		else if (a == 67 || a == 99)
		{
			system("cls");
			INQ();
			system("pause");
			continue;
		}
		else if (a == 68 || a == 100)
		{
			system("cls");
			cencus1(head);
			system("pause");
			continue;
		}
		else if (a == 69 || a == 101)
		{
			system("cls");
			cencus2();
			system("pause");
			continue;
		}
		else if (a == 70 || a == 102)
		{
			system("cls");
			exit(0);
		}
		else if (a != '\r')
		{
			system("cls");
			printf("输入按键有误，请重新输入\n");
			system("pause");
			continue;
		}

		system("cls");
		if (line == 6)
			exit(0);
		choose2(line);
	}
}
