#include <stdio.h>
#include "dlinklist.h"

//��������˫��������ѭ����ѭ��֮�֣�����д��ʱѭ����˫������
typedef struct _tag_DoubleLinkList//һ�������������Ϣ
{
	DLinkListNode header;//��һ���ڵ����ָ��
	DLinkListNode* slider;//����һ���α�
	int length;
}TDLinkList;

DLinkList* DLinkList_Create()
{
	TDLinkList* tmp = NULL;
	int ret = 0;
	tmp = (TDLinkList*)malloc(sizeof(TDLinkList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func (TLinkList*)malloc(sizeof(TLinkList)) err:%d\n", ret);
		return NULL;
	}
	/*tmp->slider = (struct _tag_LinkListNode*)malloc(sizeof(struct _tag_CircleListNode));//slider�ֲ��Ƕ���ָ�룬����Ҫ���з����ڴ�
	//��ʼ��ʱ���ǲ���Ҫ�����ڴ�ģ����Կ�ʼ��ʱ����ֶϵ㣬����ڴ�й©
	if (tmp->slider == NULL)
	{
	ret = -2;
	printf("func (struct _tag_LinkListNode*)malloc(sizeof(struct _tag_LinkListNode)) err:%d\n", ret);
	return NULL;
	}*/
	tmp->header.next = NULL;
	tmp->header.pre = NULL;
	tmp->slider = NULL;
	tmp->length = 0;
	return tmp;
}

void DLinkList_Destory(DLinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	/*tmp = (TCircleList*)list;
	if (tmp->slider != NULL)
	{
	free(tmp->slider);
	}*/
	free(list);
}

void DLinkList_Clear(DLinkList* list)
{
	TDLinkList *tmp = NULL;
	if (list == NULL)
	{
		return;
	}
	tmp = (TDLinkList*)list;
	tmp->header.next = NULL;//�ָ�����ʼ����ʱ��
	tmp->header.pre = NULL;
	tmp->slider = NULL;
	tmp->length = 0;
	return;
}

int DLinkList_Length(DLinkList* list)
{
	int ret = 0;
	TDLinkList* tmp = NULL;
	if (list == NULL)
	{
		ret = -1;
		printf("func list == NULL err:%d\n", ret);
		return ret;
	}
	tmp = (TDLinkList*)list;
	return tmp->length;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)//insert��ʱ��ʼ�������ѭ������ͬ��
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* current = &(tmp->header);//��ӵڶ�������ָ�����
	int ret = 0, i = 0;
	if (list == NULL || node == NULL || pos < 0)
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
	if (tmp->length == 0)//�տ�ʼ������һ���ڵ�
	{
		current->next = node;
		node->pre = node;
		node->next = node;
	}
	else
	{
		for (i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;//��ͷָ���ƶ���ָ��λ��
		}
		node->next = current->next;//���ڵ�������ڵ�֮��,����
		current->next->pre = node;
		current->next = node;		
		if (current == &(tmp->header))//!!!!ͷ�巨��ʱ����ȫ��һ�������������
		{

			//Ҫ�����Ľڵ����һ���ڵ㴮��
			for (i = 0; i < tmp->length + 1; i++)//���Ľڵ�λ�����Ѿ��������Ԫ�ص����λ��
			{
				current = current->next;//��ͷָ���ƶ���ָ��λ��
			}
			current->next = node;
			node->pre = current;
		}
		else
		{
			//ѭ����Ҳ���кô��ģ�����Ҫ���Ǻ���ΪNULL�����,��Ϊ����Ҫ��current���жϣ����ﲻ�ܶ�current����ֵ����
			node->pre = current;//���ڵ�������ڵ�֮��,����
		}	
		//�����������ԣ��ٿ���β�巨Ҫ��Ҫ�ر���
	}
	tmp->slider = node;//�α�ָ�������ڵ��λ�ã�Ӧ�ö����԰ɣ���Ƶ��ָ���һ���ڵ��λ��
	tmp->length++;
	return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* current = &(tmp->header);
	int i = 0;
	if (list == NULL || pos < 0)
	{
		printf("func list == NULL || pos < 0  err\n");
		return NULL;
	}
	for (i = 0; i <= pos; i++)
	{
		current = current->next;//��ͷָ���ƶ���ָ��λ��
	}
	tmp->slider = current;//���α�ָ�����ڵ�λ��
	return current;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* current = &(tmp->header);
	DLinkListNode* tmpnode;
	int i = 0;
	if (list == NULL || pos < 0)
	{
		printf("func list == NULL || pos < 0 err");
		return NULL;
	}
	if (pos >= tmp->length)//��λ�ý���������ɾ�������г�������λ�õ����ݣ���ɾ�����һ������
	{
		pos = tmp->length - 1;
	}
	if (tmp->length == 1)//ֻʣһ��Ԫ��ʱ
	{
		tmpnode = current->next;
		current->next = NULL;
		current->pre = NULL;
		current = NULL;
	}
	else
	{
		for (i = 0; i < pos; i++)
		{
			current = current->next;//��ͷָ���ƶ���ָ��λ��
		}
		tmpnode = current->next;
		current->next = tmpnode->next;
		tmp->slider = tmpnode->next;//���α�ָ��ɾ���ڵ�ĺ�һ��λ��
		if (current == &(tmp->header))//��ɾ��ͷ�ڵ�Ҫ�ر��ǣ���Ҫ�ܹ�����ѭ��
		{
			for (i = 0; i < tmp->length - 1; i++)//����Ԫ��Ҫָ��ڶ����ڵ�
			{
				current = current->next;
			}
			current->next = tmpnode->next;
			tmpnode->pre = current;

		}
		else
		{
			tmpnode->next->pre = current;
		}
	}
	tmp->length--;
	return tmpnode;
}

