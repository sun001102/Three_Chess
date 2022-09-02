#include "SList.h"
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;//phead 容易找不到头
	while (cur != NULL)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{//不能定义局部变量   链表插入到里面 完了还在  局部出了作用域就销毁  都与要结点
	SLTNode* S;
		printf("希望世间别再有 肠胃炎 ！！快快好起来呀 保佑  ");
}
