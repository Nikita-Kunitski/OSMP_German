#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include "string.h"
#include <iomanip>
using namespace std;
//6 

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
HANDLE consoleOutput;
  COORD cursorPos;
  char probel=' ', lastname[15];
  int gruppa;
	// Получаем хэндл консоли 
  consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

WORD   index   = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( consoleOutput, &csbi );
	cout<<"Введите фамилию: ";
	cin>>lastname;
	cout<<"Введите группу: ";
	cin>>gruppa;
	// Задаем координаты курсора и перемещаем курсор
  cursorPos.X = 30;
  cursorPos.Y = 3;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  SetConsoleTextAttribute( consoleOutput, 0xCC );
  cout<<setw(41)<<setfill(probel)<<probel;

  cursorPos.X = 30;
  cursorPos.Y = 4;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  cout<<probel;
  SetConsoleTextAttribute( consoleOutput, 0x0F );
  cout<<"   Фамилия";

  cursorPos.X = 50;
  cursorPos.Y = 4;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  SetConsoleTextAttribute( consoleOutput, 0xCC );
  cout<<probel;
  SetConsoleTextAttribute( consoleOutput, 0x0F );
  cout<<"   Группа";

  cursorPos.X = 70;
  cursorPos.Y = 4;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  SetConsoleTextAttribute( consoleOutput, 0xCC );
  cout<<probel;

  cursorPos.X = 30;
  cursorPos.Y = 5;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  cout<<setw(41)<<setfill(probel)<<probel;

  cursorPos.X = 30;
  cursorPos.Y = 6;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  cout<<probel;
  SetConsoleTextAttribute( consoleOutput, 0x0F );
  cout<<lastname;

  cursorPos.X = 50;
  cursorPos.Y = 6;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  SetConsoleTextAttribute( consoleOutput, 0xCC );
  cout<<probel;
  SetConsoleTextAttribute( consoleOutput, 0x0F );
  cout<<gruppa;

   cursorPos.X = 70;
  cursorPos.Y = 6;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  SetConsoleTextAttribute( consoleOutput, 0xCC );
  cout<<probel;

   cursorPos.X = 30;
  cursorPos.Y = 7;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  cout<<setw(41)<<setfill(probel)<<probel;


cursorPos.X = 1;
  cursorPos.Y = 9;
  SetConsoleCursorPosition(consoleOutput, cursorPos);
  SetConsoleTextAttribute( consoleOutput, 0x0F );
	return 0;
}
