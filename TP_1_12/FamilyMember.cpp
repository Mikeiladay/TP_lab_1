#include "FamilyMember.h"


FamilyMember::FamilyMember()
{
	countChildrens = 0;
	age = 0;
	childrens = nullptr;
	cout << "Вызван конструктор FamilyMember" << endl;
}
FamilyMember::FamilyMember(string FIO, string fatherFIO, string matherFIO, string spouseFIO,
	string* childrens, int countChildrens, string birthDate, string dieDate) :
	FIO(FIO), fatherFIO(fatherFIO), matherFIO(matherFIO), spouseFIO(spouseFIO),
	birthDate(birthDate), dieDate(dieDate) 
{ 
	calculateAge();
	setChildrens(childrens, countChildrens);
	cout << "Вызван конструктор FamilyMember" << endl; 
}

FamilyMember::FamilyMember(const FamilyMember& familyMember) 
{ 
	FIO = familyMember.FIO;
	fatherFIO = familyMember.fatherFIO;
	matherFIO = familyMember.matherFIO;
	spouseFIO = familyMember.spouseFIO;
	birthDate = familyMember.birthDate;
	dieDate = familyMember.dieDate;
	age = familyMember.age;
	setChildrens(familyMember.childrens, familyMember.countChildrens);
	cout << "Вызван конструктор копирования FamilyMember" << endl;
}

FamilyMember::~FamilyMember() 
{ 
	countChildrens = 0;
	delete[] childrens;
	childrens = nullptr;
	cout << "Вызван деструктор FamilyMember" << endl; 
}

void FamilyMember::setChildrens(string* childrens, int countChildrens)
{
	this->childrens = new string[countChildrens];
	this->countChildrens = countChildrens;
	for (int i = 0; i < countChildrens; i++)
		this->childrens[i] = childrens[i];
}

void FamilyMember::printToConsole()
{
	cout << "ФИО: " << FIO << endl;
	cout << "ФИО родителей: " << fatherFIO << "," << matherFIO << endl;
	cout << "ФИО супруга(и): " << spouseFIO << endl;
	cout << "Дата рождения: " << birthDate << endl;
	if (dieDate != "-1")
		cout << "Дата смерти: " << dieDate << endl;
	cout << "Возраст = " << age << endl;
	if (countChildrens == 0)
		cout << "Детей нет" << endl;
	else
	{
		cout << "ФИО детей: " << endl;
		for (int i = 0; i < countChildrens; i++)
		{
			cout << childrens[i];
			if (i != countChildrens - 1)
				cout << ", ";
		}
		cout << endl;
	}
}

void FamilyMember::calculateAge()
{
	int birth_day = (birthDate[0] - '0') * 10 + (birthDate[1] - '0');
	int birth_month = (birthDate[3] - '0') * 10 + (birthDate[4] - '0');
	int birth_year = (birthDate[6] - '0') * 1000 + (birthDate[7] - '0') * 100 +
		(birthDate[8] - '0') * 10 + (birthDate[9] - '0');
	int die_day, die_month, die_year;

	if (dieDate == "-1") {
		time_t seconds = time(0);
		tm* ltm = new tm();
		gmtime_s(ltm, &seconds);
		die_day = ltm->tm_mday;
		die_month = 1 + ltm->tm_mon;
		die_year = 1900 + ltm->tm_year;
	} 
	else
	{
		die_day = (dieDate[0] - '0') * 10 + (dieDate[1] - '0');
		die_month = (dieDate[3] - '0') * 10 + (dieDate[4] - '0');
		die_year = (dieDate[6] - '0') * 1000 + (dieDate[7] - '0') * 100 +
			(dieDate[8] - '0') * 10 + (dieDate[9] - '0');
	}

	age = die_year - birth_year - 1;
	if (die_month > birth_month ||
		(die_month == birth_month && die_day >= birth_day))
		age++;
}