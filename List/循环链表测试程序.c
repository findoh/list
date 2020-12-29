#include <stdio.h>
#include "circlelist.h"
//链式存储：用一组任意的存储单元存放线性表的元素，不需要预分配存储空间，元素个数不受限
typedef struct Person
{
	CircleListNode node;//节点作为第一个元素，节点将类串联起来
	int age;
	char name[64];
}Person;

void main04()
{
	CircleList* list = NULL;
	CircleListNode* node = NULL;
	int count, ret;
	Person p1, p2, p3, p4, p5;
	Person* tmp;

	list = CircleList_Create();//创建链表
	if (list == NULL)
	{
		printf("func CircleList_Create() err\n");
	}

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;
	ret = CircleList_Insert(list, (CircleListNode*)(&p1), 0);//向链表中插入数据
	if (ret < 0)
	{
		printf("func CircleList_Insert() err:%d\n", ret);
	}
	CircleList_Insert(list, (CircleListNode*)(&p2), 0);
	CircleList_Insert(list, (CircleListNode*)(&p3), 0);
	CircleList_Insert(list, (CircleListNode*)(&p4), 0);
	CircleList_Insert(list, (CircleListNode*)(&p5), 0);

	for (int i = 0; i< 2*CircleList_Length(list); i++)//遍历链表
	{
		tmp = (Person*)CircleList_Get(list, i);//得到链表中对应位置的数据
		if (tmp == NULL)
		{
			printf("func CircleList_Get() err\n");
		}
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	tmp = CircleList_Delete(list, 1);//删除链表中位置为1的数据
	if (tmp == NULL)
	{
		printf("func CircleList_Delete() err\n");
	}
	for (int i = 0; i< 2*CircleList_Length(list); i++)
	{
		tmp = (Person*)CircleList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	CircleList_Delete(list, 0);
	for (int i = 0; i < 2*CircleList_Length(list); i++)
	{
		tmp = (Person*)CircleList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	//CircleList_Delete(list, 0);
	//CircleList_Delete(list, 0);
	//CircleList_Delete(list, 0);
	//count = CircleList_Length(list);//得到此时链表的长度，应该为0
	//printf("list的长度:%d\n", count);
	CircleList_Clear(list);//清除链表中的数据	
	for (int i = 0; i<CircleList_Length(list); i++)
	{
		tmp = (Person*)CircleList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	count = CircleList_Length(list);//得到此时链表的长度，应该为0
	printf("list的长度:%d\n", count);
	CircleList_Destory(list);//释放链表内存空间

	system("pause");
}