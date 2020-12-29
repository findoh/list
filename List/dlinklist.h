#pragma once
#ifndef __MY_DOUBLELINKLIST_H__
#define __MY_DOUBLELINKLIST_H__

typedef void DLinkList;//void * 以定义一个指针变量，可以指向任何类型的数据

typedef struct _tag_DoubleLinkListNode
{
	struct _tag_DoubleLinkListNode* next;//每个节点都包含下个节点的信息，从而形成链表
	struct _tag_DoubleLinkListNode* pre;//每个节点都包含上个节点的信息，从而形成双向链表
}DLinkListNode;

DLinkList* DLinkList_Create();

void DLinkList_Destory(DLinkList* list);

void DLinkList_Clear(DLinkList* list);

int DLinkList_Length(DLinkList* list);

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);

//**************游标***************//
DLinkListNode* DLinkList_Reset(DLinkList* list);//重置游标

DLinkListNode* DLinkList_Current(DLinkList* list);//获取游标指向的数据

DLinkListNode* DLinkList_Next(DLinkList* list);//将游标移动下一个元素,返回现在的值

DLinkListNode* DLinkList_Pre(DLinkList* list);//将游标移动上一个元素,返回现在的值

DLinkListNode* DLinkList_Delete2(DLinkList* list, DLinkListNode* node);//根据元素删除数据,C语言不支持重载函数


#endif
