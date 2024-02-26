#pragma once

#include <iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

void Delete_All(char** arr, int size)
{
	for (size_t i = 0; i < size; i++)
		delete[] arr[i];

	delete[] arr;

}

void About_Game()
{
	system("cls");
	char* aboutTitle = new char[] {" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ About Battleship Game ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "};
	char* aboutText = new char[] { R"(
Welcome to the Battleship game, a classic naval strategy game where your tactical skills are put to the test. 
Your mission is to sink your opponent's fleet before they sink yours. Here's what the signs mean in the game:)"
		};
	char* str0 = new char[] {" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Signs ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "};
	char* pointerToHit = new char[] {" : Pointer to Hit - Marks a coordinate to hit an enemy ship." };
	char* shipHit = new char[] {" : Ship Hit - Indicates a part of an enemy ship that has been hit."};
	char* shipSunk = new char[] {" : Ship Sank - Shows a completely sunken enemy ship."};
	char* missedHits = new char[] {" : Missed Hits - Marks coordinates where your shots missed."};
	char* collaps = new char[] {" If ships collapse colour changes "};
	char* yourShip = new char[] { " : Your Ship - Represents the location of your own fleet."};
	char* str1 = new char[] {" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Settings ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "};
	char* Size = new char[] {"* You can change the \"Board size\" within the 10-20 range, with the default set at 10"};
	char* bot = new char[] {"* The default bot level is \"Easy\"; representing the game's initial difficulty setting."};
	char* instructions = new char[] {"Use your strategic wit to eliminate your opponent's fleet \nwhile protecting your own. Fire your shots wisely, and may the best admiral win!"};
	char* sizeNote = new char[] {" Battleship - Version 1.0"};


	char** arr = new char* [14] {aboutTitle, aboutText, str0, pointerToHit, shipHit, shipSunk, missedHits, yourShip, collaps,str1, Size, bot, instructions, sizeNote};


	for (size_t i = 0; i < 14; i++)
	{
		if (i == 3)
			cout << pointer;
		else if (i == 4)
			cout << hit_sign;

		else if (i == 5)
			cout << sank_ship_sign;

		else if (i == 6)
			cout << miss_sign;

		else if (i == 7)
			cout << ship_sign;


		for (size_t j = 0; arr[i][j] != '\0'; j++)
		{
			if (_kbhit())
			{
				cin.ignore();
				system("cls");

				for (size_t k = 0; k <= i; k++)
				{
					if (k == 3)
						cout << pointer;
					else if ( k== 4)
						cout << hit_sign;

					else if (k == 5)
						cout << sank_ship_sign;

					else if (k == 6)
						cout << miss_sign;

					else if (k == 7)
						cout << ship_sign;

					cout << arr[k] << endl;

				}

				break;

			}
			cout << arr[i][j];
			Sleep(40);
		}

		cout << endl;
	}


}


void fill_Array_with_Arrays(char** arr, int size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = new char[size] {};
}


void fill_Array(char** arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (j == 0)
			{
				for (size_t k = 1; k <= size - 1; k++)
				{
					if (k == 1 || k == size - 1)
						arr[k][j] = ' ';
					else
						arr[k][j] = 65 + k - 2;
				}
			}

			else if (i == 0)
			{
				if (j == 0 || j == 1 || j == size - 1)
					arr[i][j] = ' ';
				else
					arr[i][j] = 65 + j - 2;
			}
			else if (j == 0 && (i == 1 || i == size - 1))
				arr[i][j] = ' ';

			else if (i == 1 && j == 1)
				arr[i][j] = 201;

			else if (i == 1 && j == size - 1)
				arr[i][j] = 187;

			else if (i == size - 1 && j == 1)
				arr[i][j] = 200;

			else if (i == size - 1 && j == size - 1)
				arr[i][j] = 188;

			else if (i == 1 || i == size - 1)
				arr[i][j] = 205;

			else if (j == 1 || j == size - 1)
				arr[i][j] = 186;

			else
				arr[i][j] = ' ';

		}
	}
}


void print_Player_Array_1(char** arr, int size, int& row, int& column)
{

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{

			(column >= size - 1) ? column-- : column += 0;

			if (i == row && j == column)
			{
				if (arr[i][column] == ' ')
					cout << ship_sign << " ";

				else
					cout << red << ship_sign << white << " ";

			}

			else if ((i == 1 || i == size - 1) && j < size - 1)
				cout << arr[i][j] << " ";

			else if (i == 0 && j == 0)
				cout << " " << " ";

			else
				cout << arr[i][j] << " ";

		}

		cout << endl;
	}
}


void print_Player_Array_2(char** arr, int size, int& row, int& column, bool rotate)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (rotate == 0) //horizontal
			{
				(column + 1 >= size - 1) ? column-- : column += 0;


				if (i == row && (j == column || j == column + 1))
				{
					if (arr[i][column] == ' ' && arr[i][column + 1] == ' ')
						cout << ship_sign << " ";

					else
						cout << red << ship_sign << white << " ";

				}

				else if (i == 0 && j == 0)
					cout << " " << " ";
				else
					cout << arr[i][j] << " ";
			}

			else //vertical
			{
				(row + 1 >= size - 1) ? row-- : 0;

				if (j == column && (i == row || i == row + 1))
				{
					if (arr[row][j] == ' ' && arr[row + 1][j] == ' ')
						cout << ship_sign << " ";
					else
						cout << red << ship_sign << white << " ";
				}
				else if ((i == 1 || i == size - 1) && j < size - 1)
					cout << arr[i][j] << " ";

				else if (i == 0 && j == 0)
					cout << " " << " ";
				else
					cout << arr[i][j] << " ";
			}

		}
		cout << endl;
	}

}


