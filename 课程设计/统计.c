#define _CRT_SECURE_NO_WARNINGS 1
#define DAY1 20//��ʷ���ݴ洢����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern struct data* head;
extern int DAY, u;
extern int  str2[DAY1][20];
struct data
{
	char n;//Ա������
	int m;//��Ʒ����
	int sale;//���۶�
	struct data* next;
};
void cencus1(struct data* p)//ͳ�Ƶ��������
{
	FILE* fp;
	int daily[6] = { 0 };
	printf("�����ݴ����daily.txt��\n");
	if ((fp = fopen("daily.txt", "w+")) == NULL)
	{
		printf("�޷��򿪸��ļ�,���˳�����\n");
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
		daily[5] = daily[0] + daily[1] + daily[2] + daily[3] + daily[4];//ÿ������Ա�����۶�
		p = p->next;
	}
	fprintf(fp, "��%d��\n", DAY);
	fprintf(fp, "�����������Ǵ���Ϊ1,2,3,4,5�Ĳ�Ʒ�����۶����Ա�������۶�\n");
	for (int j = 0; j < 6; j++)
		fprintf(fp, "%d  ", daily[j]);
	printf("�����Ѵ����daily.txt��\n");
	fclose(fp);
}

void cencus2()//ͳ�ƽ�һ����ʷ����
{
	FILE* fp;
	int arr1[6] = { 0 };
	if (DAY < 7)
	{
		printf("ʱ��С��һ���޷����ͳ��\n");
		return 0;
	}
	printf("����ʷ���ݴ����cencus2.txt��\n");
	if ((fp = fopen("cencus2", "w+")) == NULL)
	{
		printf("�޷��򿪸��ļ�,���˳�����\n");
		exit(0);
	}
	for (int i = DAY - 6; i <= DAY; i++)
	{
		for (int j = 1; j <= u - 1; j++)
			arr1[str2[i][j]]++;
	}
	fprintf(fp, "��һ��ÿ�ֲ�Ʒ����(�����������ǲ�Ʒ����Ϊ1,2,3,4,5������\n");
	for (int i = 1; i <= 5; i++)
		fprintf(fp, "%d ", arr1[i]);
	fprintf(fp, "\n ");
	fprintf(fp, "��һ������Ա�Ĳ�Ʒ���������\n");
	for (int i = 1; i <= 5; i++)
	{
		if (arr1[i] != 0)
			fprintf(fp, "��Ʒ����Ϊ%d ", i);
	}
	printf("��ʷ�����Ѵ����cencus2.txt��\n");
	fclose(fp);
}