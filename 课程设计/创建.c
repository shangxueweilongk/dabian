#define _CRT_SECURE_NO_WARNINGS 1
#define LEN sizeof(struct data)
#define DAY1 20//��ʷ���ݴ洢����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern struct data* head;
extern int DAY, u;
extern int str0[DAY1], str2[DAY1][20], str3[DAY1][20];
extern char str1[DAY1][20];
struct data
{
	char n;//Ա������
	int m;//��Ʒ����
	int sale;//���۶�
	struct data* next;
};
void creat()//��������¼����Ϣ
{
	DAY++;
	str0[DAY] = DAY;
	int n = 1;
	struct data* p1, * p2;
	p2 = p1 = (struct data*)malloc(LEN);
	printf("�����ǵ�%d��\n", DAY);
	printf("\n");
	printf("������Ա������\n");
	p1->n = getchar();
	if (p1->n < 49 || p1->n>52)//������ʾ
	{
		printf("Ա������������󣬽��˳�����\n");
		exit(0);
	}
	printf("�����Ʒ����\n");
	scanf("%d", &p1->m);
	if (p1->m < 1 || p1->m>5)//������ʾ
	{
		printf("��Ʒ����������󣬽��˳�����\n");
		exit(0);
	}
	printf("���뵱�����۶�\n");
	scanf("%d", &p1->sale);
	while (p1->n != '\n')
	{
		printf("����Ϊ%c��Ա����Ϣ¼��ɹ�\n", p1->n);
		printf("\n");
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		n++;
		p2 = p1;
		p1 = (struct data*)malloc(LEN);
		getchar();
		printf("����Ա������\n");
		p1->n = getchar();
		if ((p1->n < 49 || p1->n>52) && p1->n != '\n')//������ʾ
		{
			printf("Ա������������󣬽��˳�����\n");
			exit(0);
		}
		if (p1->n != '\n')
		{
			printf("�����Ʒ����\n");
			scanf("%d", &p1->m);
			if (p1->m < 1 || p1->m>5)//������ʾ
			{
				printf("��Ʒ����������󣬽��˳�����\n");
				exit(0);
			}
			printf("���뵱�����۶�\n");
			scanf("%d", &p1->sale);
		}
	}
	p2->next = NULL;
	save(head);
	historycalsave(head);
}
