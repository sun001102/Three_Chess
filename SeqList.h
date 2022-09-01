#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//��malloc ����ռ�realloc����
	int size;//����
	int capacity;//����
}SL;
void SLInit(SL* psl);//˳����ʼ��
void SLDestory(SL* psl);//˳�������
void SLPrint(SL* psl);//��ӡ����
//ͷ��ͷɾ  β��βɾ
void SLPushBack(SL* psl,SLDataType x);//β��
void SLPushFront(SL* psl, SLDataType x);//ͷ��
void SLPopBack(SL* psl);//βɾ
void SLPopFront(SL* psl);//ͷɾ
int SLFind(SL* psl,SLDataType x);//����  �Ҳ�������-1
void SLInsert(SL* psl, size_t pos, SLDataType x);//��posλ�ò���x
void SLErase(SL* psl, size_t pos);//ɾ��posλ�õ�ֵ
void SLModify(SL* psl, size_t pos, SLDataType x);//�޸�posλ�õ�ֵ