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
