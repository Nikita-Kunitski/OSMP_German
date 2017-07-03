// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include <string.h>
#include <stdio.h>
#include "iostream"
int ch;
using namespace std;

void sozdkat()
{
	TCHAR Buffer[256];
	TCHAR Buffer2[]=TEXT("d:\\OSMP1");
    TCHAR Buffer3[]=TEXT("d:\\OSMP2");

    GetCurrentDirectory(256,Buffer);
    wcout << "Dir: " << Buffer << '\n';
    GetCurrentDirectory(256,Buffer);
 wcout << "Dir: " << Buffer << '\n';
		
 
 
if (CreateDirectory(Buffer3,NULL) && CreateDirectory(Buffer2,NULL))
wcout << "directory create" << '\n';
	else
	wcout << "error create directory" << '\n';

cout<<"Выберите действие "<<endl;
cin>>ch;
}

void file()
{
	TCHAR Buffer[256]=TEXT("hello");
    HANDLE hOut; 
    TCHAR stdPath[30] = TEXT("d:\\OSMP1\\newfile.txt");
 
    hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
 
    if (hOut == INVALID_HANDLE_VALUE) {
        printf("ERROR %x \n",GetLastError());	
       
    }
    
	else
	{
        WriteFile(hOut, Buffer, 256, NULL, NULL );
        printf("Created\n");;
    CloseHandle(hOut);
	}

	cout<<"Выберите действие "<<endl;
	cin>>ch;
}

void copy()
{
    BOOL pr2=true;
 
    TCHAR stdPathA[30] = TEXT("d:\\OSMP1\\newfile.txt");
    TCHAR stdPathB[30] = TEXT("d:\\OSMP2\\1.txt");
	
    BOOL pr= CopyFile(stdPathA,stdPathB,pr2);
    if(pr)
	{
      printf("COPIED\n");
	

	}
	else
	{
        printf(" NOT COPIED\n");

	}

	cout<<"Выберите действие "<<endl;
	cin>>ch;
}

void del()
{   
    TCHAR stdPathA[30] = TEXT("d:\\OSMP1\\newfile.txt");
   
	
    BOOL pr= DeleteFile(stdPathA);
    if(pr)
	{
      printf("DELETED\n");
		

	}
	else
	{
        printf(" NOT DELETED\n");
	}
	cout<<"Выберите действие "<<endl;
	cin>>ch;
}

void konsol()
{
TCHAR Buffer[256];
    HANDLE hIn; 
    TCHAR stdPath[30] = TEXT("d:\\OSMP2\\1.txt");
     
	hIn = CreateFile(stdPath, GENERIC_READ, 0, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
 
    if (hIn == INVALID_HANDLE_VALUE) {
        printf("ERROR %x \n",GetLastError());
    }
    
	else
	{
        ReadFile(hIn, Buffer, 256, NULL, NULL );
		wcout << "Read: " << Buffer << '\n';
        CloseHandle(hIn);
	}
	cout<<"Выберите действие "<<endl;
	cin>>ch;
}

int main()
{
	setlocale(LC_CTYPE,"Rus");
	cout<<"1 - Для создания двух каталогов\n";
	cout<<"2 - Для создания и записи текста в первый каталог\n";
	cout<<"3 - Для копирования из первого каталога во второй\n";	
	cout<<"4 - Для удаления файла из первого каталога\n";	
	cout<<"5 - Для чтения файла из второй папки\n";	
	cout<<"0 - Выход\n";
	cin>>ch;
	do
	{
	
	switch(ch)
	{
	case 1:sozdkat();break;
	case 2:file();break;
	case 3:copy();break;
	case 4:del();break;
	case 5:konsol();break;
	}
	}while(ch!=0);
return 0;
}