// Laba8.cpp: определяет точку входа для консольного приложения.
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
		cout << "Стек переполнен!" << endl;
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
			cout << "Вы ввели число с фиксированной точкой" << endl;
		}

		if (tstr[num] == 'e')
		{
			cout << "Вы ввели число с плавающей точкой" << endl;
		}

		if (tstr[num] == 'j')
		{
			cout << "Вы ввели комплексное число " << endl;
		}

		num++;
		
	} ;
	

}

int main() {
	setlocale(LC_CTYPE, "Russian");
	st = new stack;
	st->max = MAX;   ///////Макс кол-во элементов 
	st->head = NULL; ///////Установили голову


	int sk1 = 0; int sk2 = 0;
	char str[R];
	again:	cout << "Введите строку(не более 20 символов): ";
	cin >> str;

	for (int i(0);str[i] != '\0';i++) ////Загружаем в стек
	{
		if (str[i] == '(')
			sk1++;
		if (str[i] == ')')
			sk2++;
		push(st, str[i]);
	}

	if (sk1 != sk2) {
	cout << "Кол-во открывающих и закрывающих скобок должно быть одинаковое"<<endl;
	goto again;
	}
	poisk(st);

	
	return 0;
}
