#include "���.h"


int level(void)
{
	int temp = 0;
	int num = 0;
	int selector = 0;
	char str[56] = { "> �����Ͻ÷��� SPACE BAR �� �����ּ��� <" };
	system("mode con: cols=140 lines=55"); //�ܼ�â ũ�� ����
	PlaySound(TEXT("resource/�������.wav"), NULL, SND_ASYNC | SND_LOOP);		//�뷡 ���
	CursorView(0); //Ŀ�� �����(0)

	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		int x = 10;
		gotoxy(x, 6);		printf("        ������   ���	                                                    ���     ");
		gotoxy(x, 7);		printf("      ����    ��� ���                  ���                                   ");
		gotoxy(x, 8);		printf("    ����           ���  ����      �����         ���   ���     ����    ���     ����     ��� ����");
		gotoxy(x, 9);		printf("    ����           ��������  �������      ���� ����  ������  ���  ���    ���  ����   ���");
		gotoxy(x, 10);		printf("    ����           ����    ��� ���   ����     ��� ���  ��� ���   ��� ��� ���      ��� ���     ���");
		gotoxy(x, 11);		printf("    ����           ����    ��� ���   ����     ��� ���  ��� ���   ��� ��� ���      ��� ���     ��� ");
		gotoxy(x, 12);		printf("      ����    ��� ���      ��� ���   �����   ���       ��� ���  ���  ���   ���   ���  ���     ���");
		gotoxy(x, 13);		printf("        ������   ���     ���   �����    ��� ���       ��� �����    ���     ����     ���     ���");
		gotoxy(x, 14);		printf("                                                                      ���");
		gotoxy(x, 15);		printf("                                                                      ���");
		gotoxy(58, 16);	printf(" ARTIST : ����(PSY)");

		Sleep(250); //���α׷� ���� ���� �Լ� //1000ms = 1s

		gotoxy(50, 23);
		printf("%s", str);

		easy();
		hard();

		int select = select_level(); //����Ű �Է� ����.

		if (select == 0)
		{
			if (selector == 1)
				easy_game();
			else if (selector == 2)
				hard_game();
		}
		//����ȭ�� ���� 

		else if (select == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			easy();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			hard();
			selector = 1;

		}
		else if (select == 2) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			easy();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			hard();
			selector = 2;

		}

	}

	return 0;

}


int select_level(void) {


	while (true) {
		int n = keyControl();
		switch (n) {
		case LEFT:
			return 1;
			break;


		case RIGHT:
			return 2;
			break;


		case SUBMIT:
			return 0;

		}
	}
}



void easy(void)//easy mode
{

	//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //���ڻ� ���� �Լ�
	gotoxy(22, 27); printf("    ����    ����      ���� ��      ��");
	gotoxy(22, 28); printf("  ��      �� �� ����   ��        ��  ��");
	gotoxy(22, 29); printf("  ������   ��   ��    ����     ��");
	gotoxy(22, 30); printf("  ��         ��     ��         ��    ��  ");
	gotoxy(22, 31); printf("    ����    ����  �� ����      ��");

}
void hard(void) //hard mode
{
	gotoxy(70, 27); printf("  ��        ����      ��  ���      ��  ");
	gotoxy(70, 28); printf("  ��       �� ����    �� ��         �� ");
	gotoxy(70, 29); printf("  �� ���    ��   ��    ���      ����");
	gotoxy(70, 30); printf("  ���  ��  ��     ��   ��       ��   ��     ");
	gotoxy(70, 31); printf("  ��    ��   ����  �� ��        ���� ");

}


