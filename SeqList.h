#pragma once//��ֹ�ļ��ظ�����
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;//����
}SL;
//�ӿں�����
void SLInit(SL* psl);//��ʼ��
void SLDestory(SL* psl);//����
int  SLFind(SL* psl,SLDataType x);//����
//ͷ��ͷɾ  β��βɾ
void SLPushBack(SL* psl, SLDataType x);//β��
void SLPrint(SL* psl);//��ӡ
void SLPushFront(SL* psl, SLDataType x);//ͷ��
void SLPopBack(SL* psl);//βɾ
void SLPopFront(SL* psl);//ͷɾ
void SLInsert(SL* psl, size_t pos, SLDataType x);//��posλ�ò���
void SLErase(SL* psl, size_t pos);//ɾ��posλ�õ�ֵ
void SLModify(SL* psl, size_t pos, SLDataType x);//�޸�posλ�õ�ֵ
