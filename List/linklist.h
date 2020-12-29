#pragma once
#ifndef __MY_LINKLIST_H__
#define __MY_LINKLIST_H__

typedef void LinkList;//void * 以定义一个指针变量，可以指向任何类型的数据

typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;//每个节点都包含下个节点的信息，从而形成链表
}LinkListNode;

LinkList* LinkList_Create();

void LinkList_Destory(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif