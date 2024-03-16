#include "헤더.h"


#define width 4            //txt파일 배열 4개
#define height 952         //txt파일 블록 길이
#define x 20            //화면 중심으로 맞추기위해 만듦
#define y 12



int hard_game(void)
{

	
	memset(&user, 0, sizeof(USER));   //구조체 초기화

	FILE *fp;

	char *accuracy[] = { "           ","   GREAT!  ","   GOOD!   ","  PERFECT! ","   MISS!   " };      //점수판정
	int a_num = 0;
	int temp = 0;
	int num;
	int bx, by = 33;
	int block[height][width];
	int count = 0;
	int clas = 0;
	char *level[] = { "하(下)","상(上)" };
	char* file = "rank.txt";
	clock_t start;

	fp = fopen("block_hard.txt", "r");   //"block_hard.txt" 읽어옴


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //메뉴 흰색
	CursorView(0);   //커서숨김
	system("mode con cols=140 lines=55");   //화면비율
	PlaySound(TEXT("resource/챔피언.wav"), NULL, SND_ASYNC | SND_LOOP);   //노래재생


	//txt 파일에 있는 배열들을 block배열에 넣는거
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			fscanf(fp, "%d", &block[i][j]);

		}
		printf("\n");
	}



	while (1)
	{
		PlaySound(TEXT("resource/챔피언.wav"), NULL, SND_ASYNC | SND_LOOP);   //노래재생
		screen_layout(level[1]);      //스크린 화면 출력



		Sleep(3850);   //간주


		start = clock();   //시간측정 시작!

		//블록 출력
		for (int a = height - 1; a > 18; a--)
		{
			num = a;
			for (int i = 0; i <= 20; i++)
			{
				bx = 22;
				num -= i;

				for (int j = 0; j < width; j++)
				{

					//게임 실행 시간 출력
					gotoxy(80 + x, 25 + y);
					printf("   %.0f 초", (float)(clock() - start / CLOCKS_PER_SEC) / 1000);

					//25초 동안 점수가 150점 이하면 게임 종료/게임오버
					if ((float)(clock() - start / CLOCKS_PER_SEC) > 25000.0 && user.score < 150)

					{
						system("cls");
						gameover();
					}
					


					gotoxy(bx, by);            //(22,13)~(67,33)

					if (block[num][j] == 3)
					{

						if (by == 33)
							count++;
						printf("■■■■■■■"); //3이면 블록을 출력

					}
					if (block[num][j] == 1)
						printf("              "); //1이면 공백을 출력

					 //키보드 값과 판정선에 따라 판정값 내보내는 것
					if (clas == 0)//중복입력을 방지하기 위해 만듦
					{
						if (by == 33)
						{
							if (block[num][j] == 3)
							{
								if (bx == 22)// 방향키 ←
								{

									if (count % 3 == 1)      //블록이 판정선에 한번 닿았을떄 (Good!)
									{
										if (GetAsyncKeyState(VK_LEFT))//←방향키를 입력할때
										{
											a_num = 2;         //"   GOOD!   "
											user.score += 3;   //+3점
											clas = 1;         //입력이됨
										}

									}

									if (count % 3 == 2) //블록이 판정선에 두번 닿았을떄 (Great!)
									{
										if (GetAsyncKeyState(VK_LEFT))
										{
											a_num = 1;//"   GREAT!  "
											user.score += 4;//+4점
											clas = 1;
										}
									}

									if (count % 3 == 0)//블록이 판정선에 세번 닿았을떄 (Perfect!)
									{
										if (GetAsyncKeyState(VK_LEFT))
										{
											a_num = 3;//"  PERFECT! "
											user.score += 5;//+5점
											clas = 1;//입력이됨

										}
										else
											a_num = 4;//블록을 놓쳤을 떄 (Miss!)
									}
								}

								if (bx == 37)// 방향키 ↑
								{

									if (count % 3 == 1)
									{
										if (GetAsyncKeyState(VK_UP))//↑방향키를 입력할때
										{
											a_num = 2;
											user.score += 3;
											clas = 1;
										}
									}

									if (count % 3 == 2)
									{
										if (GetAsyncKeyState(VK_UP))
										{
											a_num = 1;
											user.score += 4;
											clas = 1;
										}
									}

									if (count % 3 == 0)
									{
										if (GetAsyncKeyState(VK_UP))
										{
											a_num = 3;
											user.score += 5;
											clas = 1;

										}
										else
											a_num = 4;
									}

								}
								if (bx == 52) // 방향키 ↓
								{

									if (count % 3 == 1)
									{
										if (GetAsyncKeyState(VK_DOWN)) //↓방향키를 입력할때
										{
											a_num = 2;
											user.score += 3;
											clas = 1;
										}
									}

									if (count % 3 == 2)
									{
										if (GetAsyncKeyState(VK_DOWN))
										{
											a_num = 1;
											user.score += 4;
											clas = 1;
										}
									}

									if (count % 3 == 0)
									{
										if (GetAsyncKeyState(VK_DOWN))
										{
											a_num = 3;
											user.score += 5;
											clas = 1;

										}
										else
											a_num = 4;
									}

								}
								if (bx == 67) // 방향키 →
								{

									if (count % 3 == 1)
									{
										if (GetAsyncKeyState(VK_RIGHT)) //→방향키를 입력할때
										{
											a_num = 2;
											user.score += 3;
											clas = 1;
										}
									}

									if (count % 3 == 2)
									{
										if (GetAsyncKeyState(VK_RIGHT))
										{
											a_num = 1;
											user.score += 4;
											clas = 1;
										}
									}

									if (count % 3 == 0)
									{
										if (GetAsyncKeyState(VK_RIGHT))
										{
											a_num = 3;
											user.score += 5;
											clas = 1;

										}
										else
											a_num = 4;
									}
								}
							}

							//공백에 방향키 입력하면 Miss! 출력
							else if (block[num][j] == 1)  //공백에다가
							{
								if (block[num + 1][j] != 3)
								{
									if (bx == 22)
									{
										if (GetAsyncKeyState(VK_LEFT)) //←을 입력할때
										{
											a_num = 4; //Miss!

										}


									}
									if (bx == 37)
									{
										if (GetAsyncKeyState(VK_UP))//↑방향키를 입력할때
										{
											a_num = 4;

										}

									}
									if (bx == 52)
									{
										if (GetAsyncKeyState(VK_DOWN)) //↓방향키를 입력할때
										{
											a_num = 4;

										}
									}
									if (bx == 67)
									{
										if (GetAsyncKeyState(VK_RIGHT)) //→방향키를 입력할때
										{
											a_num = 4;

										}
									}
								}
								else
									a_num = 0; //입력 받지 않을 때는 판정하는 곳에 공백 출력

							}
						}
					}
					//3개의 블록을 받기위함
					if (count % 3 == 0)
					{
						clas = 0;

					}




					//판정 출력
					gotoxy(25 + x, 38);
					printf("%s", accuracy[a_num]);
					//점수 출력
					gotoxy(107, 24);
					printf("%d", user.score);


					bx += 15;

				}
				by--;
				num = a;
				if (by == 12)
					by = 33;


			}
			Sleep(43); //블록내려오는 속도 조절
		}
		wow();   //block 배열이 다 출력되면 멈춤

		system("cls");
	}


	fp = fopen(file, "wb");

	if (fp == NULL) {
		printf("파일 개방 실패!!!\n");
		exit(100);
	}

	else
		fwrite(&user, sizeof(USER), 1, fp);

	fclose(fp);



}
