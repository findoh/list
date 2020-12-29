#include <stdio.h>
#include "circlelist.h"

typedef struct _tag_CircleList//一个链表包含的信息
{
	CircleListNode header;//是一个节点而非指针
	CircleListNode* slider;//定义一个游标
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
	/*tmp->slider = (struct _tag_LinkListNode*)malloc(sizeof(struct _tag_CircleListNode));//slider开始的时候是不需要分配内存的，所以开始的时候出现断点，造成内存泄漏
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
	tmp->header.next = NULL;//恢复到初始化的时候
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

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)//这里要体现循环链表的厉害,如果使用头插法这个函数就有问题
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* current = &(tmp->header);//添加第二个辅助指针变量
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
		pos = tmp->length;//如果是pos为length的位置，非特殊状态
	}
	if (tmp->length == 0)//第一个位置的时候要让node->next 不为空，开始的时候写的pos=0，是十分错误的，判断条件一定要考虑清楚！！！
	{
		//node->next = current->next;//将节点插入两节点之间
		current->next = node;
		node->next = node;//如果没有将next指向自己的话，后面不就没有循环的前提了？为什么视频中没有
	}
	else
	{
		for (i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;//将头指针移动到指定位置
		}
		node->next = current->next;//将节点插入两节点之间
		current->next = node;
		if (current == &(tmp->header))//!!!!头插法的时候要将    pos == 0 时
		{
			//要将最后的节点与第一个节点串联
			for (i = 0; i < tmp->length + 1; i++)//最后的节点位置是已经添加了新元素的最后位置
			{
				current = current->next;//将头指针移动到指定位置
			}
			current->next = node;

			/*CircleListNode* last = CircleList_Get(tmp, tmp->length - 1);
			last->next = current->next;*/
		}
	}
	tmp->slider = node;//游标指向新增节点的位置，应该都可以吧，视频上指向第一个节点的位置
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
		current = current->next;//将头指针移动到指定位置
	}
	tmp->slider = current;//将游标指向现在的位置
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
	if (pos >= tmp->length)//对位置进行修正，删除链表中超过长度位置的数据，则删除最后一个数据
	{
		pos = tmp->length - 1;
	}
	if (tmp->length == 1)//只剩一个元素时
	{
		tmpnode = current->next;
		current->next = NULL;
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
		}
	}	
	tmp->length--;
	return tmpnode;
}

//**************新增了游标***************//
CircleListNode* CircleList_Reset(CircleList* list)//重置游标,指向链表第一个数据元素
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

CircleListNode* CircleList_Current(CircleList* list)//获取游标指向的元素
{
	TCircleList* tmp = (TCircleList*)list;
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	return tmp->slider;
}

CircleListNode* CircleList_Next(CircleList* list)//返回游标指向的当前元素，并将游标移动下一个元素
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* tmpslider = tmp->slider;//游标的临时变量
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
	tmp->slider = tmpslider->next;
	return tmpslider;
}

CircleListNode* CircleList_Delete2(CircleList* list, CircleListNode* node)//根据元素删除数据,返回删除元素
{
	TCircleList* tmp = (TCircleList*)list;
	CircleListNode* current = &(tmp->header);//为什么第二次经过这里的时候current->next为null呀？
	CircleListNode* tmpslider = &(tmp->header);//游标的临时变量
	if (list == NULL)
	{
		printf("func list == NULL  err\n");
		return NULL;
	}
    tmpslider = current->next;
	if (node == tmpslider)//如果把第一个删了，其他的就断了呀，得把第二个摞到前面来
	{
		current->next = tmpslider->next;//头节点指向第二个元素
		for (int i = 0; i < tmp->length - 1; i++)//尾节点也要指向第二个元素才行,长度错了，因为前面一个语句它已经跳过了一个了，找了老久的错，，，，
		{
			current = current->next;
		}
		current->next = tmpslider->next;
		tmp->length --;//记得将长度减去1
		return tmpslider;
	}
	while (tmpslider != node)//直到找到一样的值才跳出来
	{
		current = current->next;
		tmpslider = current->next;
	}
	//tmp->slider = tmpslider->next;//游标指向被删除元素的下一个元素才合理吧，这里好像不用管游标
	current->next = tmpslider->next;	
	tmp->length--;
	return tmpslider;
}