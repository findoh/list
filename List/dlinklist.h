#pragma once
#ifndef __MY_DOUBLELINKLIST_H__
#define __MY_DOUBLELINKLIST_H__

typedef void DLinkList;//void * �Զ���һ��ָ�����������ָ���κ����͵�����

typedef struct _tag_DoubleLinkListNode
{
	struct _tag_DoubleLinkListNode* next;//ÿ���ڵ㶼�����¸��ڵ����Ϣ���Ӷ��γ�����
	struct _tag_DoubleLinkListNode* pre;//ÿ���ڵ㶼�����ϸ��ڵ����Ϣ���Ӷ��γ�˫������
}DLinkListNode;

DLinkList* DLinkList_Create();

void DLinkList_Destory(DLinkList* list);

void DLinkList_Clear(DLinkList* list);

int DLinkList_Length(DLinkList* list);

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);

//**************�α�***************//
DLinkListNode* DLinkList_Reset(DLinkList* list);//�����α�

DLinkListNode* DLinkList_Current(DLinkList* list);//��ȡ�α�ָ�������

DLinkListNode* DLinkList_Next(DLinkList* list);//���α��ƶ���һ��Ԫ��,�������ڵ�ֵ

DLinkListNode* DLinkList_Pre(DLinkList* list);//���α��ƶ���һ��Ԫ��,�������ڵ�ֵ

DLinkListNode* DLinkList_Delete2(DLinkList* list, DLinkListNode* node);//����Ԫ��ɾ������,C���Բ�֧�����غ���


#endif
