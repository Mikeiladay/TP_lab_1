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

	cout << "������ ����������� ������ �� �����?(1/0)" << endl;
	int method = inputInt(0, 1);
	try
	{
		if (method == 1)
			keeper.inputFromFile();
	}
	catch (string err)
	{
		cout << err << endl;
	}


	bool isExit = false;
	while (!isExit) {
		printMenu();
		method = inputInt(0, 5);
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
			keeper.printToFile();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void printMenu() {
	cout << "1. �������� ����� �����" << endl;
	cout << "2. �������� ����� �����" << endl;
	cout << "3. ������� ����� �����" << endl;
	cout << "4. ������� ������ �� �����" << endl;
	cout << "5. ��������� � ����" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}
//todo
void addFamilyMember(Keeper& keeper)
{
	string FIO, fatherFIO, matherFIO, spouseFIO, birthDate, dieDate = "-1";
	string* childrens;
	int countChildrens;

	cout << "������� ��� ����� �����: ";
	getline(cin, FIO);
	cout << "������� ��� ����: ";
	getline(cin, fatherFIO);
	cout << "������� ��� ������: ";
	getline(cin, matherFIO);
	cout << "������� ��� �������(�) ����� �����: ";
	getline(cin, spouseFIO);
	cout << "������� ���� �������� ����� �����(��/��/����): ";
	birthDate = inputDate();

	cout << "��� �� ��� ���� �������?(1/0): ";
	bool isAiave = inputInt(0, 1);
	if (!isAiave)
	{
		cout << "������� ���� ������ ����� �����(��/��/����): ";
		dieDate = inputDate();
	}

	cout << "������ ���������� �����: ";
	countChildrens = inputInt(0, INT32_MAX);
	childrens = new string[countChildrens];
	for (int i = 0; i < countChildrens; i++)
	{
		cout << "������� ��� " << i + 1 << " �������: ";
		getline(cin, childrens[i]);
	}
	Base* familyMember = new FamilyMember(FIO, fatherFIO, matherFIO, spouseFIO,
		childrens, countChildrens, birthDate, dieDate);
	keeper.add(familyMember);
}

void changeFamilyMember(Keeper& keeper)
{
	if (keeper.getSize() == 0)
		cout << "��������� ����� �����. ������ ��������" << endl;
	else
	{
		keeper.printToConsole();
		cout << "�������� ����� ����� ����� ��� ���������: ";
		int number = inputInt(1, INT32_MAX);
		try
		{
			keeper[number - 1]->change();
		}
		catch (int err)
		{
			cout << "����� " << err + 1 << " �� ����������� � �������" << endl;
		}
	}
}

void deleteFamilyMember(Keeper& keeper)
{
	if (keeper.getSize() == 0)
		cout << "��������� ����� �����. ������ �������" << endl;
	else
	{
		keeper.printToConsole();
		cout << "�������� ����� ����� ����� ��� ��������: ";
		int number = inputInt(1, INT32_MAX);
		try
		{
			keeper.del(number - 1);
		}
		catch (int err)
		{
			cout << "����� " << err + 1 << " �� ����������� � �������" << endl;
		}
	}
}