//**************�������α�***************//
DLinkListNode* DLinkList_Reset(DLinkList* list)//�����α�,ָ�������һ������Ԫ��
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* current = &(tmp->header);
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	tmp->slider = current->next;
	return current->next;
}

DLinkListNode* DLinkList_Current(DLinkList* list)//��ȡ�α�ָ���Ԫ��
{
	TDLinkList* tmp = (TDLinkList*)list;
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	return tmp->slider;
}

DLinkListNode* DLinkList_Next(DLinkList* list)//�����α�ָ��ĵ�ǰԪ�أ������α��ƶ���һ��Ԫ��
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* tmpslider = tmp->slider;//�α����ʱ����
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	tmp->slider = tmpslider->next;
	return tmpslider;
}

DLinkListNode* DLinkList_Pre(DLinkList* list)//�����α�ָ��ĵ�ǰԪ�أ������α��ƶ���һ��Ԫ��
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* tmpslider = tmp->slider;//�α����ʱ����
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	tmp->slider = tmpslider->pre;
	return tmpslider;
}

DLinkListNode* DLinkList_Delete2(DLinkList* list, DLinkListNode* node)//����Ԫ��ɾ������,����ɾ��Ԫ��
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* current = &(tmp->header);//Ϊʲô�ڶ��ξ��������ʱ��current->nextΪnullѽ��
	DLinkListNode* tmpslider = &(tmp->header);//��ʱ����
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	if (tmp->length == 1)//ֻʣһ��Ԫ��ʱ
	{
		tmpslider = current->next;
		current->next = NULL;
		current->pre = NULL;
		current = NULL;
	}
	else
	{
		tmpslider = current->next;
		if (node == tmpslider)//����ѵ�һ��ɾ�ˣ������ľͶ���ѽ���ðѵڶ�������ǰ����
		{
			current->next = tmpslider->next;//ͷ�ڵ�ָ��ڶ���Ԫ��
			for (int i = 0; i < tmp->length - 1; i++)//β�ڵ�ҲҪָ��ڶ���Ԫ�ز���,���ȴ��ˣ���Ϊǰ��һ��������Ѿ�������һ���ˣ������ϾõĴ�������
			{
				current = current->next;
			}
			tmp->slider = tmpslider->next;//�α�ָ��ɾ��Ԫ�ص���һ��Ԫ�زź����
			current->next = tmpslider->next;
			tmpslider->pre = current;//�ǵ�����pre
			tmp->length--;//�ǵý����ȼ�ȥ1
			return tmpslider;
		}
		while (tmpslider != node)//ֱ���ҵ�һ����ֵ��������
		{
			current = current->next;
			tmpslider = current->next;
		}
		tmp->slider = tmpslider->next;//�α�ָ��ɾ��Ԫ�ص���һ��Ԫ�زź����
		current->next = tmpslider->next;
		tmpslider->next->pre = current;
	}
	tmp->length--;
	return tmpslider;
}