void print_Player_Array_3(char** arr, int size, int& row, int& column, bool rotate)
{

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (rotate == 0) //horizontal
			{
				(column + 2 >= size - 1) ? column-- : column += 0;


				if (i == row && (j == column || j == column + 1 || j == column + 2))
				{
					if (arr[i][column] == ' ' && arr[i][column + 1] == ' ' && arr[i][column + 2] == ' ')
						cout << ship_sign << " ";

					else
						cout << red << ship_sign << white << " ";

				}

				else if (i == 0 && j == 0)
					cout << " " << " ";
				else
					cout << arr[i][j] << " ";
			}

			else  //vertical
			{
				(row + 2 >= size - 1) ? row-- : 0;


				if (j == column && (i == row || i == row + 1 || i == row + 2))
				{
					if (arr[row][j] == ' ' && arr[row + 1][j] == ' ' && arr[row + 2][j] == ' ')
						cout << ship_sign << " ";
					else
						cout << red << ship_sign << white << " ";
				}

				else if ((i == 1 || i == size - 1) && j < size - 1)
					cout << arr[i][j] << " ";

				else if (i == 0 && j == 0)
					cout << " " << " ";
				else
					cout << arr[i][j] << " ";
			}

		}
		cout << endl;
	}

}


void print_Player_Array_4(char** arr, int size, int& row, int& column, bool rotate)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (rotate == 0) //horizontal
			{
				(column + 3 >= size - 1) ? column-- : column += 0;


				if (i == row && (j == column || j == column + 1 || j == column + 2 || j == column + 3))
				{
					if (arr[i][column] == ' ' && arr[i][column + 1] == ' ' && arr[i][column + 2] == ' ' && arr[i][column + 3] == ' ')
						cout << ship_sign << " ";

					else
						cout << red << ship_sign << white << " ";

				}

				else if (i == 0 && j == 0)
					cout << " " << " ";

				else
					cout << arr[i][j] << " ";
			}

			else  //vertical
			{
				(row + 3 >= size - 1) ? row-- : 0;


				if (j == column && (i == row || i == row + 1 || i == row + 2 || i == row + 3))
				{
					if (arr[row][j] == ' ' && arr[row + 1][j] == ' ' && arr[row + 2][j] == ' ' && arr[row + 3][j] == ' ')
						cout << ship_sign << " ";
					else
						cout << red << ship_sign << white << " ";
				}

				else if ((i == 1 || i == size - 1) && j < size - 1)
					cout << arr[i][j] << " ";

				else if (i == 0 && j == 0)
					cout << " " << " ";
				else
					cout << arr[i][j] << " ";
			}

		}
		cout << endl;
	}
}


void Locate_Destroyer_1(char** arr_P, int size, int row, int column, int& count_1, char player_ship_sign, char extra_sign)
{
	while (true)
	{
		if (arr_P[row][column] == ' ')
		{
			arr_P[row][column] = player_ship_sign;
			count_1++;


			if (column > 2)
			{
				arr_P[row][column - 1] = extra_sign;

				if (row > 2)
				{
					arr_P[row - 1][column] = extra_sign;
					arr_P[row - 1][column - 1] = extra_sign;
				}

				if (row < size - 2)
				{
					arr_P[row + 1][column] = extra_sign;
					arr_P[row + 1][column - 1] = extra_sign;
				}
			}

			if (column < size - 2)
			{
				arr_P[row][column + 1] = extra_sign;

				if (row > 2)
				{
					arr_P[row - 1][column + 1] = extra_sign;
					arr_P[row - 1][column] = extra_sign;
				}

				if (row < size - 2)
				{
					arr_P[row + 1][column + 1] = extra_sign;
					arr_P[row + 1][column] = extra_sign;

				}

			}

		}
		break;
	}

}


