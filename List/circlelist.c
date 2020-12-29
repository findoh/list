#include <stdio.h>
#include "circlelist.h"

typedef struct _tag_CircleList//һ�������������Ϣ
{
	CircleListNode header;//��һ���ڵ����ָ��
	CircleListNode* slider;//����һ���α�
	int length;
}TCircleList;

CircleList* CircleList_Create()
{
	TCircleList* tmp = NULL;
	int ret = 0;
	tmp = (TCircleList*)malloc(sizeof(TCircleList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func (TLinkList*)malloc(sizeof(TLinkList)) err:%d\n", ret);
		return NULL;
	}
	/*tmp->slider = (struct _tag_LinkListNode*)malloc(sizeof(struct _tag_CircleListNode));//slider��ʼ��ʱ���ǲ���Ҫ�����ڴ�ģ����Կ�ʼ��ʱ����ֶϵ㣬����ڴ�й©
	if (tmp->slider == NULL)
	{
		ret = -2;
		printf("func (struct _tag_LinkListNode*)malloc(sizeof(struct _tag_LinkListNode)) err:%d\n", ret);
		return NULL;
	}*/
	tmp->header.next = NULL;
	tmp->slider = NULL;
	tmp->length = 0;
	return tmp;
}

void CircleList_Destory(CircleList* list)
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

void CircleList_Clear(CircleList* list)
{
	TCircleList *tmp = NULL;
	if (list == NULL)
	{
		return;
	}
	tmp = (TCircleList*)list;
	tmp->header.next = NULL;//�ָ�����ʼ����ʱ��
	tmp->slider = NULL;
	tmp->length = 0;
	return;
}

int CircleList_Length(CircleList* list)
{
	int ret = 0;
	TCircleList* tmp = NULL;
	if (list == NULL)
	{
		ret = -1;
		printf("func list == NULL err:%d\n", ret);
		return ret;
	}
	tmp = (TCircleList*)list;
	return tmp->length;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)//����Ҫ����ѭ�����������,���ʹ��ͷ�巨���������������
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* current = &(tmp->header);//��ӵڶ�������ָ�����
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
		pos = tmp->length;//�����posΪlength��λ�ã�������״̬
	}
	if (tmp->length == 0)//��һ��λ�õ�ʱ��Ҫ��node->next ��Ϊ�գ���ʼ��ʱ��д��pos=0����ʮ�ִ���ģ��ж�����һ��Ҫ�������������
	{
		//node->next = current->next;//���ڵ�������ڵ�֮��
		current->next = node;
		node->next = node;//���û�н�nextָ���Լ��Ļ������治��û��ѭ����ǰ���ˣ�Ϊʲô��Ƶ��û��
	}
	else
	{
		for (i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;//��ͷָ���ƶ���ָ��λ��
		}
		node->next = current->next;//���ڵ�������ڵ�֮��
		current->next = node;
		if (current == &(tmp->header))//!!!!ͷ�巨��ʱ��Ҫ��    pos == 0 ʱ
		{
			//Ҫ�����Ľڵ����һ���ڵ㴮��
			for (i = 0; i < tmp->length + 1; i++)//���Ľڵ�λ�����Ѿ��������Ԫ�ص����λ��
			{
				current = current->next;//��ͷָ���ƶ���ָ��λ��
			}
			current->next = node;

			/*CircleListNode* last = CircleList_Get(tmp, tmp->length - 1);
			last->next = current->next;*/
		}
	}
	tmp->slider = node;//�α�ָ�������ڵ��λ�ã�Ӧ�ö����԰ɣ���Ƶ��ָ���һ���ڵ��λ��
	tmp->length++;
	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* current = &(tmp->header);
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

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* current = &(tmp->header);
	CircleListNode* tmpnode;
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
		}
	}	
	tmp->length--;
	return tmpnode;
}

//**************�������α�***************//
CircleListNode* CircleList_Reset(CircleList* list)//�����α�,ָ�������һ������Ԫ��
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* current = &(tmp->header);
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}	
	tmp->slider = current->next;
	return current->next;
}

CircleListNode* CircleList_Current(CircleList* list)//��ȡ�α�ָ���Ԫ��
{
	TCircleList* tmp = (TCircleList*)list;
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	return tmp->slider;
}

CircleListNode* CircleList_Next(CircleList* list)//�����α�ָ��ĵ�ǰԪ�أ������α��ƶ���һ��Ԫ��
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* tmpslider = tmp->slider;//�α����ʱ����
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	tmp->slider = tmpslider->next;
	return tmpslider;
}

CircleListNode* CircleList_Delete2(CircleList* list, CircleListNode* node)//����Ԫ��ɾ������,����ɾ��Ԫ��
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* current = &(tmp->header);//Ϊʲô�ڶ��ξ��������ʱ��current->nextΪnullѽ��
	CircleListNode* tmpslider = &(tmp->header);//�α����ʱ����
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
    tmpslider = current->next;
	if (node == tmpslider)//����ѵ�һ��ɾ�ˣ������ľͶ���ѽ���ðѵڶ�������ǰ����
	{
		current->next = tmpslider->next;//ͷ�ڵ�ָ��ڶ���Ԫ��
		for (int i = 0; i < tmp->length - 1; i++)//β�ڵ�ҲҪָ��ڶ���Ԫ�ز���,���ȴ��ˣ���Ϊǰ��һ��������Ѿ�������һ���ˣ������ϾõĴ�������
		{
			current = current->next;
		}
		current->next = tmpslider->next;
		tmp->length --;//�ǵý����ȼ�ȥ1
		return tmpslider;
	}
	while (tmpslider != node)//ֱ���ҵ�һ����ֵ��������
	{
		current = current->next;
		tmpslider = current->next;
	}
	//tmp->slider = tmpslider->next;//�α�ָ��ɾ��Ԫ�ص���һ��Ԫ�زź���ɣ���������ù��α�
	current->next = tmpslider->next;	
	tmp->length--;
	return tmpslider;
}