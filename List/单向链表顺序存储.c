#include <stdio.h>
#include "seqlist.h"
//˳��洢����һ�������Ĵ洢��Ԫ���δ洢���Ա�ĵ�����Ԫ�أ���ҪԤ����洢�ռ�
typedef struct Person
{
	//////////////SeqListNode* node;//��������ڵ㣬��ʱ�ڵ��λ�þ������λ�ã�
	//���ﲻ��Ҫ��˳��ṹ���������ڴ��
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

	list = SeqList_Create(10);//��������
	if (list == NULL)//û����һ�κ��������Ҫ�����жϣ������ȽϹ淶
	{
		printf("func SeqList_Create() err\n");
		return;
	}

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;
	SeqList_Insert(list, (SeqListNode*)(&p1), 0);//�������в�������
	SeqList_Insert(list, (SeqListNode*)(&p2), 0);
	SeqList_Insert(list, (SeqListNode*)(&p3), 0);
	SeqList_Insert(list, (SeqListNode*)(&p4), 0);
	SeqList_Insert(list, (SeqListNode*)(&p5), 0);
	
	for (int i = 0; i<SeqList_Length(list); i++)//��������
	{
		tmp = (Person*)SeqList_Get(list, i);//�õ������ж�Ӧλ�õ�����
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	SeqList_Delete(list, 1);//ɾ��������λ��Ϊ1������
	for (int i = 0; i<SeqList_Length(list); i++)
	{
		tmp = (Person*)SeqList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	SeqList_Delete(list, 5);//ɾ�������г�������λ�õ����ݣ���ɾ�����һ������
	for (int i = 0; i<SeqList_Length(list); i++)
	{
		tmp = (Person*)SeqList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	SeqList_Clear(list);//��������е�����	
	for(int i=0; i<SeqList_Length(list); i++)
	{
		tmp = (Person*)SeqList_Get(list, i);
		printf("age:%d\n", tmp->age);
	}
	printf("***************************\n");
	count = SeqList_Capacity(list);//�õ���ʱ�����������Ӧ�ò����
	printf("list������:%d\n",count);
	count = SeqList_Length(list);//�õ���ʱ����ĳ��ȣ�Ӧ��Ϊ0
	printf("list�ĳ���:%d\n", count);
	SeqList_Destory(list);//�ͷ������ڴ�ռ�


	system("pause");
}