void Locate_Submarine_2(char** arr_P, int size, int row, int column, bool rotate, int& count_2, char player_ship_sign, char extra_sign)
{
	while (true)
	{
		if (rotate == 1)   //vertical
		{
			if (arr_P[row][column] == ' ' && arr_P[row + 1][column] == ' ')
			{
				arr_P[row][column] = player_ship_sign;  //#
				arr_P[row + 1][column] = player_ship_sign;
				count_2++;


				if (column > 2)
				{
					arr_P[row][column - 1] = extra_sign;
					arr_P[row + 1][column - 1] = extra_sign;

					if (row > 2)
					{
						arr_P[row - 1][column] = extra_sign;
						arr_P[row - 1][column - 1] = extra_sign;
					}

					if (row + 1 < size - 2)
					{
						arr_P[row + 2][column] = extra_sign;
						arr_P[row + 2][column - 1] = extra_sign;
					}
				}

				if (column < size - 2)
				{
					arr_P[row][column + 1] = extra_sign;
					arr_P[row + 1][column + 1] = extra_sign;

					if (row > 2)
					{
						arr_P[row - 1][column + 1] = extra_sign;
						arr_P[row - 1][column] = extra_sign;
					}

					if (row + 1 < size - 2)
					{
						arr_P[row + 2][column + 1] = extra_sign;
						arr_P[row + 2][column] = extra_sign;

					}

				}

			}
			break;
		}
		else   //horizontal
		{

			if (arr_P[row][column] == ' ' && arr_P[row][column + 1] == ' ')
			{
				arr_P[row][column] = player_ship_sign;  //#
				arr_P[row][column + 1] = player_ship_sign;
				count_2++;

				if (row > 2)
				{
					arr_P[row - 1][column] = extra_sign;
					arr_P[row - 1][column + 1] = extra_sign;

					if (column > 2)
					{
						arr_P[row][column - 1] = extra_sign;
						arr_P[row - 1][column - 1] = extra_sign;
					}

					if (column + 1 < size - 2)
					{
						arr_P[row - 1][column + 2] = extra_sign;
						arr_P[row][column + 2] = extra_sign;
					}

				}

				if (row < size - 2)
				{
					arr_P[row + 1][column] = extra_sign;
					arr_P[row + 1][column + 1] = extra_sign;

					if (column > 2)
					{
						arr_P[row][column - 1] = extra_sign;
						arr_P[row + 1][column - 1] = extra_sign;
					}

					if (column + 1 < size - 2)
					{
						arr_P[row][column + 2] = extra_sign;
						arr_P[row + 1][column + 2] = extra_sign;
					}
				}


			}
			break;
		}

	}
}


void Locate_Battleship_3(char** arr_P, int size, int row, int column, bool rotate, int& count_3, char player_ship_sign, char extra_sign)
{
	while (true)
	{
		if (rotate == 1)   //vertical
		{
			if (arr_P[row][column] == ' ' && arr_P[row + 1][column] == ' ' && arr_P[row + 2][column] == ' ')
			{
				arr_P[row][column] = player_ship_sign;  //#
				arr_P[row + 1][column] = player_ship_sign;
				arr_P[row + 2][column] = player_ship_sign;
				count_3++;


				if (column > 2)
				{
					arr_P[row][column - 1] = extra_sign;
					arr_P[row + 1][column - 1] = extra_sign;
					arr_P[row + 2][column - 1] = extra_sign;

					if (row > 2)
					{
						arr_P[row - 1][column] = extra_sign;
						arr_P[row - 1][column - 1] = extra_sign;
					}

					if (row + 2 < size - 2)
					{
						arr_P[row + 3][column] = extra_sign;
						arr_P[row + 3][column - 1] = extra_sign;
					}
				}

				if (column < size - 2)
				{
					arr_P[row][column + 1] = extra_sign;
					arr_P[row + 1][column + 1] = extra_sign;
					arr_P[row + 2][column + 1] = extra_sign;

					if (row > 2)
					{
						arr_P[row - 1][column + 1] = extra_sign;
						arr_P[row - 1][column] = extra_sign;
					}

					if (row + 2 < size - 2)
					{
						arr_P[row + 3][column + 1] = extra_sign;
						arr_P[row + 3][column] = extra_sign;

					}

				}

			}
			break;
		}
		else   //horizontal
		{

			if (arr_P[row][column] == ' ' && arr_P[row][column + 1] == ' ' && arr_P[row][column + 2] == ' ')
			{
				arr_P[row][column] = player_ship_sign;  //#
				arr_P[row][column + 1] = player_ship_sign;
				arr_P[row][column + 2] = player_ship_sign;
				count_3++;

				if (row > 2)
				{
					arr_P[row - 1][column] = extra_sign;
					arr_P[row - 1][column + 1] = extra_sign;
					arr_P[row - 1][column + 2] = extra_sign;

					if (column > 2)
					{
						arr_P[row][column - 1] = extra_sign;
						arr_P[row - 1][column - 1] = extra_sign;
					}

					if (column + 2 < size - 2)
					{
						arr_P[row - 1][column + 3] = extra_sign;
						arr_P[row][column + 3] = extra_sign;
					}

				}

				if (row < size - 2)
				{
					arr_P[row + 1][column] = extra_sign;
					arr_P[row + 1][column + 1] = extra_sign;
					arr_P[row + 1][column + 2] = extra_sign;

					if (column > 2)
					{
						arr_P[row][column - 1] = extra_sign;
						arr_P[row + 1][column - 1] = extra_sign;
					}

					if (column + 2 < size - 2)
					{
						arr_P[row][column + 3] = extra_sign;
						arr_P[row + 1][column + 3] = extra_sign;
					}
				}


			}
			break;
		}

	}

}


