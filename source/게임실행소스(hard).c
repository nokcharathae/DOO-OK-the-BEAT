#include "���.h"


#define width 4            //txt���� �迭 4��
#define height 952         //txt���� ��� ����
#define x 20            //ȭ�� �߽����� ���߱����� ����
#define y 12



int hard_game(void)
{

	
	memset(&user, 0, sizeof(USER));   //����ü �ʱ�ȭ

	FILE *fp;

	char *accuracy[] = { "           ","   GREAT!  ","   GOOD!   ","  PERFECT! ","   MISS!   " };      //��������
	int a_num = 0;
	int temp = 0;
	int num;
	int bx, by = 33;
	int block[height][width];
	int count = 0;
	int clas = 0;
	char *level[] = { "��(��)","��(߾)" };
	char* file = "rank.txt";
	clock_t start;

	fp = fopen("block_hard.txt", "r");   //"block_hard.txt" �о��


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //�޴� ���
	CursorView(0);   //Ŀ������
	system("mode con cols=140 lines=55");   //ȭ�����
	PlaySound(TEXT("resource/è�Ǿ�.wav"), NULL, SND_ASYNC | SND_LOOP);   //�뷡���


	//txt ���Ͽ� �ִ� �迭���� block�迭�� �ִ°�
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
		PlaySound(TEXT("resource/è�Ǿ�.wav"), NULL, SND_ASYNC | SND_LOOP);   //�뷡���
		screen_layout(level[1]);      //��ũ�� ȭ�� ���



		Sleep(3850);   //����


		start = clock();   //�ð����� ����!

		//��� ���
		for (int a = height - 1; a > 18; a--)
		{
			num = a;
			for (int i = 0; i <= 20; i++)
			{
				bx = 22;
				num -= i;

				for (int j = 0; j < width; j++)
				{

					//���� ���� �ð� ���
					gotoxy(80 + x, 25 + y);
					printf("   %.0f ��", (float)(clock() - start / CLOCKS_PER_SEC) / 1000);

					//25�� ���� ������ 150�� ���ϸ� ���� ����/���ӿ���
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
						printf("��������"); //3�̸� ����� ���

					}
					if (block[num][j] == 1)
						printf("              "); //1�̸� ������ ���

					 //Ű���� ���� �������� ���� ������ �������� ��
					if (clas == 0)//�ߺ��Է��� �����ϱ� ���� ����
					{
						if (by == 33)
						{
							if (block[num][j] == 3)
							{
								if (bx == 22)// ����Ű ��
								{

									if (count % 3 == 1)      //����� �������� �ѹ� ������� (Good!)
									{
										if (GetAsyncKeyState(VK_LEFT))//�����Ű�� �Է��Ҷ�
										{
											a_num = 2;         //"   GOOD!   "
											user.score += 3;   //+3��
											clas = 1;         //�Է��̵�
										}

									}

									if (count % 3 == 2) //����� �������� �ι� ������� (Great!)
									{
										if (GetAsyncKeyState(VK_LEFT))
										{
											a_num = 1;//"   GREAT!  "
											user.score += 4;//+4��
											clas = 1;
										}
									}

									if (count % 3 == 0)//����� �������� ���� ������� (Perfect!)
									{
										if (GetAsyncKeyState(VK_LEFT))
										{
											a_num = 3;//"  PERFECT! "
											user.score += 5;//+5��
											clas = 1;//�Է��̵�

										}
										else
											a_num = 4;//����� ������ �� (Miss!)
									}
								}

								if (bx == 37)// ����Ű ��
								{

									if (count % 3 == 1)
									{
										if (GetAsyncKeyState(VK_UP))//�����Ű�� �Է��Ҷ�
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
								if (bx == 52) // ����Ű ��
								{

									if (count % 3 == 1)
									{
										if (GetAsyncKeyState(VK_DOWN)) //�����Ű�� �Է��Ҷ�
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
								if (bx == 67) // ����Ű ��
								{

									if (count % 3 == 1)
									{
										if (GetAsyncKeyState(VK_RIGHT)) //�����Ű�� �Է��Ҷ�
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

							//���鿡 ����Ű �Է��ϸ� Miss! ���
							else if (block[num][j] == 1)  //���鿡�ٰ�
							{
								if (block[num + 1][j] != 3)
								{
									if (bx == 22)
									{
										if (GetAsyncKeyState(VK_LEFT)) //���� �Է��Ҷ�
										{
											a_num = 4; //Miss!

										}


									}
									if (bx == 37)
									{
										if (GetAsyncKeyState(VK_UP))//�����Ű�� �Է��Ҷ�
										{
											a_num = 4;

										}

									}
									if (bx == 52)
									{
										if (GetAsyncKeyState(VK_DOWN)) //�����Ű�� �Է��Ҷ�
										{
											a_num = 4;

										}
									}
									if (bx == 67)
									{
										if (GetAsyncKeyState(VK_RIGHT)) //�����Ű�� �Է��Ҷ�
										{
											a_num = 4;

										}
									}
								}
								else
									a_num = 0; //�Է� ���� ���� ���� �����ϴ� ���� ���� ���

							}
						}
					}
					//3���� ����� �ޱ�����
					if (count % 3 == 0)
					{
						clas = 0;

					}




					//���� ���
					gotoxy(25 + x, 38);
					printf("%s", accuracy[a_num]);
					//���� ���
					gotoxy(107, 24);
					printf("%d", user.score);


					bx += 15;

				}
				by--;
				num = a;
				if (by == 12)
					by = 33;


			}
			Sleep(43); //��ϳ������� �ӵ� ����
		}
		wow();   //block �迭�� �� ��µǸ� ����

		system("cls");
	}


	fp = fopen(file, "wb");

	if (fp == NULL) {
		printf("���� ���� ����!!!\n");
		exit(100);
	}

	else
		fwrite(&user, sizeof(USER), 1, fp);

	fclose(fp);



}
