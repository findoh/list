#include <stdio.h>
#include "dlinklist.h"

//！！！！双向链表有循环非循环之分，这里写的时循环的双向链表
typedef struct _tag_DoubleLinkList//一个链表包含的信息
{
	DLinkListNode header;//是一个节点而非指针
	DLinkListNode* slider;//定义一个游标
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
	/*tmp->slider = (struct _tag_LinkListNode*)malloc(sizeof(struct _tag_CircleListNode));//slider又不是二级指针，不需要再行分配内存
	//开始的时候是不需要分配内存的，所以开始的时候出现断点，造成内存泄漏
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
	tmp->header.next = NULL;//恢复到初始化的时候
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

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)//insert的时候开始跟单向的循环链表不同了
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* current = &(tmp->header);//添加第二个辅助指针变量
	int ret = 0, i = 0;
	if (list == NULL || node == NULL || pos < 0)
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
	if (tmp->length == 0)//刚开始创建第一个节点
	{
		current->next = node;
		node->pre = node;
		node->next = node;
	}
	else
	{
		for (i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;//将头指针移动到指定位置
		}
		node->next = current->next;//将节点插入两节点之间,正向
		current->next->pre = node;
		current->next = node;		
		if (current == &(tmp->header))//!!!!头插法的时候完全不一样，充分作考虑
		{

			//要将最后的节点与第一个节点串联
			for (i = 0; i < tmp->length + 1; i++)//最后的节点位置是已经添加了新元素的最后位置
			{
				current = current->next;//将头指针移动到指定位置
			}
			current->next = node;
			node->pre = current;
		}
		else
		{
			//循环的也是有好处的，不需要考虑后面为NULL的情况,因为后面要对current作判断，这里不能对current作赋值操作
			node->pre = current;//将节点插入两节点之间,逆向
		}	
		//！！！先试试，再考虑尾插法要不要特别考虑
	}
	tmp->slider = node;//游标指向新增节点的位置，应该都可以吧，视频上指向第一个节点的位置
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
		current = current->next;//将头指针移动到指定位置
	}
	tmp->slider = current;//将游标指向现在的位置
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
	if (pos >= tmp->length)//对位置进行修正，删除链表中超过长度位置的数据，则删除最后一个数据
	{
		pos = tmp->length - 1;
	}
	if (tmp->length == 1)//只剩一个元素时
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
			current = current->next;//将头指针移动到指定位置
		}
		tmpnode = current->next;
		current->next = tmpnode->next;
		tmp->slider = tmpnode->next;//将游标指向被删除节点的后一个位置
		if (current == &(tmp->header))//若删除头节点要特别考虑，还要能够构成循环
		{
			for (i = 0; i < tmp->length - 1; i++)//最后的元素要指向第二个节点
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

//**************新增了游标***************//
DLinkListNode* DLinkList_Reset(DLinkList* list)//重置游标,指向链表第一个数据元素
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

DLinkListNode* DLinkList_Current(DLinkList* list)//获取游标指向的元素
{
	TDLinkList* tmp = (TDLinkList*)list;
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	return tmp->slider;
}

DLinkListNode* DLinkList_Next(DLinkList* list)//返回游标指向的当前元素，并将游标移动下一个元素
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* tmpslider = tmp->slider;//游标的临时变量
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	tmp->slider = tmpslider->next;
	return tmpslider;
}

DLinkListNode* DLinkList_Pre(DLinkList* list)//返回游标指向的当前元素，并将游标移动上一个元素
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* tmpslider = tmp->slider;//游标的临时变量
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	tmp->slider = tmpslider->pre;
	return tmpslider;
}

DLinkListNode* DLinkList_Delete2(DLinkList* list, DLinkListNode* node)//根据元素删除数据,返回删除元素
{
	TDLinkList* tmp = (TDLinkList*)list;
	DLinkListNode* current = &(tmp->header);//为什么第二次经过这里的时候current->next为null呀？
	DLinkListNode* tmpslider = &(tmp->header);//临时变量
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	if (tmp->length == 1)//只剩一个元素时
	{
		tmpslider = current->next;
		current->next = NULL;
		current->pre = NULL;
		current = NULL;
	}
	else
	{
		tmpslider = current->next;
		if (node == tmpslider)//如果把第一个删了，其他的就断了呀，得把第二个摞到前面来
		{
			current->next = tmpslider->next;//头节点指向第二个元素
			for (int i = 0; i < tmp->length - 1; i++)//尾节点也要指向第二个元素才行,长度错了，因为前面一个语句它已经跳过了一个了，找了老久的错，，，，
			{
				current = current->next;
			}
			tmp->slider = tmpslider->next;//游标指向被删除元素的下一个元素才合理吧
			current->next = tmpslider->next;
			tmpslider->pre = current;//记得它有pre
			tmp->length--;//记得将长度减去1
			return tmpslider;
		}
		while (tmpslider != node)//直到找到一样的值才跳出来
		{
			current = current->next;
			tmpslider = current->next;
		}
		tmp->slider = tmpslider->next;//游标指向被删除元素的下一个元素才合理吧
		current->next = tmpslider->next;
		tmpslider->next->pre = current;
	}
	tmp->length--;
	return tmpslider;
}