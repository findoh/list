#pragma once
#ifndef __MY_CIRCLELIST_H__
#define __MY_CIRCLELIST_H__

typedef void CircleList;//void * 以定义一个指针变量，可以指向任何类型的数据

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode* next;//每个节点都包含下个节点的信息，从而形成链表
}CircleListNode;

CircleList* CircleList_Create();

void CircleList_Destory(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

//**************新增了游标***************//
CircleListNode* CircleList_Reset(CircleList* list);//重置游标

CircleListNode* CircleList_Current(CircleList* list);//获取游标指向的数据

CircleListNode* CircleList_Next(CircleList* list);//将游标移动下一个元素,返回现在的值

CircleListNode* CircleList_Delete2(CircleList* list, CircleListNode* node);//根据元素删除数据,C语言不支持重载函数

#endif