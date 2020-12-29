#include <stdio.h>
#include "linklist.h"

typedef struct _tag_LinkList//一个链表包含的信息
{
	LinkListNode* head;//包含头节点，视频教程里这里不是指针，应该都是可以的？非指针更容易些，，，我还是不太清楚啥时候需要用指针
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList* tmp = NULL;
	int ret = 0;
	tmp = (TLinkList*)malloc(sizeof(TLinkList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func (TLinkList*)malloc(sizeof(TLinkList)) err:%d\n", ret);
		return NULL;
	}
	tmp->head = (struct _tag_LinkListNode*)malloc(sizeof(struct _tag_LinkListNode));
	if (tmp->head == NULL)
	{
		ret = -2;
		printf("func (struct _tag_LinkListNode*)malloc(sizeof(struct _tag_LinkListNode)) err:%d\n", ret);
		return NULL;
	}
	tmp->head->next = NULL;//要加吗，让节点的next指向null？
	tmp->length = 0;
	return tmp;
}

void LinkList_Destory(LinkList* list)
{
	TLinkList* tmp = NULL;
	if (list == NULL)
	{
		return;
	}
	tmp = (TLinkList*)list;
	if (tmp->head != NULL)
	{
		free(tmp->head);
	}
	free(tmp);
	return;
}

void LinkList_Clear(LinkList* list) 
{
	TLinkList *tmp = NULL;
	if (list == NULL)
	{
		return;
	}
	tmp = (TLinkList*)list;
	tmp->head->next = NULL;//恢复到初始化的时候
	tmp->length = 0;
	return;
}

int LinkList_Length(LinkList* list)
{
	int ret = 0;
	TLinkList* tmp = NULL;
	if (list == NULL)
	{
		ret = -1;
		printf("func list == NULL err:%d\n", ret);
		return ret;
	}
	tmp = (TLinkList*)list;
	return tmp->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* tmp = (TLinkList*)list; 
	LinkListNode* current = tmp->head;//添加第二个辅助指针变量
	int ret = 0, i = 0;
	if (list == NULL || node == NULL || pos < 0 )
	{
		ret = -1;
		printf("func list == NULL || node == NULL || pos < 0 err:%d\n", ret);
		return ret;
	}
	//怎么把node添加进内存呢
	if (pos > tmp->length)//对位置进行修正
	{
		pos = tmp->length;
	}
	for (i = 0; i < pos; i++)
	{
		current = current->next;//将头指针移动到指定位置
	}
	node->next = current->next;//将节点插入两节点之间
	current->next = node;
	tmp->length++;
	return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	TLinkList* tmp = (TLinkList*)list;
	LinkListNode* current = tmp->head;
	int i = 0;
	if (list == NULL || pos < 0 )
	{
		printf("func list == NULL || pos < 0  err\n");
		return NULL;
	}
	for (i = 0; i <= pos; i++)
	{
		current = current->next;//将头指针移动到指定位置
	}
	return current;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList* tmp = (TLinkList*)list;
	LinkListNode* current = tmp->head;
	LinkListNode* tmpnode;
	int i = 0;
	if (list == NULL || pos < 0 )
	{
		printf("func list == NULL || pos < 0 err");
		return NULL;
	}
	if (pos >= tmp->length)//对位置进行修正
	{
		pos = tmp->length - 1;
	}
	for (i = 0; i < pos; i++)
	{
		current = current->next;//将头指针移动到指定位置
	}
	tmpnode = current->next;
	current->next = tmpnode->next;
	tmp->length--;
	return tmpnode;
}







