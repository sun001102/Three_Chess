#include "SList.h"
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;//phead �����Ҳ���ͷ
	while (cur != NULL)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
}
//�����½��
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
void SListPushFront(SLTNode** pphead, SLTDataType x)//ͷ��
{//���ܶ���ֲ�����   ������뵽���� ���˻���  �ֲ����������������  ����Ҫ���
	SLTNode* newnode = BuySLTNode(x);
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//1.��
	//2.�ǿ�
	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{//��β
		SLTNode* tail = *pphead;//ָ���һ���ڵ�
		while (tail->next != NULL)//��β
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	//ɾ���ˣ�//����ļ��
	if (*pphead == NULL)
	{
		return;
	}
	assert(*pphead != NULL);//�����ļ��
	SLTNode* del = *pphead;
	*pphead =(* pphead)->next;
	free(del);
	del = NULL;
}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);
	//һ���ڵ�
	// ����ڵ�
	if ((*pphead)->next == NULL)
	{
		*pphead = NULL;
	}
	else
	{
		//��β
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
}//��pos֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)//ͷ��
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
			//���pos���������нڵ㣬��������
			assert(prev);
		}
		prev->next = pos->next;
		free(pos);
	}
}