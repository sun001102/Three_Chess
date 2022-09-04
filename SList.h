#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//结构体指针
}SLTNode;
void SListPrint(SLTNode* phead);//初始化
void SListDestory(SLTNode** pphead);//销毁释放
SLTNode* BuySLTNode(SLTDataType x);//创建malloc结点的指针
void SListFind(SLTNode* phead);//查找

void SListPushFront(SLTNode** pphead,SLTDataType x);//头插
void SListPushBack(SLTNode** pphead, SLTDataType x);//尾插
void SListPopFront(SLTNode** pphead);//头删
void SListPopBack(SLTNode** pphead);//尾删

