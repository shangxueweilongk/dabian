#define _CRT_SECURE_NO_WARNINGS 1
#define LEN sizeof(struct data)//长度
#define DAY1 20//历史数据存储天数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"控制面板.h"
#include"菜单.h"
#include"创建.h"
#include"保存数据.h"
#include"查询1.h"
#include"查询2.h"
#include"统计.h"
struct data
{
	char n;//员工代号
	int m;//产品代号
	int sale;//销售额
	struct data* next;
};
struct data* head = NULL;
int DAY = 0,u=1;
char str1[DAY1][20] = { 0 };//1存储员工代号的历史数据
int  str0[DAY1] = { 0 }; str2[DAY1][20] = { 0 }, str3[DAY1][20] = { 0 };//0存储日期，2存储产品代号的历史数据，3存储销售额的历史数据

int main()
{
	menucontrol(head);
	return 0;
}