// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <locale>
#include <windows.h>

void NOD_2()
{
	short int a,b;
	std::cout<<"Введите число А:";
	std::cin>>a;
	std::cout<<"Введите число В:";
	std::cin>>b;
	_asm
	{
		mov ax, a
		mov bx, b
		jmp start
start:
		cmp ax,bx
			jg c1
		cmp bx,ax
		jg c2
		jmp c3
c1:
		sub ax, bx
			jmp start
c2:
		sub bx, ax
			jmp start
c3:
		mov a,ax
	}
	std::cout<<"Результат"<<a<<"\n";
	}

void NOD_3()
{
	short int a,b, c ;
	std::cout<<"Введите А:";
	std::cin>>a;
	std::cout<<"Введите B:";
	std::cin>>b;
	std::cout<<"Введите C:";
	std::cin>>c;
	_asm
	{
		mov ax, a
		mov bx, b
		jmp start
start:
		cmp ax, bx
		jg d1
		cmp bx, ax
		jg d2
		jmp d3
d1:
		sub ax, bx
		jmp start
d2:
		sub bx, ax
		jmp start
d3:
		mov a, ax
		mov bx, c
		//нод для первых 2-х найден

		jmp start1
start1:
		cmp ax, bx
		jg c1
		cmp bx, ax
		jg c2
		jmp c3
c1:
		sub ax, bx
		jmp start1
c2:
		sub bx, ax
		jmp start1
c3:
		mov a, ax
	}
	std::cout<<"Результат "<<a;
}

void razr()
{
	short int a;
	std::cout<<"Введите А:";
	std::cin>>a;
	_asm
	{
		mov ax, a
		and ax, 00000100B
		shr ax,2//сдвиг вправо на 2 элемента
		mov a, ax
	}
	std::cout<<"В третьем разряде стоит: "<<a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	int chisl;
	do{
	std::cout<<"\n1-НОД 2-х чисел\n";
	std::cout<<"2-НОД 3-ч чисел\n";
	std::cout<<"3-Вычисление значения в 3-ем разряде\n";
	std::cout<<"0-EXIT\n";
	std::cin>>chisl;
	switch (chisl)
	{
	case 1:NOD_2();
		break;
	case 2:NOD_3();
		break;
	case 3:razr();
		break;
	}
	}while(chisl!=0);
	return 0;
}

