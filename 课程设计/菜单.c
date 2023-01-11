#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void menu()//创建主菜单
{
	printf("=======================\n");
	printf("[A]   便条信息录入\n");
	printf("[B]   查询当天数据\n");
	printf("[C]   查询历史数据\n");;
	printf("[D]   统计当天数据\n");
	printf("[E]   统计近一周数据\n");
	printf("[F]   退出\n");
	printf("=======================\n");
}
void menu1()//创建菜单
{
	printf("==================================\n");
	printf("[A]   每种产品销售员当天的销售额表\n");
	printf("[B]   销售员当天的产品任务表\n");
	printf("[C]   产品当天的销量表\n");
	printf("[D]   退出\n");
	printf("==================================\n");
}
void menu2()//创建菜单
{
	printf("==================================\n");
	printf("[A]   近一周每种产品销量表\n");
	printf("[B]   近一周销售员的产品销售任务表\n");
	printf("[C]   历史数据表\n");
	printf("[D]   退出\n");
	printf("==================================\n");
}