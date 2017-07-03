// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "function.h"

void zadanie_1()
{
char message[80];
	char str1[40],str2[40];
	unsigned int i,j,max_1,max_2,key_1,key_2;
	unsigned int sum_1,sum_2;
	std::cout<<"Task number 1\n";
	std::cout<<"Enter text:";
	std::cin>>message;
		//разделим строку на две
	for(i=0,j=0;i<strlen(message);i++)
	{
		if(i<=(strlen(message)/2))
		{
			str1[i]=message[i];
			max_1=i;
		}
		if(i>=((strlen(message)+1)/2))
		{
			str2[j]=message[i];
			max_2=j;
			j++;
		}
	}
	std::cout<<"Enter 1-string: ";
	output_str(str1,max_1);
	std::cout<<"Enter 2-string: ";
	output_str(str2,max_2);
		sum_1=get_sum(str1,max_1);
		sum_2=get_sum(str2,max_2);	
	key_1=get_key(sum_1,max_1);
	key_2=get_key(sum_2,max_2);
	int index;
	std::cout<<"\n1-coded according to corresponding keys";
	std::cout<<"\n2-coded according to different keys";
	std::cin>>index;
	if(index==1)
	{
	std::cout<<"\nLines of coding";
	coding_decoding(str1,max_1,key_1);
	coding_decoding(str2,max_2,key_2);
	std::cout<<"\nEncode 1-line: ";
	output_str(str1,max_1);
	std::cout<<"Encode 2-line: ";
	output_str(str2,max_2);
	}
	if(index==2)
	{
		std::cout<<"Lines of coding";
		coding_decoding(str1,max_1,key_2);
		coding_decoding(str2,max_2,key_1);
		std::cout<<"\nEncode 1-line: ";
		output_str(str1,max_1);
		std::cout<<"Encode 2-line: ";
		output_str(str2,max_2);
	}
	system("pause");
}

void zadanie_2()
{
	std::cout<<"Task number 2\n";
	char message[80];
	char revers[80];
	std::cin>>message;
	int length;
	unsigned int key, sum;
	length=strlen(message);
	int i=0,j=length-1;
	for(i=0,j=length;i<length,j>=0;i++,j--)
	{
		revers[i]=message[j];
	}

	output_str(revers,length);
	sum=get_sum(revers,length);
	std::cout<<"sum="<<sum<<"\n";
	key=get_key(sum,length);
	std::cout<<"key="<<key<<"\n";
	coding_decoding(revers,length,key);
	output_str(revers,length);
}

int _tmain(int argc, _TCHAR* argv[])
{
	zadanie_1();
	system("pause");
	zadanie_2();
	return 0;
}

