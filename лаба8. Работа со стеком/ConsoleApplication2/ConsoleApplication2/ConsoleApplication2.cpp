#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 20

int sch = 0;

using namespace std;

struct stack {
	char str;
	int max;
	stack *next;
	stack *head;
} *st, *temp;

void push(stack *per, char stroka)
{
	if (sch != per->max)
	{
		if (per->head == NULL)
		{
			per->head = new stack;
			per->head->str = stroka;
			per->head->next = NULL;
		}
		else
		{
			temp = new stack;
			temp->str = stroka;
			temp->next = per->head;
			per->head = temp;
		}
		sch++;
	}
	else
	{
		cout << "���� ����������!" << endl;
	}
}

char del(stack *Stek)
{
	char my_sym;
	if (sch != 0)
	{
		my_sym = Stek->head->str;
		temp = Stek->head;
		Stek->head = Stek->head->next;
		delete temp;
		sch--;
		return my_sym;
	}
	else
	{
		return false;
	}
}

void poisk(stack *st) {

	char strok[21]; int i = 0;
	int plus=0, minus=0, proizw=0, drob=0;
	int uravn=0;
	while (sch != 0) 
	{
		strok[i] = del(st);
		if ((strok[i] == '.')||(strok[i] == ','))
		{
			cout << "�� ����� ����� � ������������� ������" << endl;
		}

		if (strok[i] == 'e')
		{
			cout << "�� ����� ����� � ��������� ������" << endl;
		}

		if (strok[i] == 'j')
		{
			cout << "�� ����� ����������� ����� " << endl;
		}

			if((strok[i]=='*')||(strok[i]=='/')||(strok[i]=='+')||(strok[i]=='-'))
		{
			uravn++;
			if((strok[i]=='*'))
				proizw++;
			if((strok[i]=='/'))
				drob++;
			if((strok[i]=='+'))
				plus++;
			if((strok[i]=='-'))
				minus++;
		}
		i++;
	}
	if(uravn!=0)
	{
		cout<<"� ��� ������������ ��������� � ";
		if(proizw!=0)
			cout<<"�������������; ";
		if(drob!=0)
			cout<<"��������; ";
		if(plus!=0)
			cout<<"������; ";
		if(minus!=0)
			cout<<"����������; ";
		cout<<endl;
	}
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	st = new stack;//�������� ������������ ������ ��� ���������� st
	st->max = MAX;   //���� ���-�� ��������� 
	st->head = NULL; 
	int skobka1 = 0,skobka2 = 0, a,b;
	char str[21];
	cout << "������� ��������� ��� �����(�����������, � ����. ���., � �.�.)(�� ����� 20 ��������): ";
	cin >> str;

	for (int i=0; str[i] != '\0'; i++) //�������� �� ���-�� ������
	{
		if (str[i] == '(')
		{
			skobka1++;
			a=i;
		}
		if (str[i] == ')')
			{
				b=i;
				skobka2++;
			}
		push(st, str[i]);
	}

	if (skobka1 != skobka2 || a>b) {
		cout << "���-�� ����������� � ����������� ������ ������ ���� ����������" << endl;
	}
	poisk(st);

	return 0;
}