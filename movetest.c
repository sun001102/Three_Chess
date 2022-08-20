#include "movecontact.h"
void menu()
{
	printf("********  1. add       2. del   ********\n");
	printf("********  3. search    4. modify********\n");
	printf("********  5. show      6. sort  ********\n");
	printf("********  0. exit               ********\n");
	printf("****************************************\n");
}
enum Option
{
	EXIT,
    ADD,
    DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
};
int main()
{
	int input = 0;
	Contact con;//ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	do//�˵�
	{
		menu();
		printf("��ѡ��->\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}