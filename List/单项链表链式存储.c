#include <stdio.h>
#include "linklist.h"
//��ʽ�洢����һ������Ĵ洢��Ԫ������Ա��Ԫ�أ�����ҪԤ����洢�ռ䣬Ԫ�ظ���������
typedef struct Person
{
	LinkListNode node;//�ڵ���Ϊ��һ��Ԫ�أ��ڵ㽫�മ������
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

	list = LinkList_Create();//��������

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;
	LinkList_Insert(list, (LinkListNode*)(&p1), 0);//�������в�������
	LinkList_Insert(list, (LinkListNode*)(&p2), 1);
	LinkList_Insert(list, (LinkListNode*)(&p3), 2);
	LinkList_Insert(list, (LinkListNode*)(&p4), 3);
	LinkList_Insert(list, (LinkListNode*)(&p5), 4);

	for (int i = 0; i<LinkList_Length(list); i++)//��������
	{
		tmp = (Person*)LinkList_Get(list, i);//�õ������ж�Ӧλ�õ�����
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	LinkList_Delete(list, 1);//ɾ��������λ��Ϊ1������
	for (int i = 0; i<LinkList_Length(list); i++)
	{
		tmp = (Person*)LinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	LinkList_Delete(list, 5);//ɾ�������г�������λ�õ����ݣ���ɾ�����һ������
	for (int i = 0; i<LinkList_Length(list); i++)
	{
		tmp = (Person*)LinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	LinkList_Clear(list);//��������е�����	
	for (int i = 0; i<LinkList_Length(list); i++)
	{
		tmp = (Person*)LinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	count = LinkList_Length(list);//�õ���ʱ����ĳ��ȣ�Ӧ��Ϊ0
	printf("list�ĳ���:%d\n", count);
	LinkList_Destory(list);//�ͷ������ڴ�ռ�

	system("pause");
}