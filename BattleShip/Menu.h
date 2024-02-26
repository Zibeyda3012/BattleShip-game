#pragma once

//Main Menu
void Menu(int select)
{

	char* str1 = new char[9] {"New Game"};
	char* str2 = new char[6] {"About"};
	char* str3 = new char[9] {"Settings"};
	char* str4 = new char[5] {"Exit"};

	char** str = new char* [4] {str1, str2, str3, str4};

	//"Battleship" visual function
	Print_BattleShip(font_type);

	for (int i = 0; i < 4; i++)
	{
		if (i == select - 1)
			cout << "\t\t\t\t\t\t\t" << red << str[i] << white << endl;
		else
			cout << "\t\t\t\t\t\t\t" << str[i] << endl;
	}

	Delete_All(str, 4);
}

void NewGame(int select)
{
	char* str1 = new char[] {"Manually locate"}; //1
	char* str2 = new char[] {"Auto locate"};  //2

	char** str = new char* [2] {str1, str2};


	for (size_t i = 0; i < 2; i++)
	{
		if (i == select - 1)
			cout << blue << str[i] << white << endl;

		else
			cout << str[i] << endl;

	}

	cout << endl;
	cout << yellow << "Press Backspace button to go back to main menu..." << white << endl;

	Delete_All(str, 2);
}

void settings(char** str,int select)
{

	for (size_t i = 0; i < 7; i++)
	{
		if (i == select - 1)
			cout << purple<< str[i] << white << endl;
		else
			cout << str[i] << endl;
	}
     
}

void print_Settings()
{

	char* str1 = new char[] {"Board Size"};
	char* str2 = new char[] {"Font type"};
	char* str3 = new char[] {"Hit Sign"};
	char* str4 = new char[] {"Miss Sign"};
	char* str5 = new char[] {"Sank Ship Sign"};
	char* str6 = new char[] {"Player Ship Sign"};
	char* str7 = new char[] {"Exit"};

	char** str = new char* [7] {str1, str2, str3, str4, str5, str6,str7};
	int num;

	int choice = 1;
	settings(str,choice);

	while (true)
	{
		num = _getch();

		//arrow
		if (num == 224)
		{
			num = _getch();

			if (num == 80)  //down arrow
			{
				if (choice < 7)
					choice++;

				else if (choice == 7)
					choice = 1;

			}

			else if (num == 72)  //up arrow
			{
				if (choice > 1)
					choice--;



				else if (choice == 1)
					choice = 7;


			}
		}

		//w
		else if (num == 119)
		{
			if (choice > 1)
				choice--;



			else if (choice == 1)
				choice = 7;

		}

		//s
		else if (num == 115)
		{
			if (choice < 7)
				choice++;

			else if (choice == 7)
				choice = 1;

		}


		//enter
		else if (num == 13)
		{
			if (choice == 1) // board size
			{
				change_Board_Size(str[choice - 1]);

			}

			else if (choice == 2) //font type
			{
				change_Font(str[choice - 1]);
			}

			else if (choice == 3) //hit sign
			{

				change_Signs(hit_sign, str[choice - 1]);
			}

			else if (choice == 4) //miss sign
			{
				change_Signs(miss_sign, str[choice - 1]);

			}

			else if (choice == 5) //sank ship sign
			{
				change_Signs(sank_ship_sign, str[choice - 1]);

			}

			else if (choice == 6) // ship sign
			{
				change_Signs(ship_sign, str[choice - 1]);

			}

			else if (choice == 7) //exit
			{
				return;
			}
		}

		else if (num == 8 || num == 27)
		{
			system("cls");
			return;
		}

		system("cls");
		settings(str, choice);

	}

	Delete_All(str, 7);



}

void print_New_Game()
{
	int num;

	int choice = 1;
	NewGame(choice);

	char** arr_P = new char* [board_size] {};
	fill_Array_with_Arrays(arr_P, board_size);
	fill_Array(arr_P, board_size);

	char** arr_bot = new char* [board_size] {};
	fill_Array_with_Arrays(arr_bot, board_size);
	fill_Array(arr_bot, board_size);

	while (true)
	{
		num = _getch();

		if (num == 224)
		{
			num = _getch();

			if (num == 80)  //down arrow
			{
				if (choice < 2)
					choice++;

				else if (choice == 2)
					choice = 1;

			}

			else if (num == 72)  //up arrow
			{
				if (choice > 1)
					choice--;


				else if (choice == 1)
					choice = 2;

			}
		}


		//w
		else if (num == 119)
		{
			if (choice > 1)
				choice--;


			else if (choice == 1)
				choice = 2;

		}


		//s
		else if (num == 115)
		{
			if (choice < 2)
				choice++;


			else if (choice == 2)
				choice = 1;


		}

		else if (num == 13) //enter
		{
			if (choice == 1) //manually locate
			{
				system("cls");
				Print_Ship_Visuals();
				Manually_Locate(arr_P);
				Auto_Locate(arr_bot, true);
				break;


			}

			else if (choice == 2) //auto locate
			{
				system("cls");
				Print_Ship_Visuals();
				Auto_Locate(arr_P, false);
				Auto_Locate(arr_bot, true);
				break;

			}

		}

		else if (num == 8) //backspace
		{
			system("cls");
			break;
		}


		system("cls");
		NewGame(choice);
	}

	Game(arr_P, arr_bot);
	Delete_All(arr_P, board_size);
	Delete_All(arr_bot, board_size);
}

void Print_Main_Menu()
{
	int num;

	int choice = 1;
	Menu(choice);

	while (true)
	{
		num = _getch();

		//arrow
		if (num == 224)
		{
			num = _getch();

			if (num == 80)  //down arrow
			{
				if (choice < 4)
				{
					choice++;
					system("cls");
					Menu(choice);
				}
				else if (choice == 4)
				{
					choice = 1;
					system("cls");
					Menu(choice);
				}
			}

			else if (num == 72)  //up arrow
			{
				if (choice > 1)
				{
					choice--;
					system("cls");
					Menu(choice);
				}

				else if (choice == 1)
				{
					choice = 4;
					system("cls");
					Menu(choice);
				}
			}
		}

		//w
		else if (num == 119)
		{
			if (choice > 1)
			{
				choice--;
				system("cls");
				Menu(choice);
			}

			else if (choice == 1)
			{
				choice = 4;
				system("cls");
				Menu(choice);
			}
		}

		//s
		else if (num == 115)
		{
			if (choice < 4)
			{
				choice++;
				system("cls");
				Menu(choice);
			}
			else if (choice == 4)
			{
				choice = 1;
				system("cls");
				Menu(choice);
			}
		}


		//enter
		else if (num == 13)
		{
			if (choice == 1) //new game
			{
				system("cls");
				Print_Ship_Visuals();
				print_New_Game();
				break;
			}

			else if (choice == 2) //about
			{
				system("cls");
				Print_Ship_Visuals();
				About_Game();

				cout << yellow << "please press backspace button to go back to Main Menu... " << white << endl;
				while (num != 8)
				{
					num = _getch();
					if (num == 8)
					{
						system("cls");
						break;
					}
				}
			}

			else if (choice == 3) //settings
			{
				system("cls");
				Print_Ship_Visuals();
				print_Settings();
			}

			else if (choice == 4) //exit
			{
				system("cls");
				cout << "You are quitting game";
				for (size_t i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(400);
				}
				break;
			}
		}

		system("cls");
		Menu(choice);

	}



}
