#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"�˵�.h"
#include"�������.h"
extern DAY;
struct data
{
	char n;//Ա������
	int m;//��Ʒ����
	int sale;//���۶�
	struct data* next;
};
void inquire1(int num[6], int daily2[6])
{
	if (DAY < 1)//������ʾ
	{
		printf("������Ϣδ¼�룬�޷���ѯ��ʷ����");
		return 0;
	}
	printf("�����ǵ�%d��\n", DAY);
	printf("\n");
	printf("==================\n");
	printf("��Ʒ����    ���۶�\n");
	for (int i = 1; i <= 5; i++)
	{
		printf(" %d             %d \n", num[i], daily2[num[i]]);
	}
	printf("==================\n");
	printf("\n");
}
void inquire2(int num[6], int daily2[6])
{
	if (DAY < 1)//������ʾ
	{
		printf("������Ϣδ¼�룬�޷���ѯ��ʷ����");
		return 0;
	}
	printf("�����ǵ�%d��\n", DAY);
	printf("\n");
	printf("==================\n");
	printf("====��Ʒ�����====\n");
	for (int i = 1; i <= 5; i++)
	{
		if (daily2[num[i]] == 0)
			break;
		printf("===��Ʒ����Ϊ%d====\n", num[i]);
	}
	printf("==================\n");
	printf("\n");
}
void inquire3(int num[6], int num1[6])
{
	if (DAY < 1)//������ʾ
	{
		printf("������Ϣδ¼�룬�޷���ѯ��ʷ����");
		return 0;
	}
	printf("�����ǵ�%d��\n", DAY);
	printf("\n");
	printf("==================\n");
	printf("��Ʒ����    ������\n");
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
		printf("\033[1;36;40m[A]   ÿ�ֲ�Ʒ����Ա��������۶��\033[0m");
		break;
	}
	case 2:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[B]   ����Ա����Ĳ�Ʒ�����\033[0m");
		break;
	}
	case 3:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[C]   ��Ʒ�����������\033[0m");
		break;
	}
	case 4:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[F]   �˳�\033[0m");
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
void inquire(struct data* p)//ÿ�ֲ�Ʒ����Ա��������۶��������
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
	for (int i = 1; i <= 5; i++)//ð������
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
		system("cls");//����
		Beep(2000, 250);//����
		hide();
		menu1();
		line = 1;
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   ÿ�ֲ�Ʒ����Ա��������۶��\033[0m");//������ɫ��
		while ((a = _getch()) != '\r')
		{
			if (a == -32)//���뷽ʽ1
			{
				b = _getch();
				if (b == 72 && line != 1)//��
				{
					line--;
					choose3(line);
				}
				else if (b == 72 && line == 1)//��
				{
					line = 4;
					choose3(line);
				}
				else if (b == 80 && line != 4)//��
				{
					line++;
					choose3(line);
				}
				else if (b == 80 && line == 4)//��
				{
					line = 1;
					choose3(line);
				}
			}
			else
				break;
		}
		if (a == 65 || a == 97)//���뷽ʽ2
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
			printf("���밴����������������\n");
			system("pause");
			continue;
		}
		system("cls");
		if (line == 4)
			return 0;
		choose4(line, num, num1, daily2);
	}
}