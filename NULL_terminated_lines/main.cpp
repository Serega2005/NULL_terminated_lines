﻿#include<iostream>
#include<ctype.h> //для проверки, является ли символ цифрой
#include<Windows.h>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void to_upper(char str[]);
void to_lower(char str[]);
void capitalize(char str[]);
void shrink(char str[]);

void remove_symbol(char str[], char symbol);

int StrLen(char str[]);

bool is_palindrome(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);
bool is_hex_number(char str[]);

int to_int_number(char str[]);
int bin_to_dec(char str[]);
int hex_to_dec(char str[]);

//#define BASE_STRING_OPERATIONS
//#define BINARY_NUMBERS
#define NEX_NUMBERS

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << tab << (char)i << endl;
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("CHCP 1251");
	system("CLS");
#ifdef BASE_STRING_OPERATIONS
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";
	const int n = 256;
	char str[n];
	//ASCII();
	cout << "Введите строку: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, n);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << "Размер строки в Байтах: " << sizeof(str) << endl;
	cout << "Размер строки в символах: " << StrLen(str) << endl;
	to_upper(str);
	cout << "Переводим строку в верхний регистр: " << str << endl;
	to_lower(str);
	cout << "Переводим строку в нижний регистр: " << str << endl;
	capitalize(str);
	cout << "Возводим первую букву каждого слова в верхний регистр: " << str << endl;
	shrink(str);
	cout << "Удаляем лишние пробелы: " << str << endl;

	cout << "Эта строка является палиндромом?: " << (is_palindrome(str)? "Да" : "Нет") << endl;
	cout << str << endl;
#endif // BASE_STRING_OPERATIONS
	//ASCII();
	const int n = 256;
	char str[n] = {};
	cout << "Введите строку: "; 
	cin.getline(str, n);
#ifdef BINARY_NUMBER
    cout << (is_int_number(str) ? "Число" : "НЕ число") << endl;
	cout << to_int_number(str) * 2 << endl;
	cout << "Строка " << (is_bin_number(str) ? "является двоичным числом" : "НЕ является двоичным числом") << endl;
	cout << str << "(bin) - " << bin_to_dec(str) << "(dec)" <<endl;	cin.getline (str, n);
#endif // BINARY_NUMBER

#ifdef NEX_NUMBERS
	cout << "Строка " << (is_hex_number(str) ? "является шестнадцатиричным числом" : "НЕ является шестнадцатиричным числом") << endl;
	cout << str << "(Hex) = " << hex_to_dec(str) << "(Dec)" << endl;

#endif //NEX_NUMBERS
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
		{
		   str[i] -= 32;
		}
		else if (str[i] == 'ё') str[i] -= 16;
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
		{
			str[i] += 32;
		}
	    else if (str[i] == 'Ё') str[i] += 16;
	}
}

void capitalize(char str[])
{
	to_lower;
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;
	else if (str[0] == 'ё') str[0] -= 16;
	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') && str[i-1] == ' ')str[i] -= 32;
		else if (str[i] == 'ё' && str[i-1] == ' ') str[i] -= 16;
		else if (str[i] == 'Ё' && str[i - 1] == ' ') str[i] += 16;
	}

}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

bool is_palindrome(char str[])
{
	//Определяем длину строки
	int size = StrLen(str);
	char* buffer = new char[size+1] {};
	str = buffer;
	//for (int i = 0; str[i]; i++)buffer[i] = str[i];
	strcpy(buffer, str);//String Copy. buffer - строка получатель, str - строка источник

	remove_symbol(buffer, ' ');
	to_lower(buffer);
	size = strlen(buffer);
	for (int i = 0; i< size/2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
	//return 0;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')return false;
		if (str[i-1] == ' ' && str[i] == ' ' && str[i+1] == ' ')return false;
	}
	return true;
}

bool is_hex_number(char str[])
{
	for (int i = str[0] == '0' && str[1]=='x'? 2:0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			str[i] != ' '
			)return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;

}

int to_int_number(char str[])
{
	if (!is_int_number(str))return 0;
	int number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')continue;
		number *= 10;
		number += str[i] - 48;
	}
	return number;
}

int bin_to_dec(char str[])
{
	if (!is_bin_number(str))return 0;
	int n = StrLen(str);
	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}
	}
	return decimal;

	//int decimal = 0;//конечное десятичное число
	//int weight = 1; //весовой коэффициент разряда
	//int size = StrLen(str);
	//for (int i = 0; str[i]; i++)
	//{
	//	if (str[i] == ' ')continue;
	//	if (str[i] == '1')
	//	{
	//		weight = 2 ^ (size - 1 - i);
	//	}
	//	if (str[i] == '0')continue;
	//	decimal += weight;
	//}
	//return decimal;
}

int hex_to_dec(char str[])
{
	if (!is_hex_number(str))return 0;
	int n = strlen(str);
	char* buffer = new char[n + 1]{};
	strcpy(buffer, str);
	to_upper(buffer);

	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (buffer[i] == 'x' || buffer[i] == 'X')break;
		if (buffer[i] != ' ')
		{
			decimal += (buffer[i] - (isdigit(buffer[i])? 48 : 55)) * weight;
			weight *= 16;
		}
	}
	return decimal;
}
