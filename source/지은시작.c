#include "���.h"


int i = 1; //����: �Ķ���

int start(void)
{
	system("mode con cols=140 lines=55 | title ��������");
	CursorView(0); //Ŀ�� �����
	PlaySound(TEXT("resource/������� ȭ��.wav"), NULL, SND_ASYNC | SND_LOOP);
	while (true) {
		
		titleDraw();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //�޴� ���
		 printf("\n\n\t\t\t\t\t\t    > �����Ͻ÷��� SPACE BAR �� �����ּ��� <");
		int menuCode = menuDraw(); //����Ű �Է� ����.

		if (menuCode == 0) {
			/*�ε���...*/
			for (int j = 0; j < 10; j++) {
				titleDraw();
			}
			level();
			//START
		}
		else if (menuCode == 1) {
			printf("\n");
			exit(100); //���α׷� ����
		}
		else if (menuCode == 2) {
			cookies(); //������ �Ұ� ȭ��
		}
		system("cls");
	}
	return 0;
}

void init() {
	system("mode con cols=140 lines=55 | title ��������");
	CursorView(0); //Ŀ�� �����
}

//�������� ���
void titleDraw(void) {

	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	gotoxy(5, 4);

	printf("\n     ��������            ��������           ��������                         ��������       ����         ����\n");
	printf("     ���������        ����������       ����������                     ����������     ����        ����\n");
	printf("     ����     ����      ����         ����    ����         ����                  ����         ����   ����       ����\n");
	printf("     ����     ����      ����         ����    ���� ��  ��  ����                  ����         ����   ����      ����\n");
	printf("     ����     ����      ����  �� ��  ����    ���� ��  ��  ����                  ������ ������   ����     ����\n");
	printf("     ����     ����      ����         ����    ����         ����    ������    ����         ����   ���������\n");
	printf("     ����     ����      ����         ����    ����    ��   ����    ������    ����         ����   ���������\n");
	printf("     ����     ����      ����  ��  �� ����    ����         ����                  ���� ��������   ����     ����\n");
	printf("     ����     ����      ����  ���� ����    ����  ���� ����                  ����   ���  ����   ����      ����\n");
	printf("     ����     ����      ����         ����    ����         ����                  ����         ����   ����       ����\n");
	printf("     ���������         ����������       ����������                     ����������    ����        ����\n");
	printf("     ��������             ��������           ��������                         ��������      ����         ����\n");

	printf("\n\n\n");

	printf("                                                   ���         ���\n");
	printf("                                                   ���         ���\n");
	printf("                                                   ���         ���\n");
	printf("                                              ��������    ���\n");
	printf("                                              ��������    ���  ���         ������ \n");
	printf("                                                   ���         �������      ���     ���\n");
	printf("                                                   ���         ���     ���    ��������\n");
	printf("                                                   ���         ���     ���    ���\n");
	printf("                                                   ���         ���     ���     ���     ���\n");
	printf("                                                   ���         ���     ���      ������\n");

	printf("\n\n\n");

	printf("                     �������               ��������                 �����               ���������\n");
	printf("                     ��������             ��������                ������              ���������\n");
	printf("                     ���        ���           ���                         ���    ���                   ���\n");
	printf("                     ���        ���           ���                        ���      ���                  ���\n");
	printf("                     ���       ���            ���                        ���      ���                  ���\n");
	printf("                     ��������             ��������              ��������                  ���\n");
	printf("                     ��������             ��������              ��������                  ���\n");
	printf("                     ���       ���            ���                        ���      ���                  ���\n");
	printf("                     ���        ���           ���                        ���      ���                  ���\n");
	printf("                     ���        ���           ���                        ���      ���                  ���\n");
	printf("                     ��������             ��������              ���      ���                  ���\n");
	printf("                     �������               ��������              ���      ���                  ���\n");
	
	Sleep(250);

	if (i < 15)
		i++;

	else
		i = 1;
}

//������ �Ұ� ȭ��
void cookies(void) {
	system("cls"); //ȭ�� ��� �����
	gotoxy(67, 22);
	printf("[ �� �� ]\n");
	gotoxy(64, 24);
	printf("2019204035 ������\n");
	gotoxy(64, 25);
	printf("2019204033 �谡��\n");
	gotoxy(64, 26);
	printf("2019204037 ������\n");
	gotoxy(64, 27);
	printf("2019204058 ������\n");
	gotoxy(51, 30);
	printf("�����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.\n");

	while (true) {
		if (keyControl() == SUBMIT) { //space bar ������
			break; //�Լ� Ż��
		}
	}
}

//�޴����� ȭ�� ���
int menuDraw(void) {
	int x = 66;
	int y = 49;

	gotoxy(x - 2, y);
	printf("> S T A R T");
	gotoxy(x, y + 1);
	printf("Q U I T");
	gotoxy(x, y + 2);
	printf("C O O K I E S");

	while (true) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 49) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 51) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 49;
		}
		}
	}
}

//����Ű ����
int keyControl(void) {
	char temp = getch();

	if (temp == 72) {
		return UP;
	}
	else if (temp == 80) {
		return DOWN;
	}
	else if (temp == 75) {
		return LEFT;
	}
	else if (temp == 77) {
		return RIGHT;
	}
	else if (temp == ' ') { //����(�����̽���) -> ����
		return SUBMIT;
	}
}

//x, y ��ǥ�� Ŀ���� �����̴� �Լ�
void gotoxy(int x, int y) {
	COORD Cur = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


//��¦��¦ ȿ��
void flash(char* str) {
	char str2[30];

	strcpy(str2, str);

	gotoxy(63, 49);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("%20s", " ");

	Sleep(250);

	gotoxy(63, 49);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("%s", str2);

	Sleep(250);
}

//ȭ�鿡 Ŀ���� ���̰ų� �����
void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}