#include "SeqList.h"
int  SLFind(SL* psl, SLDataType x)//����
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SLCheckCapacity(SL* psl)
{
//�������  �գ�����
	if (psl->size == psl->capacity)//����
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;//����2��
		SLDataType* tmp = (SLDataType*)relloc(psl->a, newCapacity * sizeof(SLDataType));//����   ��ʱָ�����
		if (tmp == NULL)
		{
			perro("realloc fail");//���ݴ���
			return;
		}
		//���ݳɹ�
		psl->a = tmp;
		psl->capacity = newCapacity;
	}
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->size = psl->capacity = 0;
}
void SLDestory(SL* psl)
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->size = psl->capacity = 0;
}
void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	////�������  �գ�����
	//if (psl->size == psl->capacity)//����
	//{
	//	int newCapacity = psl->capacity == 0 ?  4:psl->capacity * 2;//����2��
	//	SLDataType* tmp=(SLDataType*)relloc(psl->a, newCapacity * sizeof(SLDataType));//����   ��ʱָ�����
	//	if (tmp == NULL)
	//	{
	//		perro("realloc fail");//���ݴ���
	//		return;
	//	}
	//	//���ݳɹ�
	//	psl->a = tmp;
	//	psl->capacity = newCapacity;
	
	    SLCheckCapacity(psl);
		psl->a[psl->size] = x;
		psl->size++;
	}
}
void SLPushFront(SL* psl, SLDataType x)//ͷ��
{
	assert(psl);
	SLCheckCapacity(psl);//�������
	int end =psl->size - 1;//Ų������ �Ӻ���ǰ
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		end++;
	}
	psl->a[0] = x;
	psl->size++;
}
void SLPopBack(SL* psl)//βɾ
{
	assert(psl);
	//����ļ��  �� ɾ��û��  ͣ��
	if (psl->size == NULL)
	{
		return;
	}
	//�����ļ��
	assert(psl->size > 0);
	psl->size--;
}
void SLPopFront(SL* psl)//ͷɾ
//Ų������  ��ǰ����
{
	assert(psl);
	int begin = 0;
	while (begin < psl->size - 1)//����<=psl->size-2  =βɾ
	{
		psl->a[begin] =psl->a[begin + 1];
		begin++;
	}
	psl->size--;
}
void SLInsert(SL* psl, size_t pos, SLDataType x)
{//posΪ�޷��� ����Ϊ0��ѭ������
	assert(psl);
	assert(pos <= psl->size);//����β��
	//�������
	SLCheckCapacity(psl);
	//Ų������  �����ѭ�� ��Ϊ��������
	size_t end = psl->size;
	while (end >pos)
	{
		psl->a[end -1] = psl->a[end];//��Ų
		end--;
	}
	psl->a[pos] = x;
	psl->size++;
}
void SLErase(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);
	size_t begin = pos;
	while (begin < psl->size - 1)
	{
		psl->a[begin] = psl->a[begin + 1];
		begin++;
	}
	psl->size--;
}
void SLModify(SL* psl, size_t pos, SLDataType x)//�޸�
{
	assert(psl);
	assert(pos < psl->size);
	psl->a[pos] = x;
}