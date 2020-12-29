#include <stdio.h>
#include "linklist.h"

typedef struct _tag_LinkList//һ�������������Ϣ
{
	LinkListNode* head;//����ͷ�ڵ㣬��Ƶ�̳������ﲻ��ָ�룬Ӧ�ö��ǿ��Եģ���ָ�������Щ�������һ��ǲ�̫���ɶʱ����Ҫ��ָ��
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
	tmp->head->next = NULL;//Ҫ�����ýڵ��nextָ��null��
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
	tmp->head->next = NULL;//�ָ�����ʼ����ʱ��
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
	LinkListNode* current = tmp->head;//��ӵڶ�������ָ�����
	int ret = 0, i = 0;
	if (list == NULL || node == NULL || pos < 0 )
	{
		ret = -1;
		printf("func list == NULL || node == NULL || pos < 0 err:%d\n", ret);
		return ret;
	}
	//��ô��node��ӽ��ڴ���
	if (pos > tmp->length)//��λ�ý�������
	{
		pos = tmp->length;
	}
	for (i = 0; i < pos; i++)
	{
		current = current->next;//��ͷָ���ƶ���ָ��λ��
	}
	node->next = current->next;//���ڵ�������ڵ�֮��
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
		current = current->next;//��ͷָ���ƶ���ָ��λ��
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
	if (pos >= tmp->length)//��λ�ý�������
	{
		pos = tmp->length - 1;
	}
	for (i = 0; i < pos; i++)
	{
		current = current->next;//��ͷָ���ƶ���ָ��λ��
	}
	tmpnode = current->next;
	current->next = tmpnode->next;
	tmp->length--;
	return tmpnode;
}







