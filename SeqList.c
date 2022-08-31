#include "SeqList.h"
int  SLFind(SL* psl, SLDataType x)//查找
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
//检查容量  空？满？
	if (psl->size == psl->capacity)//满了
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;//扩容2倍
		SLDataType* tmp = (SLDataType*)relloc(psl->a, newCapacity * sizeof(SLDataType));//扩容   临时指针接收
		if (tmp == NULL)
		{
			perro("realloc fail");//扩容错误
			return;
		}
		//扩容成功
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
	////检查容量  空？满？
	//if (psl->size == psl->capacity)//满了
	//{
	//	int newCapacity = psl->capacity == 0 ?  4:psl->capacity * 2;//扩容2倍
	//	SLDataType* tmp=(SLDataType*)relloc(psl->a, newCapacity * sizeof(SLDataType));//扩容   临时指针接收
	//	if (tmp == NULL)
	//	{
	//		perro("realloc fail");//扩容错误
	//		return;
	//	}
	//	//扩容成功
	//	psl->a = tmp;
	//	psl->capacity = newCapacity;
	
	    SLCheckCapacity(psl);
		psl->a[psl->size] = x;
		psl->size++;
	}
}
void SLPushFront(SL* psl, SLDataType x)//头插
{
	assert(psl);
	SLCheckCapacity(psl);//检查容量
	int end =psl->size - 1;//挪动数据 从后往前
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		end++;
	}
	psl->a[0] = x;
	psl->size++;
}
void SLPopBack(SL* psl)//尾删
{
	assert(psl);
	//温柔的检查  （ 删到没了  停）
	if (psl->size == NULL)
	{
		return;
	}
	//暴力的检查
	assert(psl->size > 0);
	psl->size--;
}
void SLPopFront(SL* psl)//头删
//挪动数据  从前往后
{
	assert(psl);
	int begin = 0;
	while (begin < psl->size - 1)//或者<=psl->size-2  =尾删
	{
		psl->a[begin] =psl->a[begin + 1];
		begin++;
	}
	psl->size--;
}
void SLInsert(SL* psl, size_t pos, SLDataType x)
{//pos为无符号 存在为0死循环问题
	assert(psl);
	assert(pos <= psl->size);//等于尾插
	//检查容量
	SLCheckCapacity(psl);
	//挪动数据  解决死循环 不为负不提升
	size_t end = psl->size;
	while (end >pos)
	{
		psl->a[end -1] = psl->a[end];//后挪
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
void SLModify(SL* psl, size_t pos, SLDataType x)//修改
{
	assert(psl);
	assert(pos < psl->size);
	psl->a[pos] = x;
}