#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//�ṹ��ָ��
}SLTNode;
void SListPrint(SLTNode* phead);//��ʼ��
void SListDestory(SLTNode** pphead);//�����ͷ�
SLTNode* BuySLTNode(SLTDataType x);//����malloc����ָ��
void SListFind(SLTNode* phead);//����

void SListPushFront(SLTNode** pphead,SLTDataType x);//ͷ��
void SListPushBack(SLTNode** pphead, SLTDataType x);//β��
void SListPopFront(SLTNode** pphead);//ͷɾ
void SListPopBack(SLTNode** pphead);//βɾ

