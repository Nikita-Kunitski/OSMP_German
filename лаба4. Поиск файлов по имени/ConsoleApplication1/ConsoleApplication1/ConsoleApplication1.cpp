// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
int ch;
using namespace std;

void poisk()
{
			WIN32_FIND_DATA FindFileData;
		HANDLE hFind = INVALID_HANDLE_VALUE;

		TCHAR directorySearch[] = TEXT("d:\\work\\*");
		TCHAR filesearch[] = TEXT("d:\\work\\dat*.txt");
		hFind = FindFirstFile(filesearch, &FindFileData);

		if (hFind == INVALID_HANDLE_VALUE) 
		{
		  printf ("Invalid file handle. Error is %u.\n", GetLastError());
		} 
		else
		{
			 std::wcout << "Found: " <<FindFileData.cFileName<< '\n';
		  while (FindNextFile(hFind, &FindFileData) != 0) 
		  {
			  std::wcout << "Found: " <<FindFileData.cFileName<< '\n';
		  }
		  FindClose(hFind);
}
		cout<<"�������� �������� "<<endl;
		cin>>ch;
}

void otkr()
{
		  	STARTUPINFO cif;
         ZeroMemory(&cif,sizeof(STARTUPINFO));
         PROCESS_INFORMATION pi;
		 TCHAR buf[]=TEXT("mspaint.exe");
 if(!(CreateProcess(NULL,buf, NULL, NULL, FALSE, 0,
                   NULL, NULL, &cif, &pi )))
 std::wcout << "Error " << '\n';

 cout<<"�������� �������� "<<endl;
cin>>ch;
}


  bool AreEqual(const TCHAR *a, const TCHAR *b)
{
  while(*a == *b)
  {
    if(*a==_TEXT('\0'))return true;
    a++; b++;
  }
  return false;
}



bool IsProcessRun()
{
 bool RUN;
 TCHAR buf[]=TEXT("mspaint.exe");
 
 
 HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

 PROCESSENTRY32 pe;
 pe.dwSize = sizeof(PROCESSENTRY32);
 Process32First(hSnapshot, &pe);

 if (AreEqual(pe.szExeFile, buf)) 
 {
 RUN = true;
 return RUN;
 }
 else
 RUN = false;
 while (Process32Next(hSnapshot, &pe))
 {
 if (AreEqual(pe.szExeFile, buf))  
 {
 RUN = true;
 return RUN;
 }
  else
 RUN = false;
 }
 return RUN;
}


void proverka()
{
		 	
    if(IsProcessRun())
	        {
                 
              std::wcout << "Running" << '\n';
            }
	else

	{
            std::wcout << "NOT Running"<< '\n';
	}
		cout<<"�������� �������� "<<endl;
		cin>>ch;
		}

int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_CTYPE,"Rus");
cout<<"1-����� �����;\n";
	cout<<"2-�������� �����\n";
	cout<<"3-�������� �� ���������� ������ �����\n";
	cout<<"0-�����;\n";
	cin>>ch;
do
{
	switch(ch)
	{
	case 1:poisk();break;
	case 2:otkr();break;
	case 3:proverka();break;
	}
}while (ch!=0);
	return 0;
}

