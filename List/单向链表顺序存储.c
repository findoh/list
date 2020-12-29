#include <stdio.h>
#include "seqlist.h"
//顺序存储：用一段连续的存储单元依次存储线性表的的数据元素，需要预分配存储空间
typedef struct Person
{
	//////////////SeqListNode* node;//加入链表节点，此时节点的位置就是类的位置，
	//这里不需要，顺序结构本身是有内存的
	char name[64];
	int age;

}Person;

void main01()
{
	SeqList* list = NULL;
	SeqListNode* node = NULL;
	int count;
	Person p1, p2, p3, p4, p5;
	Person* tmp;

	list = SeqList_Create(10);//创建链表
	if (list == NULL)//没调用一次函数，最好要进行判断，这样比较规范
	{
		printf("func SeqList_Create() err\n");
		return;
	}

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;
	SeqList_Insert(list, (SeqListNode*)(&p1), 0);//向链表中插入数据
	SeqList_Insert(list, (SeqListNode*)(&p2), 0);
	SeqList_Insert(list, (SeqListNode*)(&p3), 0);
	SeqList_Insert(list, (SeqListNode*)(&p4), 0);
	SeqList_Insert(list, (SeqListNode*)(&p5), 0);
	
	for (int i = 0; i<SeqList_Length(list); i++)//遍历链表
	{
		tmp = (Person*)SeqList_Get(list, i);//得到链表中对应位置的数据
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	SeqList_Delete(list, 1);//删除链表中位置为1的数据
	for (int i = 0; i<SeqList_Length(list); i++)
	{
		tmp = (Person*)SeqList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	SeqList_Delete(list, 5);//删除链表中超过长度位置的数据，则删除最后一个数据
	for (int i = 0; i<SeqList_Length(list); i++)
	{
		tmp = (Person*)SeqList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	SeqList_Clear(list);//清除链表中的数据	
	for(int i=0; i<SeqList_Length(list); i++)
	{
		tmp = (Person*)SeqList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	count = SeqList_Capacity(list);//得到此时链表的容量，应该不会变
	printf("list的容量:%d\n",count);
	count = SeqList_Length(list);//得到此时链表的长度，应该为0
	printf("list的长度:%d\n", count);
	SeqList_Destory(list);//释放链表内存空间


	system("pause");
}