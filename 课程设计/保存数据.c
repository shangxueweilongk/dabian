#define _CRT_SECURE_NO_WARNINGS 1
#define DAY1 20//��ʷ���ݴ洢����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
extern int DAY,u;
extern int str0[DAY1], str2[DAY1][20], str3[DAY1][20];
char str1[DAY1][20];
struct data
{
	char n;//Ա������
	int m;//��Ʒ����
	int sale;//���۶�
	struct data* next;
};
void save(struct data* p)//��������
{
	FILE* fp;
	printf("���������ݴ����data.txt��\n");
	if ((fp = fopen("data.txt", "w+")) == NULL)
	{
		printf("�޷��򿪸��ļ�,���˳�����\n");
		exit(0);
	}
	fprintf(fp, "��%d��\n", DAY);
	while (p != NULL)
	{
		fprintf(fp, "Ա������%c ", p->n);
		fprintf(fp, "��Ʒ����%d ", p->m);
		fprintf(fp, "���۶�%d ", p->sale);
		fprintf(fp, "\n");
		p = p->next;
	}
	printf("���������ѱ�����data.txt��\n");
	fclose(fp);
}

void historycalsave(struct data* p)
{
	FILE* fp;
	printf("����ʷ���ݴ����history.txt��\n");
	if ((fp = fopen("history.txt", "w+")) == NULL)
	{
		printf("�޷��򿪸��ļ�,���˳�����\n");
		exit(0);
	}
	for (u=1; p != NULL; u++)//uΪֽ����
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
		fprintf(fp, "��%d��\n", str0[i]);
		for (int j = 1; j <= u - 1; j++)
		{
			if (str2[str0[i]][j] != 0)
				fprintf(fp, "Ա������%c ��Ʒ����%d ���۶�%d\n", str1[str0[i]][j], str2[str0[i]][j], str3[str0[i]][j]);
		}

	}
	printf("��ʷ�����ѱ�����history.txt��\n");
	fclose(fp);
}
