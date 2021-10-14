#include "Keeper.h"
#include "FamilyMember.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addFamilyMember(Keeper& keeper);
void changeFamilyMember(Keeper& keeper);
void deleteFamilyMember(Keeper& keeper);

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper keeper;
	

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method;
		cin >> method;
		switch (method)
		{
		case 1:
			addFamilyMember(keeper);
			break;
		case 2:
			changeFamilyMember(keeper);
			break;
		case 3:
			deleteFamilyMember(keeper);
			break;
		case 4:
			keeper.printToConsole();
			break;
		case 5:
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void printMenu() {
	cout << "1. Добавить члена семьи" << endl;
	cout << "2. Изменить члена семьи" << endl;
	cout << "3. Удалить члена семьи" << endl;
	cout << "4. Вывести данные на экран" << endl;
	cout << "5. Сохранить в файл" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}
//todo
void addFamilyMember(Keeper& keeper)
{
	string FIO, fatherFIO, matherFIO, spouseFIO, birthDate, dieDate = "-1";
	string* childrens;
	int countChildrens;

	getline(cin, FIO);
	cout << "Введите ФИО члена семьи: ";
	getline(cin, FIO);
	cout << "Введите ФИО родителя 1 члена семьи: ";
	getline(cin, fatherFIO);
	cout << "Введите ФИО родителя 2 члена семьи: ";
	getline(cin, matherFIO);
	cout << "Введите ФИО супруга(и) члена семьи: ";
	getline(cin, spouseFIO);
	cout << "Введите дату рождения члена семьи(дд/мм/гггг): ";
	getline(cin, birthDate);

	cout << "Жив ли еще этот человек?(1/0): ";
	bool isAiave;
	cin >> isAiave;
	if (!isAiave)
	{
		getline(cin, dieDate);
		cout << "Введите дату смерти члена семьи(дд/мм/гггг): ";
		getline(cin, dieDate);
	}

	cout << "Введие количество детей: ";
	cin >> countChildrens;
	childrens = new string[countChildrens];
	for (int i = 0; i < countChildrens; i++)
	{
		cout << "Введите ФИО " << i + 1 << " ребенка: ";
		cin >> childrens[i];
	}
	Base* familyMember = new FamilyMember(FIO, fatherFIO, matherFIO, spouseFIO, 
		childrens, countChildrens, birthDate, dieDate);
	keeper.add(familyMember);
}

void changeFamilyMember(Keeper& keeper)
{

}

void deleteFamilyMember(Keeper& keeper)
{
	if (keeper.getSize() == 0)
		cout << "Фамильное древо пусто. Некого удалять" << endl;
	else
	{
		keeper.printToConsole();
		cout << "Выберете номер члена семьи для удаления: ";
		int number;
		cin >> number;
		try
		{
			keeper.del(number - 1);
		}
		catch (int err)
		{
			cout << "Номер " << err + 1 << " не содержиться в массиве" << endl;
		}
	}
}