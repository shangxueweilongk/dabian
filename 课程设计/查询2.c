#define _CRT_SECURE_NO_WARNINGS 1
#define DAY1 20//��ʷ���ݴ洢����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"�˵�.h"
extern int DAY, u;
extern int str0[DAY1], str2[DAY1][20], str3[DAY1][20];
extern char str1[DAY1][20];
void INQ1(int num[6], int num1[6])
{
	if (DAY < 7)
	{
		printf("ʱ��С��һ���޷����в�ѯ\n");
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
void INQ2(int num[6], int daily2[6])
{
	if (DAY < 7)
	{
		printf("ʱ��С��һ���޷����в�ѯ\n");
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
void INQ3()
{
	if (DAY < 1)//������ʾ
	{
		printf("������Ϣδ¼�룬�޷���ѯ��ʷ����");
		return 0;
	}
	printf("�����ǵ�%d��\n", DAY);
	printf("\n");
	printf("=======================================================\n");
	printf("||ʱ�� || Ա������ || ��Ʒ���� || ���۶�                 \n");
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
		printf("\033[1;36;40m[A]   ��һ��ÿ�ֲ�Ʒ������\033[0m");
		break;
	}
	case 2:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[B]   ��һ������Ա�Ĳ�Ʒ���������\033[0m");
		break;
	}
	case 3:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[C]   ��ʷ���ݱ�\033[0m");
		break;
	}
	case 4:
	{
		gotoxy(0, line);
		printf("\033[1;36;40m[D]   �˳�\033[0m");
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
	int daily1[6] = { 0 }, daily2[6] = { 0 }, num[6] = { 0,1,2,3,4,5 }, num1[6] = { 0 }, box1 = 0, box2 = 0, line = 0;//dailyΪÿ�ֲ�Ʒ�����۶�
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
		menu2();
		line = 1;
		gotoxy(0, line);
		printf("\033[1;36;40m[A]   ��һ��ÿ�ֲ�Ʒ������\033[0m");//������ɫ��
		while ((a = _getch()) != '\r')
		{
			if (a == -32)//���뷽ʽ1
			{
				b = _getch();
				if (b == 72 && line != 1)//��
				{
					line--;
					choose5(line);
				}
				else if (b == 72 && line == 1)//��
				{
					line = 4;
					choose5(line);
				}
				else if (b == 80 && line != 4)//��
				{
					line++;
					choose5(line);
				}
				else if (b == 80 && line == 4)//��
				{
					line = 1;
					choose5(line);
				}
			}
			else
				break;
		}
		if (a == 65 || a == 97)//���뷽ʽ2
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
			printf("���밴����������������\n");
			system("pause");
			continue;
		}
		system("cls");
		if (line == 4)
			return 0;
		choose6(line, num, num1, daily2);
	}
}
