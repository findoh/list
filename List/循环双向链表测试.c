#include <stdio.h>
#include "dlinklist.h"
//��ʽ�洢����һ������Ĵ洢��Ԫ������Ա��Ԫ�أ�����ҪԤ����洢�ռ䣬Ԫ�ظ���������
typedef struct Person
{
	DLinkListNode node;//�ڵ���Ϊ��һ��Ԫ�أ��ڵ㽫�മ������
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

	list = DLinkList_Create();//��������
	if (list == NULL)
	{
		printf("func CircleList_Create() err\n");
	}

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;
	ret = DLinkList_Insert(list, (DLinkListNode*)(&p1), 0);//�������в�������
	if (ret < 0)
	{
		printf("func CircleList_Insert() err:%d\n", ret);
	}
	DLinkList_Insert(list, (DLinkListNode*)(&p2), 0);
	DLinkList_Insert(list, (DLinkListNode*)(&p3), 0);
	DLinkList_Insert(list, (DLinkListNode*)(&p4), 0);
	DLinkList_Insert(list, (DLinkListNode*)(&p5), 0);

	for (int i = 0; i< 2 * DLinkList_Length(list); i++)//��������
	{
		tmp = (Person*)DLinkList_Get(list, i);//�õ������ж�Ӧλ�õ�����
		if (tmp == NULL)
		{
			printf("func CircleList_Get() err\n");
		}
		printf("age:%d\n", tmp->age);
	}//25 24 23 22 21 25 24 23 22 21 
	printf("*************���Բ����Ƿ��ܹ�ʵ��˫��ѭ��**************\n");
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
	printf("age:%d\n", tmp->age);//25���ɹ�
	
	printf("*************����ɾ���м�Ԫ�غ��Ƿ��ܹ�ʵ��˫��ѭ��**************\n");
	//tmp= DLinkList_Delete(list, 1);//ɾ��������λ��Ϊ1������
	tmp = DLinkList_Delete2(list, (DLinkListNode*)(&p4));//ɾ��������ֵΪp4������
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
	printf("age:%d\n", tmp->age);//25���ɹ�
	
	printf("*************����ɾ��ͷԪ�غ��Ƿ��ܹ�ʵ��˫��ѭ��**************\n");
	//DLinkList_Delete(list, 0);
	tmp = DLinkList_Delete2(list, (DLinkListNode*)(&p5));//ɾ��������ֵΪp5������
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
	printf("age:%d\n", tmp->age);//23���ɹ�

	printf("*************��������е�����**************\n");
	DLinkList_Clear(list);//��������е�����	
	for (int i = 0; i<DLinkList_Length(list); i++)
	{
		tmp = (Person*)DLinkList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	count = DLinkList_Length(list);//�õ���ʱ����ĳ��ȣ�Ӧ��Ϊ0
	printf("list�ĳ���:%d\n", count);
	DLinkList_Destory(list);//�ͷ������ڴ�ռ�

	system("pause");
}