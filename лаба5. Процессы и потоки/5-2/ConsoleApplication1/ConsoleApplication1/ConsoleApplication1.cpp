#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "string.h"
//5-2\\

TCHAR buf[256] = TEXT("BELSTU");

CRITICAL_SECTION criticalS;

DWORD WINAPI myThreadRead(void* lpParameter)
{

	TCHAR stdPath[50] = TEXT("file.txt");
	HANDLE hIn;
	TCHAR Received[256];
	DWORD RegisterNumb = 0;

	EnterCriticalSection(&criticalS);

	hIn = CreateFile(stdPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hIn == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();
	}

	else
	{
		ReadFile(hIn, Received, 256, &RegisterNumb, NULL);
		printf("Read!"); std::cout << std::endl;
		std::wcout << Received << "\n";
		CloseHandle(hIn);
	}
	LeaveCriticalSection(&criticalS);
	return 0;
}

DWORD WINAPI myThreadWrite(void* lpParameter)
{
	TCHAR* textp = new TCHAR();
	textp = (TCHAR*)lpParameter;

	HANDLE hOut;
	DWORD dwNumberOfBytes;
	WCHAR stdPath[50] = TEXT("file.txt");

	EnterCriticalSection(&criticalS);

	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE)
	{
		std::cout << "ERROR %x \n" << GetLastError();
		getchar();
	}

	else
	{
		WriteFile(hOut, textp, 256, &dwNumberOfBytes, NULL);
		std::cout << "Written!"<<std::endl;
		CloseHandle(hOut);
	}

	LeaveCriticalSection(&criticalS);
	return 0;
}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	InitializeCriticalSection(&criticalS);
	DWORD myThreadID;
	DWORD myThreadID2;
	HANDLE myWriter = CreateThread(0, 0, myThreadWrite, (void*)&buf, 0, &myThreadID);
	HANDLE myReader = CreateThread(0, 0, myThreadRead, (void*)&buf, 0, &myThreadID2);
	SetThreadPriority(myWriter, THREAD_PRIORITY_HIGHEST);
	ResumeThread(myWriter);
	ResumeThread(myReader);
	WaitForSingleObject(myWriter, 3000);
	WaitForSingleObject(myReader, 3000);
	TerminateThread(myWriter,0);
	TerminateThread(myReader, 0);
}