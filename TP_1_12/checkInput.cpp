#include "checkInput.h"

bool isInt(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

bool isSplit(char c)
{
	if (c == '.' || c == '/')
		return true;
	else
		return false;
}

bool isInt(string s)
{
	if (s.size() < 1)
		return false;
	for (int i = 0; i < s.size(); i++)
		if (s[i] < '0' || s[i] > '9')
			return false;
	return true;
}

bool checkDate(string date)
{
	if (date.size() == 10) 
	{
		if (isInt(date[0]) && isInt(date[1]) && isSplit(date[2]) &&
			isInt(date[3]) && isInt(date[4]) && isSplit(date[5]) &&
			isInt(date[6]) && isInt(date[7]) && isInt(date[8]) && isInt(date[9]))
			return true;
	}	
	return false;
}

int inputInt(int minInput, int maxInput) {
	while (true)
	{
		int method;
		std::cin >> method;
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			std::cout << "Неверный ввод.\nВведите повторно: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

string inputDate()
{
	while (true)
	{
		string date;
		getline(cin, date);
		if (checkDate(date))
			return date;
		cout << "Неверный формат даты. Введите повторно: ";
	}
}