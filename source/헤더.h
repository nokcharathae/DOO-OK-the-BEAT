#pragma once
#include<stdio.h>
# include <string.h> 
# include <windows.h> //system
# include <stdbool.h> //bool, true, false
# include <conio.h> //_getch(), _kbhit()
#include<mmsystem.h>
#include <time.h>
#pragma comment(lib, "winmm.lib")
# pragma warning (disable: 4996)



# define UP 0
# define DOWN 1
#define LEFT 75
#define RIGHT 77
# define SUBMIT 4 //����(space bar)


typedef struct _user		//����� ����
{

	char name[16];
	int score, rank;



}USER;

void init(void);
void cookies(void);
void titleDraw(void);
int keyControl(void);
int menuDraw(void);
void flash(char* );
extern void gotoxy(int x, int y); //�Է��� xy��ǥ�� Ŀ���� �̵��ϴ� �Լ�
extern void CursorView(char show); //Ŀ�� ����� �Լ�	
int select_level(void);
void easy(void);
void hard(void);

void screen_layout(char *pLevel);								//ȭ�� ���̾ƿ� ����Լ�
void block_line(void);											//�������� ��ϵ� ���������� �� ��� �Լ�

void Wow_print();
int Menu();
void Score();
void gameover_print();
int gameover(void);


void print_current(void);
void bubble_sort(USER pArr[], int count);
void Login();
void Print_name();


USER user;