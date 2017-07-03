#include "stdafx.h"
#include "function.h"
#include <iostream>


 void output_str(char* str, unsigned int max)
 {
	for (unsigned int i=0; i<=max;i++)
		std::cout<<str[i];
	std::cout<<"\n";
 }

 unsigned int get_sum ( char* str, unsigned int max)
 {
	 unsigned int sum=0;
	 for(int i(0);i<=max;i++)
	 {
		sum+=str[i];
	 }
 return sum;
 }

 unsigned int get_key(unsigned int sum, unsigned int max)
 {
	 unsigned int key;
	 key=sum/max;
 return key;
 }

 void coding_decoding(char* str, unsigned int max, unsigned int key)
 {
  for(int i(0);i<=max;i++)
	  str[i]=str[i] ^ key; 
 }