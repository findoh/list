#include <stdio.h>
#include "seqlist.h"

//�ڽṹ�����׶���ָ��
typedef struct  _tag_SeqList
{
	int length;//ע�ⳤ�Ⱥ��ڴ������
	int capacity;
	unsigned int **node;//�����������ָ�����飬Ԥ����洢�ռ�
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	//��Ҫ�ǿ����ڴ�ռ�
	TSeqList* tmp = NULL;
	int ret = 0;
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func (TSeqList*)malloc(sizeof(TSeqList)) err:%d", ret);
		return NULL;
	}
	tmp->node = (unsigned int **)malloc(capacity * sizeof(unsigned int*));//�÷��������ڴ滹�Ǹ㲻̫���
	if (tmp->node == NULL)
	{
		ret = -2;
		printf("func (unsigned int *)malloc(capacity * sizeof(unsigned int*)) err:%d", ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

void SeqList_Destory(SeqList* list)
{
	//��ô���ٵ��ڴ����ô�ͷ�
	TSeqList* tmp = NULL;
	if (list == NULL)
	{
		return;
	}
	tmp = (TSeqList*)list;
	if (tmp->node != NULL)
	{
		free(tmp->node);
	}	
	free(tmp);
	return;
}

void SeqList_Clear(SeqList* list)
{
	TSeqList *tmp = NULL;
	if (list == NULL)
	{
		return;
	}
	tmp = (TSeqList*)list;
	tmp->length = 0;
	return;
}

int SeqList_Length(SeqList* list)
{
	int ret = 0;
	TSeqList* tmp = NULL;
	if (list == NULL)
	{
		ret = -1;
		printf("func list == NULL err:%d", ret);
		return ret;
	}
	tmp = (TSeqList*)list;
	return tmp->length;
}

int SeqList_Capacity(SeqList* list)
{
	int ret = 0;
	TSeqList* tmp = NULL;
	if (list == NULL)
	{
		ret = -1;
		printf("func list == NULL err:%d", ret);
		return ret;
	}
	tmp = (TSeqList*)list;
	return tmp->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList* tmp = (TSeqList*)list;
	int ret = 0, i = 0;
	if (list == NULL || node == NULL || pos < 0|| pos >= tmp->capacity)
	{
		ret = -1;
		printf("func list == NULL || node == NULL || pos < 0 err:%d", ret);
		return ret;
	}
	//��ô��node��ӽ��ڴ���
	if (pos > tmp->length)//��λ�ý�������
	{
		pos = tmp->length;
	}
	for (i =tmp->length; i >pos; i--)//�����ɾ��Ԫ��ʱ��Ҫ�������ƶ�
	{
		tmp->node[i] = tmp->node[i - 1];
	}	
	tmp->node[pos] = (unsigned int*)node;
	tmp->length++;
	return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList* tmp = (TSeqList*)list;
	if (list == NULL || pos < 0 || pos >= tmp->capacity)
	{
		printf("func list == NULL || pos < 0 || pos >= tmp->capacity err");
		return NULL;
	}
	return tmp->node[pos];
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList* tmp = (TSeqList*)list;
	unsigned int* tmpnode;
	int i = 0;
	if (list == NULL || pos < 0 || pos >= tmp->capacity)
	{
		printf("func list == NULL || pos < 0 || pos >= tmp->capacity err");
		return NULL;
	}
	if (pos >= tmp->length)//��λ�ý�������
	{
		pos = tmp->length - 1;
	}
	tmpnode = tmp->node[pos];
	for (i = pos; i < tmp->length - 1; i++)
	{
		tmp->node[i] = tmp->node[i + 1];
	}
	tmp->node[tmp->length - 1] = NULL;
	tmp->length--;
	return tmpnode;//�ײ�Ⲣ��֪��SeqListNode���ڴ���ջ�Ϸ���Ļ��Ƕ��Ϸ���ģ����Բ�û������ͱ�Ҫfree����ڴ�
	               //���ǽ��䷵�س����������ϲ�ҵ��������
}
