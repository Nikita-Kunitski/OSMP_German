#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include "string.h"
//6 �� 2-�� ������� (����� � ����)
typedef BOOL (WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);     // �������� ������������������ �������
 SETCONSOLEFONT SetConsoleFont;

int _tmain(int argc, _TCHAR* argv[])
{

HANDLE myConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD cCharsWritten;
TCHAR str[] = TEXT("HELLO TO EVERYBODY\n");

HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");    
  SetConsoleFont =(SETCONSOLEFONT) GetProcAddress(hmod, "SetConsoleFont"); 
  if (!SetConsoleFont) {std::cout<<"error\n" ; exit(1);}   //   ���� ������
  SetConsoleFont(myConsoleHandle,7);  // ������������� 3 �����. (7 �����)
 
   SetConsoleTextAttribute(myConsoleHandle,FOREGROUND_RED | FOREGROUND_INTENSITY);//������� ����

int x = 5; int y = 6;
COORD pos = {x, y};
HANDLE hConsole_c = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
SetConsoleActiveScreenBuffer(hConsole_c);

DWORD len = 20;
DWORD dwBytesWritten = 0;

WriteConsoleOutputCharacter(hConsole_c, str, len, pos, &dwBytesWritten);

pos.X=10;
pos.Y=8;

WriteConsoleOutputCharacter(hConsole_c, str, len, pos, &dwBytesWritten);

pos.X=15;
pos.Y=10;

SetConsoleCursorPosition(myConsoleHandle, pos);

WriteConsoleOutputCharacter(hConsole_c, str, len, pos, &dwBytesWritten);



getchar();
CloseHandle(hConsole_c);



	return 0;
}
