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
