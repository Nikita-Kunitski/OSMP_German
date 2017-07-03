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
		cout << "Стек переполнен!" << endl;
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
			cout << "Вы ввели число с фиксированной точкой" << endl;
		}

		if (strok[i] == 'e')
		{
			cout << "Вы ввели число с плавающей точкой" << endl;
		}

		if (strok[i] == 'j')
		{
			cout << "Вы ввели комплексное число " << endl;
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
		cout<<"У нас представлено уравнение с ";
		if(proizw!=0)
			cout<<"произведением; ";
		if(drob!=0)
			cout<<"делением; ";
		if(plus!=0)
			cout<<"суммой; ";
		if(minus!=0)
			cout<<"вычитанием; ";
		cout<<endl;
	}
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	st = new stack;//выделяем динамическую память под переменную st
	st->max = MAX;   //Макс кол-во элементов 
	st->head = NULL; 
	int skobka1 = 0,skobka2 = 0, a,b;
	char str[21];
	cout << "Введите выражение или число(комплексное, с плав. тчк., и т.д.)(не более 20 символов): ";
	cin >> str;

	for (int i=0; str[i] != '\0'; i++) //проверка на кол-во скобок
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
		cout << "Кол-во открывающих и закрывающих скобок должно быть одинаковое" << endl;
	}
	poisk(st);

	return 0;
}