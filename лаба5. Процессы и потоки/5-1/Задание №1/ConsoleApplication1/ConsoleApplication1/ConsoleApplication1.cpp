// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
//5-1, задание 1
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "string.h"

DWORD WINAPI myThread(void* lpParameter)
{
   
	int* counterp= new int();
	counterp=(int*) lpParameter;
	int counter=*counterp;

    while(counter<20)
	{
    Sleep(600);
    counter++;
	printf("\n Counter= %d",counter);
	}

	return 0;
}

DWORD WINAPI myThread_1(LPVOID lpParameter)
{
	unsigned int counter=0;
	
    while(counter<20)
	{
    Sleep(600);
    counter++;
	printf("\n Counter= %d",counter);
	}

	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{

  int z=5;
  
  unsigned int myCounter = 0;
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(0, 0, myThread, &z, 0, &myThreadID);
	HANDLE myHandle_1 = CreateThread(0, 0, myThread_1, &myCounter, 0, &myThreadID);
	Sleep(3000);
	printf("\n Main Process sagt");
	TerminateThread(myHandle,0);
	TerminateThread(myHandle_1,0);	
	return 0;
}
