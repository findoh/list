#pragma once
#ifndef __MY_CIRCLELIST_H__
#define __MY_CIRCLELIST_H__

typedef void CircleList;//void * �Զ���һ��ָ�����������ָ���κ����͵�����

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode* next;//ÿ���ڵ㶼�����¸��ڵ����Ϣ���Ӷ��γ�����
}CircleListNode;

CircleList* CircleList_Create();

void CircleList_Destory(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

//**************�������α�***************//
CircleListNode* CircleList_Reset(CircleList* list);//�����α�

CircleListNode* CircleList_Current(CircleList* list);//��ȡ�α�ָ�������

CircleListNode* CircleList_Next(CircleList* list);//���α��ƶ���һ��Ԫ��,�������ڵ�ֵ

CircleListNode* CircleList_Delete2(CircleList* list, CircleListNode* node);//����Ԫ��ɾ������,C���Բ�֧�����غ���

#endif