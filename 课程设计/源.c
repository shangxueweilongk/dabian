#define _CRT_SECURE_NO_WARNINGS 1
#define LEN sizeof(struct data)//����
#define DAY1 20//��ʷ���ݴ洢����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"�������.h"
#include"�˵�.h"
#include"����.h"
#include"��������.h"
#include"��ѯ1.h"
#include"��ѯ2.h"
#include"ͳ��.h"
struct data
{
	char n;//Ա������
	int m;//��Ʒ����
	int sale;//���۶�
	struct data* next;
};
struct data* head = NULL;
int DAY = 0,u=1;
char str1[DAY1][20] = { 0 };//1�洢Ա�����ŵ���ʷ����
int  str0[DAY1] = { 0 }; str2[DAY1][20] = { 0 }, str3[DAY1][20] = { 0 };//0�洢���ڣ�2�洢��Ʒ���ŵ���ʷ���ݣ�3�洢���۶����ʷ����

int main()
{
	menucontrol(head);
	return 0;
}