void Locate_Carrier_4(char** arr_P, int size, int row, int column, bool rotate, int& count_4, char player_ship_sign, char extra_sign)
{


	while (true)
	{
		if (rotate == 1)   //vertical
		{
			if (arr_P[row][column] == ' ' && arr_P[row + 1][column] == ' ' && arr_P[row + 2][column] == ' ' && arr_P[row + 3][column] == ' ')
			{
				arr_P[row][column] = player_ship_sign;  //#
				arr_P[row + 1][column] = player_ship_sign;
				arr_P[row + 2][column] = player_ship_sign;
				arr_P[row + 3][column] = player_ship_sign;
				count_4++;


				if (column > 2)
				{
					arr_P[row][column - 1] = extra_sign;
					arr_P[row + 1][column - 1] = extra_sign;
					arr_P[row + 2][column - 1] = extra_sign;
					arr_P[row + 3][column - 1] = extra_sign;

					if (row > 2)
					{
						arr_P[row - 1][column] = extra_sign;
						arr_P[row - 1][column - 1] = extra_sign;
					}

					if (row + 3 < size - 2)
					{
						arr_P[row + 4][column] = extra_sign;
						arr_P[row + 4][column - 1] = extra_sign;
					}
				}

				if (column < size - 2)
				{
					arr_P[row][column + 1] = extra_sign;
					arr_P[row + 1][column + 1] = extra_sign;
					arr_P[row + 2][column + 1] = extra_sign;
					arr_P[row + 3][column + 1] = extra_sign;

					if (row > 2)
					{
						arr_P[row - 1][column + 1] = extra_sign;
						arr_P[row - 1][column] = extra_sign;
					}

					if (row + 3 < size - 2)
					{
						arr_P[row + 4][column + 1] = extra_sign;
						arr_P[row + 4][column] = extra_sign;

					}

				}

			}
			break;
		}
		else   //horizontal
		{

			if (arr_P[row][column] == ' ' && arr_P[row][column + 1] == ' ' && arr_P[row][column + 2] == ' ' && arr_P[row][column + 3] == ' ')
			{
				arr_P[row][column] = player_ship_sign;  //#
				arr_P[row][column + 1] = player_ship_sign;
				arr_P[row][column + 2] = player_ship_sign;
				arr_P[row][column + 3] = player_ship_sign;
				count_4++;

				if (row > 2)
				{
					arr_P[row - 1][column] = extra_sign;
					arr_P[row - 1][column + 1] = extra_sign;
					arr_P[row - 1][column + 2] = extra_sign;
					arr_P[row - 1][column + 3] = extra_sign;

					if (column > 2)
					{
						arr_P[row][column - 1] = extra_sign;
						arr_P[row - 1][column - 1] = extra_sign;
					}

					if (column + 3 < size - 2)
					{
						arr_P[row - 1][column + 4] = extra_sign;
						arr_P[row][column + 4] = extra_sign;
					}

				}

				if (row < size - 2)
				{
					arr_P[row + 1][column] = extra_sign;
					arr_P[row + 1][column + 1] = extra_sign;
					arr_P[row + 1][column + 2] = extra_sign;
					arr_P[row + 1][column + 3] = extra_sign;

					if (column > 2)
					{
						arr_P[row][column - 1] = extra_sign;
						arr_P[row + 1][column - 1] = extra_sign;
					}

					if (column + 3 < size - 2)
					{
						arr_P[row][column + 4] = extra_sign;
						arr_P[row + 1][column + 4] = extra_sign;
					}
				}


			}
			break;
		}

	}


}

void Manually_Locate(char** arr_P)
{
	//default size
	int size = board_size;
	int row = size / 2;
	int column = size / 2;

	bool rotate = 0;

	print_Player_Array_4(arr_P, size, row, column, rotate);


	while (true)
	{
		int select = _getch();

		if (select == 224) //arrow
		{
			select = _getch();

			if (select == 72) //up arrow
			{
				if (row > 2)
				{
					row--;
				}

			}

			else if (select == 80) //down arrow
			{
				if (row < size - 2)
				{
					row++;
				}
			}

			else if (select == 75) //left arrow
			{

				if (column > 2)
				{
					column--;
				}

			}

			else if (select == 77) //right arrow
			{
				if (column < size - 2)
				{
					column++;
				}


			}
		}

		else if (select == 119) //w
		{
			if (row > 2)
			{
				row--;
			}
		}

		else if (select == 115) //s
		{
			if (row < size - 2)
			{
				row++;
			}
		}

		else if (select == 97) //a
		{
			if (column > 2)
			{
				column--;
			}

		}

		else if (select == 100) //d
		{
			if (column < size - 2)
			{
				column++;
			}
		}

		else if (select == 13) //enter
		{
			if (pl_4 != 1)
				Locate_Carrier_4(arr_P, size, row, column, rotate, pl_4, ship_sign, side_sign);
			else if (pl_3 != 2)
			{
				Locate_Battleship_3(arr_P, size, row, column, rotate, pl_3, ship_sign, side_sign);
			}
			else if (pl_2 != 3)
			{
				Locate_Submarine_2(arr_P, size, row, column, rotate, pl_2, ship_sign, side_sign);
			}
			else if (pl_1 != 4)
			{
				Locate_Destroyer_1(arr_P, size, row, column, pl_1, ship_sign, side_sign);
			}
			else
				break;


		}

		else if (select == 114 || select == 82)  //rotate
			(rotate == 0) ? rotate = 1 : rotate = 0;




		system("cls");
		if (pl_4 != 1)
			print_Player_Array_4(arr_P, size, row, column, rotate);

		else if (pl_3 != 2)
			print_Player_Array_3(arr_P, size, row, column, rotate);

		else if (pl_2 != 3)
			print_Player_Array_2(arr_P, size, row, column, rotate);

		else if (pl_1 != 4)
			print_Player_Array_1(arr_P, size, row, column);
		else
			break;

	}
}


