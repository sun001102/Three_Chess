#include "SList.h"
void TestList1()
{
	SLTNode* plist = NULL;
	SListPushuBack(&plist, 1);
	SListPushuBack(&plist, 2);
	SListPushuBack(&plist, 3);
	SListPushuBack(&plist, 4);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		//�޸�
		pos->data *= 10;
		printf("�ҵ���\n");
	}
	else
	{
		printf("û���ҵ�\n");
	}
	SListPrint(plist);
	pos = SListFind(plist, 2);
	if (pos)
	{
		SListInsert(&plist, pos, 20);
	}
	SListPrint(plist);
	SListDestory(&plist);
}
int main()
{
	TestList1();
	return 0;
}