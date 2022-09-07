#include "SList.h"
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;//phead 容易找不到头
	while (cur != NULL)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
}
//创建新结点
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode=(SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perro("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
}
void SListPushFront(SLTNode** pphead, SLTDataType x)//头插
{//不能定义局部变量   链表插入到里面 完了还在  局部出了作用域就销毁  都与要结点
	SLTNode* newnode = BuySLTNode(x);
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//1.空
	//2.非空
	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{//找尾
		SLTNode* tail = *pphead;//指向第一个节点
		while (tail->next != NULL)//找尾
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	//删光了？//温柔的检查
	if (*pphead == NULL)
	{
		return;
	}
	assert(*pphead != NULL);//暴力的检查
	SLTNode* del = *pphead;
	*pphead =(* pphead)->next;
	free(del);
	del = NULL;
}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);
	//一个节点
	// 多个节点
	if ((*pphead)->next == NULL)
	{
		*pphead = NULL;
	}
	else
	{
		//找尾
		SLTNode* perv = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			perv = tail;
			tail = tail->next;
		}
		perv->next = NULL;
		free(tail);
		tail = NULL;
	}
}
void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur!=NULL)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
SLTNode* SListFind(SLTNode* phead, SLTDataType X)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}//在pos之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)//头插
	{
		SListPushFront(pphead,x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuySLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	pos->next = newnode;
	newnode->next = pos->next;
}
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	SLTNode* prev = NULL;
	if (*pphead==pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
			//检查pos不是链表中节点，参数传错
			assert(prev);
		}
		prev->next = pos->next;
		free(pos);
	}
}