void Auto_Locate(char** arr, bool check)  //hem player array hem de bot array qe1bul ede biler
{
	int row, column;
	bool rotate = 0;

	while (true)
	{
		row = 2 + rand() % (board_size - 3);
		column = 2 + rand() % (board_size - 3);

		rotate = 0 + rand() % (2);

		if (check) //bot olan hal
		{
			if (bot_4 != 1)
				Locate_Carrier_4(arr, board_size, row, column, rotate, bot_4, ship_sign, side_sign);
			else if (bot_3 != 2)
			{
				Locate_Battleship_3(arr, board_size, row, column, rotate, bot_3, ship_sign, side_sign);
			}
			else if (bot_2 != 3)
			{
				Locate_Submarine_2(arr, board_size, row, column, rotate, bot_2, ship_sign, side_sign);
			}
			else if (bot_1 != 4)
			{
				Locate_Destroyer_1(arr, board_size, row, column, bot_1, ship_sign, side_sign);
			}
			else
				break;

		}

		else
		{
			if (pl_4 != 1)
				Locate_Carrier_4(arr, board_size, row, column, rotate, pl_4, ship_sign, side_sign);
			else if (pl_3 != 2)
			{
				Locate_Battleship_3(arr, board_size, row, column, rotate, pl_3, ship_sign, side_sign);
			}
			else if (pl_2 != 3)
			{
				Locate_Submarine_2(arr, board_size, row, column, rotate, pl_2, ship_sign, side_sign);
			}
			else if (pl_1 != 4)
			{
				Locate_Destroyer_1(arr, board_size, row, column, pl_1, ship_sign, side_sign);
			}

			else
				break;
		}

	}








}

void print_Game_Boards(char** arr_P, char** arr_bot, int row, int col)
{

	cout << endl << endl;

	cout << "\tPlayer Board";
	for (size_t i = 0; i < board_size; i++)
		cout << "  ";

	cout << "\t Bot Board" << endl << endl << endl;;

	for (size_t i = 0; i < board_size; i++)
	{
		for (size_t j = 0; j < board_size; j++)
		{

			if (i == 0 && j == 0)
				cout << " " << " ";

			else if ((i == 1 || i == board_size - 1) && j < board_size - 1)
				cout << arr_P[i][j] << " ";

			else if (i == bot_row && j == bot_col)
				cout << red << arr_P[i][j] << white << " ";

			else
				if (arr_P[i][j] == side_sign)
					cout << " " << " ";
				else
				{
					if (arr_P[i][j] == miss_sign && i != 0 && j != 0)
						cout << yellow << arr_P[i][j] << white << " ";


					else if (arr_P[i][j] == hit_sign && i != 0 && j != 0)
						cout << blue << arr_P[i][j] << white << " ";

					else
						cout << arr_P[i][j] << " ";


				}

		}

		for (size_t k = 0; k < board_size; k++)
			cout << " ";

		for (size_t z = 0; z < board_size; z++)
		{
			if (i == 0 && z == 0)
				cout << " " << " ";

			else if ((i == 1 || i == board_size - 1) && z < board_size - 1)
				cout << arr_bot[i][z] << " ";

			else if (i == row && z == col)  //pointer 
			{
				if (arr_bot[i][z] == miss_sign || arr_bot[i][z] == hit_sign || arr_bot[i][z] == tilde)
					cout << orange << arr_bot[i][z] << white << " ";

				else
					cout << pointer << " ";
			}

			else
				if (arr_bot[i][z] == side_sign || arr_bot[i][z] == ship_sign)
					cout << " " << " ";

				else if (arr_bot[i][z] == hit_sign && i != 0 && z != 0)
					cout << green << arr_bot[i][z] << white << " ";

				else if (arr_bot[i][z] == miss_sign && i != 0 && z != 0)
					cout << purple << arr_bot[i][z] << white << " ";

				else if (arr_bot[i][z] == sank_ship_sign)
					cout << aqua << arr_bot[i][z] << white << " ";

				else
					cout << arr_bot[i][z] << " ";
		}

		cout << endl;

	}

	cout << yellow << "Player's Ship Count" << white;
	for (size_t i = 0; i < board_size; i++)
		cout << " ";
	cout << yellow << "\tBot's Ship Count " << white << endl << endl;

	cout << "Destroyer  => " << pl_1;

	for (size_t i = 0; i < board_size; i++)
		cout << " ";

	cout << "\t\tDestroyer  => " << bot_1 << endl;

	cout << "Submarine  => " << pl_2;

	for (size_t i = 0; i < board_size; i++)
		cout << " ";

	cout << "\t\tSubmarine  => " << bot_2 << endl;

	cout << "BattleShip => " << pl_3;

	for (size_t i = 0; i < board_size; i++)
		cout << " ";

	cout << "\t\tBattleShip => " << bot_3 << endl;

	cout << "Carrier    => " << pl_4;

	for (size_t i = 0; i < board_size; i++)
		cout << " ";

	cout << "\t\tCarrier    => " << bot_4 << endl;


}

