#pragma once
#include <iostream>
using namespace std;


void Menu(int select);

void NewGame(int select);

void settings(char** str, int select);

void print_Settings();

void print_New_Game();

void Print_Main_Menu();

void Print_BattleShip(int type);

void Print_Ship_Visuals();

void Winner_Animation();

void Loser_Animation();

void Delete_All(char** arr, int size);

void About_Game();

void fill_Array_with_Arrays(char** arr, int size);

void fill_Array(char** arr, int size);

void print_Player_Array_1(char** arr, int size, int& row, int& column);

void print_Player_Array_2(char** arr, int size, int& row, int& column, bool rotate);

void print_Player_Array_3(char** arr, int size, int& row, int& column, bool rotate);

void print_Player_Array_4(char** arr, int size, int& row, int& column, bool rotate);

void Locate_Destroyer_1(char** arr_P, int size, int row, int column, int& count_1, char player_ship_sign, char extra_sign);

void Locate_Submarine_2(char** arr_P, int size, int row, int column, bool rotate, int& count_2, char player_ship_sign, char extra_sign);

void Locate_Battleship_3(char** arr_P, int size, int row, int column, bool rotate, int& count_3, char player_ship_sign, char extra_sign);

void Locate_Carrier_4(char** arr_P, int size, int row, int column, bool rotate, int& count_4, char player_ship_sign, char extra_sign);

void Manually_Locate(char** arr_P);

void Auto_Locate(char** arr, bool check);

void print_Game_Boards(char** arr_P, char** arr_bot, int row, int col);

void Change_sunkShip_sign(char** arr, int row, int col);

void Attack(char** arr_P, char** arr_bot, int row, int col);

void Easy_Bot(char** arr_P);

void Hard_Bot(char** arr_P, char** arr_bot);

void Check_Bot_Level(char** arr_P, char** arr_bot);

void change_Signs(char& sign, const char* ptr);

void change_Font(const char* ptr);

void change_Board_Size(const char* ptr);

void Game(char** arr_P, char** arr_bot);







