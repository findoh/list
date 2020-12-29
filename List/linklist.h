#pragma once
#ifndef __MY_LINKLIST_H__
#define __MY_LINKLIST_H__

typedef void LinkList;//void * �Զ���һ��ָ�����������ָ���κ����͵�����

typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;//ÿ���ڵ㶼�����¸��ڵ����Ϣ���Ӷ��γ�����
}LinkListNode;

LinkList* LinkList_Create();

void LinkList_Destory(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif