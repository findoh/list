#include <stdio.h>
#include "linklist.h"
//链式存储：用一组任意的存储单元存放线性表的元素，不需要预分配存储空间，元素个数不受限
typedef struct Person
{
	LinkListNode node;//节点作为第一个元素，节点将类串联起来
	int age;
	char name[64];		
}Person;

void main02()
{
	LinkList* list = NULL;
	LinkListNode* node = NULL;
	int count;
	Person p1, p2, p3, p4, p5;
	Person* tmp;

	list = LinkList_Create();//创建链表

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;
	LinkList_Insert(list, (LinkListNode*)(&p1), 0);//向链表中插入数据
	LinkList_Insert(list, (LinkListNode*)(&p2), 1);
	LinkList_Insert(list, (LinkListNode*)(&p3), 2);
	LinkList_Insert(list, (LinkListNode*)(&p4), 3);
	LinkList_Insert(list, (LinkListNode*)(&p5), 4);

	for (int i = 0; i<LinkList_Length(list); i++)//遍历链表
	{
		tmp = (Person*)LinkList_Get(list, i);//得到链表中对应位置的数据
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	LinkList_Delete(list, 1);//删除链表中位置为1的数据
	for (int i = 0; i<LinkList_Length(list); i++)
	{
		tmp = (Person*)LinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	LinkList_Delete(list, 5);//删除链表中超过长度位置的数据，则删除最后一个数据
	for (int i = 0; i<LinkList_Length(list); i++)
	{
		tmp = (Person*)LinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	LinkList_Clear(list);//清除链表中的数据	
	for (int i = 0; i<LinkList_Length(list); i++)
	{
		tmp = (Person*)LinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	count = LinkList_Length(list);//得到此时链表的长度，应该为0
	printf("list的长度:%d\n", count);
	LinkList_Destory(list);//释放链表内存空间

	system("pause");
}