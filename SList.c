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

void SListPushFront(SLTNode** pphead, SLTDataType x)
{//���ܶ���ֲ�����   ������뵽���� ���˻���  �ֲ����������������  ����Ҫ���
	SLTNode* S;
		printf("ϣ����������� ��θ�� ������������ѽ ����  ");
}
