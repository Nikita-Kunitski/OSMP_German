// Laba8.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 20
#define R 21

int sch=0;

using namespace std;

struct stack {
	char str;
	int max;
	stack *next;
	stack *head;
} *st, *temp;

void push(stack *per,char stroka)
{
	if (sch !=per->max)
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

char pop(stack *Stek)
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

void proverka(stack *stek)
{
	

}

void poisk(stack *st) {

	char tstr[R]; int num=0;
	while (sch!=0) {
		tstr[num] = pop(st);
		if (tstr[num] == '.')
		{
			cout << "�� ����� ����� � ������������� ������" << endl;
		}

		if (tstr[num] == 'e')
		{
			cout << "�� ����� ����� � ��������� ������" << endl;
		}

		if (tstr[num] == 'j')
		{
			cout << "�� ����� ����������� ����� " << endl;
		}

		num++;
		
	} ;
	

}

int main() {
	setlocale(LC_CTYPE, "Russian");
	st = new stack;
	st->max = MAX;   ///////���� ���-�� ��������� 
	st->head = NULL; ///////���������� ������


	int sk1 = 0; int sk2 = 0;
	char str[R];
	again:	cout << "������� ������(�� ����� 20 ��������): ";
	cin >> str;

	for (int i(0);str[i] != '\0';i++) ////��������� � ����
	{
		if (str[i] == '(')
			sk1++;
		if (str[i] == ')')
			sk2++;
		push(st, str[i]);
	}

	if (sk1 != sk2) {
	cout << "���-�� ����������� � ����������� ������ ������ ���� ����������"<<endl;
	goto again;
	}
	poisk(st);

	
	return 0;
}
