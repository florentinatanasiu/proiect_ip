#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;

ifstream inputFile;
ofstream outputFile;
char choice;
int highscore;
bool error;
int line, column, score, mov = 0, repeatLoop = 5, birdColumn, birdLine, birdTime, pipeHole;
int map[25][80];
int checkPipes[25][80];
int logo[10][42] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 2, 2, 2, 0, 2, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 2, 2, 2, 0, 2, 0, 2, 0, 0, 2, 2, 2, 0, 2, 0, 2, 2, 2, 0, 2, 2, 0, 0, 1 },
	{ 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 1 },
	{ 1, 0, 2, 2, 0, 0, 2, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 2, 2, 2, 0, 0, 2, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 2, 2, 0, 2, 0, 2, 0, 1 },
	{ 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 0, 2, 0, 2, 0, 1 },
	{ 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 1 },
	{ 1, 0, 2, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

void game();
void showScreen();
void pipes();
void movBird();
bool gameOver();
void checkScore();
void menu();
void endGame();

void drawLogo()
{
	for (int lines = 0; lines < 10; lines++)
	{
		for (int columns = 0; columns < 42; columns++)
		{
			switch (logo[lines][columns])
			{
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				cout << " ";
				break;

			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				cout << char(219);
				break;

			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << char(219);
				break;
			}
		}
		cout << " " << endl;
	}

}

void createScreen()
{
	system("cls");

	for (column = 0; column < 80; column++)
	{
		map[0][column] = 223;
		map[24][column] = 223;

	}
	for (line = 0; line < 25; line++)
	{
		map[line][0] = 223;
		map[line][79] = 223;
	}

	map[10][5] = 157;
	column = 20;
	while (column < 78)
	{
		int pipeHole = 6 + (rand() % 10);
		for (line = 1; line < 24; line++)
		{
			map[line][column] = 221;
			checkPipes[line][column] = 1;
		}
		map[pipeHole][column] = 0;
		checkPipes[pipeHole][column] = 0;
		map[pipeHole - 1][column] = 0;
		checkPipes[pipeHole + 1][column] = 0;
		map[pipeHole + 1][column] = 0;
		checkPipes[pipeHole - 1][column] = 0;
		column += 10;
	}
}

void showScreen()
{
	system("cls");
	for (line = 0; line < 25; line++)
	{
		for (column = 0; column < 80; column++)
		{
			switch (map[line][column])
			{
			case 223:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << char(map[line][column]);
				break;
			case 221:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				cout << char(map[line][column]);
				break;
			case 157:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << char(map[line][column]);
				break;
			case 0:
				cout << " ";
				break;
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Your score is:" << score << endl;
}

void movBird()
{
	if (mov>0)
	{
		birdTime = 0;
		for (line = 1; line<24; line++)
		{
			for (column = 1; column<79; column++)
			{
				if (map[line][column] == 157)
				{
					if (line>1)
					{
						map[line - 1][column] = 157;
						map[line][column] = 0;
						birdLine = line - 1;
						birdColumn = column;
						return;
					}
				}
			}
		}
	}
	else
	{
		birdTime++;
		for (line = 1; line<24; line++)
		{
			for (column = 1; column<79; column++)
			{
				if (map[line][column] == 157)
				{
					if (line<23)
					{
						if (birdTime<3)
						{
							{
								map[line + 1][column] = 157;
								map[line][column] = 0;
								birdLine = line - 1;
								birdColumn = column;
								return;
							}
						}
						else if (birdTime>2 && birdTime<5)
						{
							map[line + 2][column] = 157;
							map[line][column] = 0;
							birdColumn = column;
							birdLine = line + 2;
							return;
						}
						else if (birdTime>5)
						{
							map[line + 3][column] = 157;
							map[line][column] = 0;
							birdColumn = column;
							birdLine = line + 3;
							return;
						}
					}
					else return;
				}
			}
		}
	}
}

void pipes()
{
	if (repeatLoop == 10)
	{
		pipeHole = 5 + (rand() % 12);
		for (line = 1; line < 24; line++)
		{
			map[line][78] = 221;
			checkPipes[line][78] = 1;
		}
		map[pipeHole][78] = 0;
		map[pipeHole - 1][78] = 0;
		map[pipeHole + 1][78] = 0;
		repeatLoop = 0;
		goto movPipe;
	}
	else goto movPipe;
movPipe:
	{    repeatLoop++;
	for (line = 1; line<24; line++)
	{
		for (column = 1; column<79; column++)
		{
			if (map[line][column] == 221)
			{
				if (column>1)
				{
					map[line][column - 1] = 221;
					checkPipes[line][column - 1] = 1;
					map[line][column] = 0;
					checkPipes[line][column] = 0;
				}
				if (column == 1)
				{
					map[line][column] = 0;
					checkPipes[line][column] = 0;
				}
			}
		}
	}
	}
}

void checkScore()
{

	for (line = 1; line<24; line++)
	{
		if (map[line][birdColumn] == 221 && gameOver() == false)
		{
			score++;
			return;
		}
	}
}

bool gameOver()
{
	if ((birdLine >= 23 || birdLine <= 1))
		return true;

	if (checkPipes[birdLine][birdColumn]>0 && (map[birdLine][birdColumn] == 221 || map[birdLine][birdColumn] == 157))
		return true;
	return false;
}

void menu()
{
	cout << endl << endl;
	cout << "                     M E N U:    " << endl << endl;
	cout << "            Press 1: Start Game  " << endl << endl;
	cout << "            Press 2: Help        " << endl << endl;
	cout << "            Press 3: Best score  " << endl << endl;
	cout << "            Press 4: Exit        " << endl << endl;
	cin >> choice;

	while (choice != '4')
	{
		switch (choice)
		{
		case '1':
			game();
			break;
		case '2':
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			system("cls");
			cout << endl << endl<<endl;
			cout << "                *       *       *       *       *       " << endl;
			cout << "                            I N S T R U C T I O N S: " << endl;
			cout << "                    *       *       *       *        *       * " << endl;
			cout << endl << endl;

			cout << "              * Press any key to make bird fly.          " << endl;
			cout << "              * Fly through the holes between the pipes.         " << endl;
			cout << "              * When you pass through the hole,you get 1 point.    " << endl;
			cout << "              * Try to pass as much as you can.              " << endl;
			cout << "              * But be careful, don't hit the pipes or the ground!" << endl << endl;
			cout << endl << endl << endl;
			cout << "       Do you want o return to menu?[Y/N]" << endl;
			cin >> choice;
			if (choice == 'y')
			{
				system("cls");
				menu();
			}
			else goto exit;
			break;
		case'3':
			system("cls");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "                THE  BEST  SCORE : " << highscore;
			cout << endl << endl;
			cout << "              Return to main?[Y/N]" << endl;
			cin >> choice;
			if (choice == 'y')
			{
				system("cls");
				menu();
			}
			else goto exit;

			break;
		case '4':
			goto exit;
			break;
		default:
			cout << "You choose a wrong key..Please select another option ^_^ ";
			break;
		}
		cin >> choice;
	}

exit:
	{
		system("cls");
		cout << endl << endl << "                   " << "Are you sure you want to quit? [Y/N]" << endl;
		cin >> choice;
		if (choice == 'n')
		{
			system("cls");
			menu();
			return;
		}
	}
}

void endGame()
{
	system("cls");
	if (score > highscore)
	{
		highscore = score;
		score = 0;
	}
	if (error == false)
	{
		outputFile.open("file.txt");
		outputFile << highscore;
		outputFile.close();
	}
	cout << endl << endl;
	cout << "                ------------------------------------------------------------------------- " << endl;
	cout << "               |    *****      *     *       * ******       ****  *       ****** ****    |" << endl;
	cout << "               |   *          * *    * *   * * *           *    *  *     * *     *   *   |" << endl;
	cout << "               |   *  ****   *   *   *  * *  * *****       *    *   *   *  ****  ****    |" << endl;
	cout << "               |   *  *  *  *******  *   *   * *           *    *    * *   *     * *     |" << endl;
	cout << "               |    *****  *       * *       * ******       ****      *    ***** *   *   |" << endl;
	cout << "                ------------------------------------------------------------------------- " << endl;
	cout << "" << endl << endl;
	cout << "                        Y O U R   S C O R E : " << score << endl << endl;
	cout << "                        H I G H   S C O R E : " << highscore;
}

void game()
{
	showScreen();
	while (true)
	{
		Sleep(150);
		choice = '*';
		if (_kbhit())
		{
			choice = _getch();
			if (choice != '*')
				mov = 1;
		}
		movBird();
		checkScore();
		if (gameOver() == true)
		 goto end;
		pipes();
		if (score > highscore)
			highscore = score;
		showScreen();
		if (mov > 0)
			mov++;
		if (mov == 3)
			mov = 0;
	}
end:
	endGame();
}

void main()
{
	createScreen();
	system("cls");
	cout << endl << endl;
	drawLogo();
	inputFile.open("file.txt");
	if (inputFile.is_open())
	{
		inputFile >> highscore;
		inputFile.close();
		error = false;
	}
	else
	{
		highscore = 0;
		error = true;
	}
	menu();
	system("pause");

}