void Change_sunkShip_sign(char** arr, int row, int col)
{
	while (true)
	{
		if (arr[row][col - 1] == ship_sign || arr[row][col - 1] == hit_sign)  //horizontal
			col--;

		else if (arr[row - 1][col] == ship_sign || arr[row - 1][col] == hit_sign)
			row--;

		else
			break;

	}

	bool rotate = 0; //default value

	if (arr[row][col + 1] == hit_sign || arr[row][col + 1] == ship_sign)
		rotate = 0;  //horizontal
	else if (arr[row + 1][col] == hit_sign || arr[row + 1][col] == ship_sign)
		rotate = 1;   //vertical




	if (rotate == 0)
	{
		if (arr[row][col] == hit_sign && arr[row][col + 1] == hit_sign && arr[row][col + 2] == hit_sign && arr[row][col + 3] == hit_sign)
		{
			arr[row][col] = ' ';
			arr[row][col + 1] = ' ';
			arr[row][col + 2] = ' ';
			arr[row][col + 3] = ' ';

			if (game_turn % 2 != 0) //player
			{
				Locate_Carrier_4(arr, board_size, row, col, rotate, bot_4, sank_ship_sign, tilde);
				bot_4 -= 2;
			}

			else
			{
				Locate_Carrier_4(arr, board_size, row, col, rotate, pl_4, sank_ship_sign, tilde);
				pl_4 -= 2;
			}


		}

		else if (arr[row][col] == hit_sign && arr[row][col + 1] == hit_sign && arr[row][col + 2] == hit_sign &&
			(arr[row][col + 3] == char(186) || arr[row][col + 3] == miss_sign || arr[row][col + 3] == tilde || arr[row][col + 3] == side_sign || arr[row][col + 3] == ' '))
		{
			arr[row][col] = ' ';
			arr[row][col + 1] = ' ';
			arr[row][col + 2] = ' ';

			if (game_turn % 2 != 0) //player
			{
				Locate_Battleship_3(arr, board_size, row, col, rotate, bot_3, sank_ship_sign, tilde);
				bot_3 -= 2;
			}

			else
			{
				Locate_Battleship_3(arr, board_size, row, col, rotate, pl_3, sank_ship_sign, tilde);
				pl_3 -= 2;
			}


		}


		else if (arr[row][col] == hit_sign && arr[row][col + 1] == hit_sign &&
			(arr[row][col + 2] == char(186) || arr[row][col + 2] == miss_sign || arr[row][col + 2] == tilde || arr[row][col + 2] == side_sign || arr[row][col + 2] == ' '))
		{
			arr[row][col] = ' ';
			arr[row][col + 1] = ' ';

			if (game_turn % 2 != 0) //player
			{
				Locate_Submarine_2(arr, board_size, row, col, rotate, bot_2, sank_ship_sign, tilde);
				bot_2 -= 2;
			}

			else
			{
				Locate_Submarine_2(arr, board_size, row, col, rotate, pl_2, sank_ship_sign, tilde);
				pl_2 -= 2;
			}

		}

		if ((arr[row][col + 1] == miss_sign || arr[row][col + 1] == char(186) || arr[row][col + 1] == tilde || arr[row][col + 1] == ' ' || arr[row][col + 1] == side_sign)
			&& (arr[row + 1][col] == miss_sign || arr[row + 1][col] == char(205) || arr[row + 1][col] == tilde || arr[row + 1][col] == ' ' || arr[row + 1][col] == side_sign))
		{
			arr[row][col] = ' ';
			if (game_turn % 2 != 0)
			{
				Locate_Destroyer_1(arr, board_size, row, col, bot_1, sank_ship_sign, tilde);
				bot_1 -= 2;
			}

			else
			{
				Locate_Destroyer_1(arr, board_size, row, col, pl_1, sank_ship_sign, tilde);
				pl_1 -= 2;
			}


		}


	}

	else if (rotate == 1)
	{
		if (arr[row][col] == hit_sign && arr[row + 1][col] == hit_sign && arr[row + 2][col] == hit_sign && arr[row + 3][col] == hit_sign)
		{
			arr[row][col] = ' ';
			arr[row + 1][col] = ' ';
			arr[row + 2][col] = ' ';
			arr[row + 3][col] = ' ';

			if (game_turn % 2 != 0) //player
			{
				Locate_Carrier_4(arr, board_size, row, col, rotate, bot_4, sank_ship_sign, tilde);
				bot_4 -= 2;
			}

			else
			{
				Locate_Carrier_4(arr, board_size, row, col, rotate, pl_4, sank_ship_sign, tilde);
				pl_4 -= 2;
			}


		}

		else if (arr[row][col] == hit_sign && arr[row + 1][col] == hit_sign && arr[row + 2][col] == hit_sign &&
			(arr[row + 3][col] == tilde || arr[row + 3][col] == miss_sign || arr[row + 3][col] == side_sign || arr[row + 3][col] == ' ' || arr[row + 3][col] == char(205)))
		{
			arr[row][col] = ' ';
			arr[row + 1][col] = ' ';
			arr[row + 2][col] = ' ';

			if (game_turn % 2 != 0) //player
			{
				Locate_Battleship_3(arr, board_size, row, col, rotate, bot_3, sank_ship_sign, tilde);
				bot_3 -= 2;
			}

			else
			{
				Locate_Battleship_3(arr, board_size, row, col, rotate, pl_3, sank_ship_sign, tilde);
				pl_3 -= 2;
			}


		}


		else if (arr[row][col] == hit_sign && arr[row + 1][col] == hit_sign &&
			(arr[row + 2][col] == tilde || arr[row + 2][col] == miss_sign || arr[row + 2][col] == side_sign || arr[row + 2][col] == ' ' || arr[row + 2][col] == char(205)))
		{
			arr[row][col] = ' ';
			arr[row + 1][col] = ' ';

			if (game_turn % 2 != 0) //player
			{
				Locate_Submarine_2(arr, board_size, row, col, rotate, bot_2, sank_ship_sign, tilde);
				bot_2 -= 2;
			}

			else
			{
				Locate_Submarine_2(arr, board_size, row, col, rotate, pl_2, sank_ship_sign, tilde);
				pl_2 -= 2;
			}

		}

	}





}


