#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//用malloc 申请空间realloc调整
	int size;//个数
	int capacity;//容量
}SL;
void SLInit(SL* psl);//顺序表初始化
void SLDestory(SL* psl);//顺序表销毁
void SLPrint(SL* psl);//打印数据
//头插头删  尾插尾删
void SLPushBack(SL* psl,SLDataType x);//尾插
void SLPushFront(SL* psl, SLDataType x);//头插
void SLPopBack(SL* psl);//尾删
void SLPopFront(SL* psl);//头删
int SLFind(SL* psl,SLDataType x);//查找  找不到返回-1
void SLInsert(SL* psl, size_t pos, SLDataType x);//在pos位置插入x
void SLErase(SL* psl, size_t pos);//删除pos位置的值
void SLModify(SL* psl, size_t pos, SLDataType x);//修改pos位置的值