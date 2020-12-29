#include <stdio.h>
#include "dlinklist.h"
//链式存储：用一组任意的存储单元存放线性表的元素，不需要预分配存储空间，元素个数不受限
typedef struct Person
{
	DLinkListNode node;//节点作为第一个元素，节点将类串联起来
	int age;
	char name[64];
}Person;

void main()
{
	DLinkList* list = NULL;
	DLinkListNode* node = NULL;
	int count, ret;
	Person p1, p2, p3, p4, p5;
	Person* tmp;

	list = DLinkList_Create();//创建链表
	if (list == NULL)
	{
		printf("func CircleList_Create() err\n");
	}

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;
	ret = DLinkList_Insert(list, (DLinkListNode*)(&p1), 0);//向链表中插入数据
	if (ret < 0)
	{
		printf("func CircleList_Insert() err:%d\n", ret);
	}
	DLinkList_Insert(list, (DLinkListNode*)(&p2), 0);
	DLinkList_Insert(list, (DLinkListNode*)(&p3), 0);
	DLinkList_Insert(list, (DLinkListNode*)(&p4), 0);
	DLinkList_Insert(list, (DLinkListNode*)(&p5), 0);

	for (int i = 0; i< 2 * DLinkList_Length(list); i++)//遍历链表
	{
		tmp = (Person*)DLinkList_Get(list, i);//得到链表中对应位置的数据
		if (tmp == NULL)
		{
			printf("func CircleList_Get() err\n");
		}
		printf("age:%d\n", tmp->age);
	}//25 24 23 22 21 25 24 23 22 21 
	printf("*************测试插入是否能够实现双向循环**************\n");
	tmp = (Person*)DLinkList_Next(list);
	printf("age:%d\n", tmp->age);//21
	tmp = (Person*)DLinkList_Next(list);
	printf("age:%d\n", tmp->age);//25
	tmp = (Person*)DLinkList_Next(list);
	printf("age:%d\n", tmp->age);//24
	tmp = (Person*)DLinkList_Pre(list);
	printf("age:%d\n", tmp->age);//23
	tmp = (Person*)DLinkList_Pre(list);
	printf("age:%d\n", tmp->age);//24
	tmp = (Person*)DLinkList_Current(list);
	printf("age:%d\n", tmp->age);//25，成功
	
	printf("*************测试删除中间元素后是否能够实现双向循环**************\n");
	//tmp= DLinkList_Delete(list, 1);//删除链表中位置为1的数据
	tmp = DLinkList_Delete2(list, (DLinkListNode*)(&p4));//删除链表中值为p4的数据
	if (tmp == NULL)
	{
		printf("func CircleList_Delete() err\n");
	}
	for (int i = 0; i< 2 * DLinkList_Length(list); i++)
	{
		tmp = (Person*)DLinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}//25 23 22 21 25 23 22 21
	printf("***************************\n");
	tmp = (Person*)DLinkList_Next(list);
	printf("age:%d\n", tmp->age);//21
	tmp = (Person*)DLinkList_Next(list);
	printf("age:%d\n", tmp->age);//25
	tmp = (Person*)DLinkList_Pre(list);
	printf("age:%d\n", tmp->age);//23
	tmp = (Person*)DLinkList_Pre(list);
	printf("age:%d\n", tmp->age);//25，成功
	
	printf("*************测试删除头元素后是否能够实现双向循环**************\n");
	//DLinkList_Delete(list, 0);
	tmp = DLinkList_Delete2(list, (DLinkListNode*)(&p5));//删除链表中值为p5的数据
	if (tmp == NULL)
	{
		printf("func CircleList_Delete2() err\n");
	}
	for (int i = 0; i < 2 * DLinkList_Length(list); i++)
	{
		tmp = (Person*)DLinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}//23 22 21 23 22 21
	printf("***************************\n");
	tmp = (Person*)DLinkList_Next(list);
	printf("age:%d\n", tmp->age);//21
	tmp = (Person*)DLinkList_Next(list);
	printf("age:%d\n", tmp->age);//23
	tmp = (Person*)DLinkList_Pre(list);
	printf("age:%d\n", tmp->age);//22
	tmp = (Person*)DLinkList_Pre(list);
	printf("age:%d\n", tmp->age);//23，成功

	printf("*************清除链表中的数据**************\n");
	DLinkList_Clear(list);//清除链表中的数据	
	for (int i = 0; i<DLinkList_Length(list); i++)
	{
		tmp = (Person*)DLinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	count = DLinkList_Length(list);//得到此时链表的长度，应该为0
	printf("list的长度:%d\n", count);
	DLinkList_Destory(list);//释放链表内存空间

	system("pause");
}