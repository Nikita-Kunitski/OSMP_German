// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "dll.h"
#include<iostream>
#include<conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
int x = PutInt(5);
LetterList();
std::cout<<x;
_getch();
return 0;
}