void Attack(char** arr_P, char** arr_bot, int row, int col)
{
	if (game_turn % 2 != 0) //player's turn
	{
		if (arr_bot[row][col] == ship_sign)
		{
			arr_bot[row][col] = hit_sign;
			Change_sunkShip_sign(arr_bot, row, col);
		}

		else if (arr_bot[row][col] == ' ' || arr_bot[row][col] == side_sign)
		{
			arr_bot[row][col] = miss_sign;
			game_turn++;
		}

		else
			cout << "\a";



	}

	else //bot's turn
	{
		if (arr_P[row][col] == ship_sign)
		{
			arr_P[row][col] = hit_sign;
			Change_sunkShip_sign(arr_P, row, col);
		}

		else if (arr_P[row][col] == ' ' || arr_P[row][col] == side_sign)
		{
			arr_P[row][col] = miss_sign;
			game_turn++;
		}

	}

}


void Easy_Bot(char** arr_P)
{

	while (true)
	{
		bot_row = 2 + rand() % (board_size - 3);
		bot_col = 2 + rand() % (board_size - 3);

		if (arr_P[bot_row][bot_col] == ' ' || arr_P[bot_row][bot_col] == side_sign || arr_P[bot_row][bot_col] == ship_sign)
			break;
	}

}

void Hard_Bot(char** arr_P, char** arr_bot)
{
	bool rotate = 0; //default olaraq tek olculu
	Easy_Bot(arr_P);
	if (arr_P[bot_row][bot_col] == ship_sign)
	{
		if (arr_P[bot_row][bot_col + 1] != ship_sign || arr_P[bot_row][bot_col - 1] != ship_sign || arr_P[bot_row + 1][bot_col] != ship_sign || arr_P[bot_row - 1][bot_col] != ship_sign)
		{
			Attack(arr_P, arr_bot, bot_row, bot_col);
			arr_P[bot_row][bot_col] = sank_ship_sign;
		}

		arr_P[bot_row][bot_col] = hit_sign;
		if (arr_P[bot_row + 1][bot_col] == ship_sign || arr_P[bot_row - 1][bot_col] == ship_sign)
			rotate = 1;

		else if (arr_P[bot_row][bot_col - 1] == ship_sign || arr_P[bot_row][bot_col + 1] == ship_sign)
			rotate = 0;


		if (rotate == 0)  //horizontal
		{
			for (int i = 1; arr_P[bot_row][bot_col + i] == ship_sign; i++)
			{
				arr_P[bot_row][bot_col + i] = hit_sign;
				Change_sunkShip_sign(arr_P, bot_row, bot_col);
			}

			for (int j = 1; arr_P[bot_row][bot_col - j] == ship_sign; j++)
			{
				arr_P[bot_row][bot_col - j] = hit_sign;
				Change_sunkShip_sign(arr_P, bot_row, bot_col);
			}


		}

		else if (rotate == 1) //vertical
		{
			for (int i = 1; arr_P[bot_row + i][bot_col] == ship_sign; i++)
			{
				arr_P[bot_row + i][bot_col] = hit_sign;
				Change_sunkShip_sign(arr_P, bot_row, bot_col);
			}

			for (int j = 1; arr_P[bot_row - j][bot_col] == ship_sign; j++)
			{
				arr_P[bot_row - j][bot_col] = hit_sign;
				Change_sunkShip_sign(arr_P, bot_row, bot_col);
			}


		}




	}


}


void Check_Bot_Level(char** arr_P, char** arr_bot)
{
	if (bot_level == 1) //easy bot
	{
		Easy_Bot(arr_P);
	}

	else   //hard level bot
	{
		Hard_Bot(arr_P, arr_bot);
	}
	Attack(arr_P, arr_bot, bot_row, bot_col);
}

