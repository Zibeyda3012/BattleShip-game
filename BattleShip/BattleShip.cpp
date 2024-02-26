
#include <iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

#define blue "\x1B[34m"
#define red "\x1B[31m"
#define green "\x1B[32m"
#define orange "\x1B[33m"
#define white "\x1B[0m"
#define yellow "\x1B[33m"
#define aqua "\x1B[46m"
#define purple "\x1B[35m"


char side_sign = 249; //gemi etrafinda qoyulan isare
char tilde = 126;   //batmis geminin etrafinda qoyulan isare
int board_size=13;
char hit_sign = 'H';
char miss_sign = 'M';
char pointer = '@';
int font_type = 1;
char sank_ship_sign = 232;
char ship_sign = '#';
int bot_row = -1;
int bot_col = -1;

int bot_level = 1;//default olaraq easy mode


int one = 4;  //birolculu gemi sayi
int two = 3;  //ikiolculu gemi sayi
int three = 2;  //ucolculu gemi sayi
int four = 1;   //dordolculu gemi sayi

int pl_1 = 0;    //playerin gemi sayi
int pl_2 = 0;
int pl_3 = 0;
int pl_4 = 0;

int bot_1 = 0;  //botun gemi sayi
int bot_2 = 0;   
int bot_3 = 0;
int bot_4 = 0;

int winner_score = 0;
int loser_score = 0;

int game_turn = 1;  //oyuncu novbesi

#include"Prototypes.h"
#include"ShipVisuals.h"
#include"AllFunctions.h"
#include"Menu.h"




int main()
{
	srand(time(NULL));
	Print_Main_Menu();


}