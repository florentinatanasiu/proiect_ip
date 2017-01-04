#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
char choice;
int map[25][80], checkPipes[25][80];
int highscore, line, column, score=0;
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
			
			break;
		case '2':
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			system("cls");
			cout << endl << endl;
			cout << "            Press any key to make bird fly.              " << endl;
			cout << "        Fly through the holes between the pipes.         " << endl;
			cout << "      When you pass through the hole,you get 1 point.    " << endl;
			cout << "            Try to pass as much as you can.              " << endl;
			cout << "       But be careful, don't hit the pipes or the ground!" << endl << endl;
			cout << endl << endl;
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
			cout << endl << endl << endl;
			cout << "              The best score is: " << highscore;
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
void main()
{
	createScreen();
	system("cls");
	cout << endl << endl;
	drawLogo();
	menu();
	system("pause");

}