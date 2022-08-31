#pragma once//防止文件重复包括
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;//容量
}SL;
//接口函数：
void SLInit(SL* psl);//初始化
void SLDestory(SL* psl);//销毁
int  SLFind(SL* psl,SLDataType x);//查找
//头插头删  尾插尾删
void SLPushBack(SL* psl, SLDataType x);//尾插
void SLPrint(SL* psl);//打印
void SLPushFront(SL* psl, SLDataType x);//头插
void SLPopBack(SL* psl);//尾删
void SLPopFront(SL* psl);//头删
void SLInsert(SL* psl, size_t pos, SLDataType x);//在pos位置插入
void SLErase(SL* psl, size_t pos);//删除pos位置的值
void SLModify(SL* psl, size_t pos, SLDataType x);//修改pos位置的值
