#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"�˵�.h"
#include"����.h"
#include"��������.h"
#include"��ѯ1.h"
#include"��ѯ2.h"
#include"ͳ��.h"
extern struct data* head;
void hide()//���ع��
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
		printf("\033[1;36;40m[A]   ������Ϣ¼��\033[0m");
		break;
	}
	case 2:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[B]   ��ѯ��������\033[0m");
		break;
	}
	case 3:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[C]   ��ѯ��ʷ����\033[0m");
		break;
	}
	case 4:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[D]   ͳ�Ƶ�������\033[0m");
		break;
	}
	case 5:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[E]   ͳ�ƽ�һ������\033[0m");
		break;
	}
	case 6:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[F]   �˳�\033[0m");
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
		system("cls");//����
		Beep(2000, 250);//����
		hide();
		menu();
		line = 1;
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   ������Ϣ¼��\033[0m");//������ɫ��
		while ((a = _getch()) != '\r')
		{
			if (a == -32)//���뷽ʽ1
			{
				b = _getch();
				if (b == 72 && line != 1)//��
				{
					line--;
					choose1(line);
				}
				else if (b == 72 && line == 1)//��
				{
					line = 6;
					choose1(line);
				}
				else if (b == 80 && line != 6)//��
				{
					line++;
					choose1(line);
				}
				else if (b == 80 && line == 6)//��
				{
					line = 1;
					choose1(line);
				}
			}
			else
				break;
		}
		if (a == 65 || a == 97)//���뷽ʽ2
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
			printf("���밴����������������\n");
			system("pause");
			continue;
		}

		system("cls");
		if (line == 6)
			exit(0);
		choose2(line);
	}
}
