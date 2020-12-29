#include <stdio.h>
#include "circlelist.h"
//��ʽ�洢����һ������Ĵ洢��Ԫ������Ա��Ԫ�أ�����ҪԤ����洢�ռ䣬Ԫ�ظ���������
typedef struct Value
{
	CircleListNode node;//�ڵ���Ϊ��һ��Ԫ�أ��ڵ㽫�മ������
	int num;
}Value;

void main05()
{
	CircleList* list = NULL;
	CircleListNode* node = NULL;
	int count, ret;
	Value v1, v2, v3, v4, v5, v6, v7, v8;
	Value* tmpv;

	list = CircleList_Create();//��������
	if (list == NULL)
	{
		printf("func CircleList_Create() err\n");
	}
	v1.num = 1;
	v2.num = 2;//Ϊʲô���û��ɾ����
	v3.num = 3;
	v4.num = 4;
	v5.num = 5;
	v6.num = 6;
	v7.num = 7;
	v8.num = 8;
	ret = CircleList_Insert(list, (CircleListNode*)(&v1), 0);//�������в�������
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

	printf("**************��������*************\n");
	for (int i = 0; i< CircleList_Length(list); i++)//��������
	{
		tmpv = (Value*)CircleList_Get(list, i);//�õ������ж�Ӧλ�õ�����
		if (tmpv == NULL)
		{
			printf("func CircleList_Get() err\n");
		}
		printf("age:%d\n", tmpv->num);
	}
	printf("**************�����α���б��*************\n");
	node = CircleList_Reset(list);//�����α�
	if (node == NULL)
	{
		printf("func CircleList_Reset() err");
	}

	while (CircleList_Length(list) > 0)
	{
		for (int i = 0; i< 3; i++)//��������
		{
			tmpv = (Value*)CircleList_Next(list);			
		}
		printf("%d", tmpv->num);//�����������,ע��������﷨
		printf("\n");
		CircleList_Delete2(list, (CircleListNode*)tmpv);//ɾ������
	}
	printf("***************************\n");
	count = CircleList_Length(list);//�õ���ʱ����ĳ��ȣ�Ӧ��Ϊ0
	printf("list�ĳ���:%d\n", count);
	CircleList_Destory(list);//�ͷ������ڴ�ռ�

	system("pause");
}