void change_Signs(char& sign, const char* ptr)
{
	char temp = sign;
	int num;
	if (sign == hit_sign || sign == miss_sign)
	{
		while (true)
		{
			system("cls");
			cout << ptr << "  =>  " << temp;
			num = _getch();

			if (num == 224)
			{
				num = _getch();

				if (num == 80)  //down arrow
				{
					if (temp < 90)
						temp++;

					else if (temp == 90)
						temp = 65;

				}

				else if (num == 72)  //up arrow
				{
					if (temp > 65)
						temp--;



					else if (temp == 65)
						temp = 90;


				}
			}

			//w
			else if (num == 119)
			{
				if (temp > 65)
					temp--;


				else if (temp == 65)
					temp = 90;

			}

			//s
			else if (num == 115)
			{
				if (temp < 90)
					temp++;

				else if (temp == 90)
					temp = 65;

			}


			else if (num == 13) //enter
			{
				if (temp != hit_sign && temp != miss_sign)
				{
					sign = temp;
					return;
				}
				else
				{
					cout << endl;
					cout << "this element has already been chosen" << endl;
					Sleep(1000);
				}

			}

			else if (num == 8 || num == 27) //enter backspace or escape to exit 
			{
				return;
			}


		}
	}

	else if (sign == ship_sign || sign == sank_ship_sign)
	{
		while (true)
		{
			system("cls");
			cout << ptr << "  =>  " << temp;
			num = _getch();

			if (num == 224)
			{
				num = _getch();

				if (num == 80)  //down arrow
				{
					if (temp < 237)
						temp++;

					else if (temp == 237)
						temp = 224;

				}

				else if (num == 72)  //up arrow
				{
					if (temp > 224)
						temp--;

					else if (temp == 224)
						temp = 237;


				}
			}

			//w
			else if (num == 119)
			{
				if (temp > 224)
					temp--;


				else if (temp == 224)
					temp = 237;

			}

			//s
			else if (num == 115)
			{

				if (temp < 237)
					temp++;

				else if (temp == 237)
					temp = 224;


			}


			else if (num == 13) //enter
			{
				if (temp != ship_sign && temp != sank_ship_sign)
				{
					sign = temp;
					return;
				}
				else
				{
					cout << endl;
					cout << "this element has already been chosen" << endl;
					Sleep(1000);
				}

			}

			else if (num == 8 || num == 27) //enter backspace or escape to exit 
			{
				return;
			}

		}
	}
}

void change_Font(const char* ptr)
{
	int temp = font_type;
	int num;
	while (true)
	{
		system("cls");
		Print_BattleShip(temp);
		cout << ptr << "  =>  " << temp;
		num = _getch();

		if (num == 224)
		{
			num = _getch();

			if (num == 80)  //down arrow
			{
				if (temp < 4)
					temp++;

				else if (temp == 4)
					temp = 1;

			}

			else if (num == 72)  //up arrow
			{
				if (temp > 1)
					temp--;

				else if (temp == 1)
					temp = 4;


			}

		}

		else if (num == 115 || num == 83) //s
		{
			if (temp < 4)
				temp++;

			else if (temp == 4)
				temp = 1;
		}

		else if (num == 119 || num == 87)
		{
			if (temp > 1)
				temp--;

			else if (temp == 1)
				temp = 4;
		}

		else if (num == 13) //enter
		{
			font_type = temp;
			return;

		}


		else if (num == 8 || num == 27) //backspace or escape
		{
			return;

		}

	}

}

void change_Board_Size(const char* ptr)
{
	int temp = board_size-3;
	int num;
	while (true)
	{
		system("cls");
		Print_BattleShip(temp);
		cout << ptr << "  =>  " << temp;
		num = _getch();

		if (num == 224)
		{
			num = _getch();

			if (num == 80)  //down arrow
			{
				if (temp < 20)
					temp++;

				else if (temp == 20)
					temp = 10;

			}

			else if (num == 72)  //up arrow
			{
				if (temp > 10)
					temp--;

				else if (temp == 10)
					temp = 20;


			}

		}

		else if (num == 115 || num == 83) //s
		{
			if (temp < 20)
				temp++;

			else if (temp == 20)
				temp = 10;
		}

		else if (num == 119 || num == 87)
		{
			if (temp > 10)
				temp--;

			else if (temp == 10)
				temp = 20;
		}

		else if (num == 13) //enter
		{
			board_size = temp+3;
			return;

		}


		else if (num == 8 || num == 27) //backspace or escape
		{
			return;

		}

	}

}



void Game(char** arr_P, char** arr_bot)
{
	int row = board_size / 2;
	int col = board_size / 2;
	print_Game_Boards(arr_P, arr_bot, row, col);

	while (true)

	{
		if ((bot_1 + bot_2 + bot_3 + bot_4) == 0)
		{
			cout << "Player wins!!!" << endl << endl << endl;
			Winner_Animation();
			return;
		}

		if ((pl_1 + pl_2 + pl_3 + pl_4) == 0)
		{

			cout << "Bot wins!!!" << endl << endl << endl;
			Loser_Animation();
			return;
		}


		if (game_turn % 2 != 0) //player's turn
		{
			char move;

			move = _getch();

			if (move == 72 || move == 119 || move == 87) //up
			{
				row--;
				if (row < 2)
					row++;
			}

			else if (move == 83 || move == 115 || move == 80) //down
			{
				row++;
				if (row > board_size - 2)
					row--;
			}

			else if (move == 75 || move == 65 || move == 97) //left
			{
				col--;
				if (col < 2)
					col++;
			}

			else if (move == 77 || move == 68 || move == 100)
			{
				col++;
				if (col > board_size - 2)
					col--;
			}

			else if (move == 13) //enter
			{

				Attack(arr_P, arr_bot, row, col);

			}


		}

		else //bot's turn
		{

			Check_Bot_Level(arr_P, arr_bot);
		}
		system("cls");
		print_Game_Boards(arr_P, arr_bot, row, col);
	}
}


