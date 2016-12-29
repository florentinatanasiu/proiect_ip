#include<iostream>
#include<Windows.h>
#include<conio.h> 
#include<stdio.h>
#include<fstream>

using namespace std;
char choice;
int bestScores[3] = { 0, 0, 0 };
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
	cout << "            Press 3: Best scores " << endl << endl;
	cout << "            Press 4: Exit        " << endl << endl;
	cin >> choice;

	while (choice !='4')
	{
		switch (choice)
		{
		case '1':
			break;
		case '2':
			break;
		case'3':
			goto showBestScores;
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
		cout <<endl<<endl<<"                   "<< "Are you sure you want to quit? [Y/N]"<<endl;
		cin >> choice;
		if (choice == 'n')
		{
			system("cls");
			menu();
		}
	}
showBestScores:
	{
		system("cls");
		cout << endl << endl << "        The highest three scores are:" << endl;
		for (int index = 0; index <= 2;index++)
		cout << endl<< "          " << bestScores[index]<<endl;

	}

}


void main()
{
	system("cls");
	cout << endl << endl;
	drawLogo();
	menu();
	
	
	system("pause");


	
}