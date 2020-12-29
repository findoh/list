#include <stdio.h>
#include "seqlist.h"

//在结构体中套二级指针
typedef struct  _tag_SeqList
{
	int length;//注意长度和内存的区别
	int capacity;
	unsigned int **node;//链表里包含的指针数组，预分配存储空间
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	//主要是开辟内存空间
	TSeqList* tmp = NULL;
	int ret = 0;
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func (TSeqList*)malloc(sizeof(TSeqList)) err:%d", ret);
		return NULL;
	}
	tmp->node = (unsigned int **)malloc(capacity * sizeof(unsigned int*));//该分配哪种内存还是搞不太清楚
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
	//怎么开辟的内存就怎么释放
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
	//怎么把node添加进内存呢
	if (pos > tmp->length)//对位置进行修正
	{
		pos = tmp->length;
	}
	for (i =tmp->length; i >pos; i--)//插入或删除元素时需要大量的移动
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
	if (pos >= tmp->length)//对位置进行修正
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
	return tmpnode;//底层库并不知道SeqListNode的内存是栈上分配的还是堆上分配的，所以并没有义务和必要free这块内存
	               //而是将其返回出来，交给上层业务做处理
}
