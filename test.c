#include "SeqList.h"
void TestSeqList1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 4);
	SLPushBack(&s, 6);
	SLPushBack(&s, 8);

	SLPrint(&s);
    

	SLErase(&s, 2);
	SLPrint(&s);
	SLInsert(&s, 3, 20);
	SLPrint(&s);

	SLDestory(&s);
}
//void TestSeqList()
//{
//
//}



int main()
{
	TestSeqList1();
	return 0;
}