#include <stdio.h>
#include "circlelist.h"
//链式存储：用一组任意的存储单元存放线性表的元素，不需要预分配存储空间，元素个数不受限
typedef struct Value
{
	CircleListNode node;//节点作为第一个元素，节点将类串联起来
	int num;
}Value;

void main05()
{
	CircleList* list = NULL;
	CircleListNode* node = NULL;
	int count, ret;
	Value v1, v2, v3, v4, v5, v6, v7, v8;
	Value* tmpv;

	list = CircleList_Create();//创建链表
	if (list == NULL)
	{
		printf("func CircleList_Create() err\n");
	}
	v1.num = 1;
	v2.num = 2;//为什么这个没有删掉？
	v3.num = 3;
	v4.num = 4;
	v5.num = 5;
	v6.num = 6;
	v7.num = 7;
	v8.num = 8;
	ret = CircleList_Insert(list, (CircleListNode*)(&v1), 0);//向链表中插入数据
	if (ret < 0)
	{
		printf("func CircleList_Insert() err:%d\n", ret);
	}
	CircleList_Insert(list, (CircleListNode*)(&v2), 1);
	CircleList_Insert(list, (CircleListNode*)(&v3), 2);
	CircleList_Insert(list, (CircleListNode*)(&v4), 3);
	CircleList_Insert(list, (CircleListNode*)(&v5), 4);
	CircleList_Insert(list, (CircleListNode*)(&v6), 5);
	CircleList_Insert(list, (CircleListNode*)(&v7), 6);
	CircleList_Insert(list, (CircleListNode*)(&v8), 7);

	printf("**************遍历链表*************\n");
	for (int i = 0; i< CircleList_Length(list); i++)//遍历链表
	{
		tmpv = (Value*)CircleList_Get(list, i);//得到链表中对应位置的数据
		if (tmpv == NULL)
		{
			printf("func CircleList_Get() err\n");
		}
		printf("age:%d\n", tmpv->num);
	}
	printf("**************利用游标进行编程*************\n");
	node = CircleList_Reset(list);//重置游标
	if (node == NULL)
	{
		printf("func CircleList_Reset() err");
	}

	while (CircleList_Length(list) > 0)
	{
		for (int i = 0; i< 3; i++)//遍历链表
		{
			tmpv = (Value*)CircleList_Next(list);			
		}
		printf("%d", tmpv->num);//输出第三个数,注意输出的语法
		printf("\n");
		CircleList_Delete2(list, (CircleListNode*)tmpv);//删除该数
	}
	printf("***************************\n");
	count = CircleList_Length(list);//得到此时链表的长度，应该为0
	printf("list的长度:%d\n", count);
	CircleList_Destory(list);//释放链表内存空间

	system("pause");
}