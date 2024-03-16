#include "헤더.h"


int i = 1; //시작: 파란색

int start(void)
{
	system("mode con cols=140 lines=55 | title 게임제목");
	CursorView(0); //커서 숨기기
	PlaySound(TEXT("resource/리듬게임 화면.wav"), NULL, SND_ASYNC | SND_LOOP);
	while (true) {
		
		titleDraw();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //메뉴 흰색
		 printf("\n\n\t\t\t\t\t\t    > 선택하시려면 SPACE BAR 를 눌러주세요 <");
		int menuCode = menuDraw(); //방향키 입력 받음.

		if (menuCode == 0) {
			/*로딩중...*/
			for (int j = 0; j < 10; j++) {
				titleDraw();
			}
			level();
			//START
		}
		else if (menuCode == 1) {
			printf("\n");
			exit(100); //프로그램 종료
		}
		else if (menuCode == 2) {
			cookies(); //제작자 소개 화면
		}
		system("cls");
	}
	return 0;
}

void init() {
	system("mode con cols=140 lines=55 | title 게임제목");
	CursorView(0); //커서 숨기기
}

//게임제목 출력
void titleDraw(void) {

	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	gotoxy(5, 4);

	printf("\n     ■■■■■■■            ■■■■■■■           ■■■■■■■                         ■■■■■■■       ■■■         ■■■\n");
	printf("     ■■■■■■■■        ■■■■■■■■■       ■■■■■■■■■                     ■■■■■■■■■     ■■■        ■■■\n");
	printf("     ■■■     ■■■      ■■■         ■■■    ■■■         ■■■                  ■■■         ■■■   ■■■       ■■■\n");
	printf("     ■■■     ■■■      ■■■         ■■■    ■■■ ■  ■  ■■■                  ■■■         ■■■   ■■■      ■■■\n");
	printf("     ■■■     ■■■      ■■■  ■ ■  ■■■    ■■■ ■  ■  ■■■                  ■■■■■ ■■■■■   ■■■     ■■■\n");
	printf("     ■■■     ■■■      ■■■         ■■■    ■■■         ■■■    ■■■■■    ■■■         ■■■   ■■■■■■■■\n");
	printf("     ■■■     ■■■      ■■■         ■■■    ■■■    ■   ■■■    ■■■■■    ■■■         ■■■   ■■■■■■■■\n");
	printf("     ■■■     ■■■      ■■■  ■  ■ ■■■    ■■■         ■■■                  ■■■ ■■■■■■■   ■■■     ■■■\n");
	printf("     ■■■     ■■■      ■■■  ■■■ ■■■    ■■■  ■■■ ■■■                  ■■■   ■■  ■■■   ■■■      ■■■\n");
	printf("     ■■■     ■■■      ■■■         ■■■    ■■■         ■■■                  ■■■         ■■■   ■■■       ■■■\n");
	printf("     ■■■■■■■■         ■■■■■■■■■       ■■■■■■■■■                     ■■■■■■■■■    ■■■        ■■■\n");
	printf("     ■■■■■■■             ■■■■■■■           ■■■■■■■                         ■■■■■■■      ■■■         ■■■\n");

	printf("\n\n\n");

	printf("                                                   ■■         ■■\n");
	printf("                                                   ■■         ■■\n");
	printf("                                                   ■■         ■■\n");
	printf("                                              ■■■■■■■    ■■\n");
	printf("                                              ■■■■■■■    ■■  ■■         ■■■■■ \n");
	printf("                                                   ■■         ■■■■■■      ■■     ■■\n");
	printf("                                                   ■■         ■■     ■■    ■■■■■■■\n");
	printf("                                                   ■■         ■■     ■■    ■■\n");
	printf("                                                   ■■         ■■     ■■     ■■     ■■\n");
	printf("                                                   ■■         ■■     ■■      ■■■■■\n");

	printf("\n\n\n");

	printf("                     ■■■■■■               ■■■■■■■                 ■■■■               ■■■■■■■■\n");
	printf("                     ■■■■■■■             ■■■■■■■                ■■■■■              ■■■■■■■■\n");
	printf("                     ■■        ■■           ■■                         ■■    ■■                   ■■\n");
	printf("                     ■■        ■■           ■■                        ■■      ■■                  ■■\n");
	printf("                     ■■       ■■            ■■                        ■■      ■■                  ■■\n");
	printf("                     ■■■■■■■             ■■■■■■■              ■■■■■■■                  ■■\n");
	printf("                     ■■■■■■■             ■■■■■■■              ■■■■■■■                  ■■\n");
	printf("                     ■■       ■■            ■■                        ■■      ■■                  ■■\n");
	printf("                     ■■        ■■           ■■                        ■■      ■■                  ■■\n");
	printf("                     ■■        ■■           ■■                        ■■      ■■                  ■■\n");
	printf("                     ■■■■■■■             ■■■■■■■              ■■      ■■                  ■■\n");
	printf("                     ■■■■■■               ■■■■■■■              ■■      ■■                  ■■\n");
	
	Sleep(250);

	if (i < 15)
		i++;

	else
		i = 1;
}

//제작자 소개 화면
void cookies(void) {
	system("cls"); //화면 모두 지우기
	gotoxy(67, 22);
	printf("[ 제 작 ]\n");
	gotoxy(64, 24);
	printf("2019204035 최은영\n");
	gotoxy(64, 25);
	printf("2019204033 김가영\n");
	gotoxy(64, 26);
	printf("2019204037 오수빈\n");
	gotoxy(64, 27);
	printf("2019204058 이지은\n");
	gotoxy(51, 30);
	printf("스페이스바를 누르면 메인화면으로 이동합니다.\n");

	while (true) {
		if (keyControl() == SUBMIT) { //space bar 누르면
			break; //함수 탈출
		}
	}
}

//메뉴선택 화면 출력
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

//방향키 선택
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
	else if (temp == ' ') { //공백(스페이스바) -> 선택
		return SUBMIT;
	}
}

//x, y 좌표로 커서를 움직이는 함수
void gotoxy(int x, int y) {
	COORD Cur = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


//반짝반짝 효과
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

//화면에 커서를 보이거나 숨기기
void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}