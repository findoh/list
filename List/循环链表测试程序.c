#include <stdio.h>
#include "circlelist.h"
//��ʽ�洢����һ������Ĵ洢��Ԫ������Ա��Ԫ�أ�����ҪԤ����洢�ռ䣬Ԫ�ظ���������
typedef struct Person
{
	CircleListNode node;//�ڵ���Ϊ��һ��Ԫ�أ��ڵ㽫�മ������
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

	list = CircleList_Create();//��������
	if (list == NULL)
	{
		printf("func CircleList_Create() err\n");
	}

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;
	ret = CircleList_Insert(list, (CircleListNode*)(&p1), 0);//�������в�������
	if (ret < 0)
	{
		printf("func CircleList_Insert() err:%d\n", ret);
	}
	CircleList_Insert(list, (CircleListNode*)(&p2), 0);
	CircleList_Insert(list, (CircleListNode*)(&p3), 0);
	CircleList_Insert(list, (CircleListNode*)(&p4), 0);
	CircleList_Insert(list, (CircleListNode*)(&p5), 0);

	for (int i = 0; i< 2*CircleList_Length(list); i++)//��������
	{
		tmp = (Person*)CircleList_Get(list, i);//�õ������ж�Ӧλ�õ�����
		if (tmp == NULL)
		{
			printf("func CircleList_Get() err\n");
		}
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	tmp = CircleList_Delete(list, 1);//ɾ��������λ��Ϊ1������
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
	//count = CircleList_Length(list);//�õ���ʱ����ĳ��ȣ�Ӧ��Ϊ0
	//printf("list�ĳ���:%d\n", count);
	CircleList_Clear(list);//��������е�����	
	for (int i = 0; i<CircleList_Length(list); i++)
	{
		tmp = (Person*)CircleList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	count = CircleList_Length(list);//�õ���ʱ����ĳ��ȣ�Ӧ��Ϊ0
	printf("list�ĳ���:%d\n", count);
	CircleList_Destory(list);//�ͷ������ڴ�ռ�

	system("pause");
}