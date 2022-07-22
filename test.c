#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("************************\n");
	printf("*********1.play*********\n");
	printf("*********0.exit*********\n");
	printf("************************\n");
}
void game()
{
	char ret = 0;
	char board[Row][Col] = { 0 };
	//��ʼ�����̵ĺ���
	InitBoard(board, Row, Col);
	DisplayBoard(board, Row, Col);
	//����
	while (1)
	{
		PlayerMove(board, Row, Col);
		ret = IsWin(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, Row, Col);
		ComputerMove(board, Row, Col);
		ret = IsWin(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, Row, Col);
	}
		if (ret =='*')
		{
			printf("���Ӯ��\n");
		}
		else if (ret == '#')
		{
			printf("����Ӯ��\n");
		}
		else
		{
			printf("ƽ��\n");
		}
		DisplayBoard(board, Row, Col);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default :
				printf("�������\n");
				break;
		}
	} while (input);
	return 0;
}