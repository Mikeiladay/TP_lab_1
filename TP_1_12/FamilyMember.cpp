#include "FamilyMember.h"


FamilyMember::FamilyMember()
{
	countChildrens = 0;
	age = 0;
	childrens = nullptr;
	cout << "������ ����������� FamilyMember" << endl;
}
FamilyMember::FamilyMember(string FIO, string fatherFIO, string matherFIO, string spouseFIO,
	string* childrens, int countChildrens, string birthDate, string dieDate) :
	FIO(FIO), fatherFIO(fatherFIO), matherFIO(matherFIO), spouseFIO(spouseFIO),
	birthDate(birthDate), dieDate(dieDate)
{
	calculateAge();
	setChildrens(childrens, countChildrens);
	cout << "������ ����������� FamilyMember" << endl;
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
	cout << "������ ����������� ����������� FamilyMember" << endl;
}

FamilyMember::~FamilyMember()
{
	countChildrens = 0;
	delete[] childrens;
	childrens = nullptr;
	cout << "������ ���������� FamilyMember" << endl;
}

void FamilyMember::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "� ����� �� ������� ������";
	string err2 = "���� �� ����� ���� �������� �� �����";
	if (!getline(file, tmpS))
		throw err;
	FIO = tmpS;
	if (!getline(file, tmpS))
		throw err;
	fatherFIO = tmpS;
	if (!getline(file, tmpS))
		throw err;
	matherFIO = tmpS;
	if (!getline(file, tmpS))
		throw err;
	spouseFIO = tmpS;
	if (!getline(file, tmpS))
		throw err;
	if (checkDate(tmpS))
		birthDate = tmpS;
	else
		birthDate = "01.01.1900";
	if (!getline(file, tmpS))
		throw err;
	if (checkDate(tmpS))
		dieDate = tmpS;
	else
		dieDate = "-1";
	calculateAge();
	if (!getline(file, tmpS))
		throw err;
	if (isInt(tmpS))
		countChildrens = stoi(tmpS);
	else
		throw err2;
	childrens = new string[countChildrens];
	for (int i = 0; i < countChildrens; i++)
	{
		if (!getline(file, tmpS))
			throw err;
		childrens[i] = tmpS;
	}
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
	cout << "���: " << FIO << endl;
	cout << "��� ���������: " << fatherFIO << "," << matherFIO << endl;
	cout << "��� �������(�): " << spouseFIO << endl;
	cout << "���� ��������: " << birthDate << endl;
	if (dieDate != "-1")
		cout << "���� ������: " << dieDate << endl;
	cout << "������� = " << age << endl;
	if (countChildrens == 0)
		cout << "����� ���" << endl;
	else
	{
		cout << "��� �����: " << endl;
		for (int i = 0; i < countChildrens; i++)
		{
			cout << childrens[i];
			if (i != countChildrens - 1)
				cout << ", ";
		}
		cout << endl;
	}
}

void FamilyMember::printToFile(ostream& out)
{
	out << FIO << endl;
	out << fatherFIO << endl;
	out << matherFIO << endl;
	out << spouseFIO << endl;
	out << birthDate << endl;
	out << dieDate << endl;
	out << countChildrens << endl;
	for (int i = 0; i < countChildrens; i++)
		out << childrens[i] << endl;
}

void FamilyMember::change()
{
	cout << "������� ����� ��� ����� �����: ";
	getline(cin, FIO);
	cout << "������� ����� ��� �������� 1 ����� �����: ";
	getline(cin, fatherFIO);
	cout << "������� ����� ��� �������� 2 ����� �����: ";
	getline(cin, matherFIO);
	cout << "������� ����� ��� �������(�) ����� �����: ";
	getline(cin, spouseFIO);
	cout << "������� ����� ���� �������� ����� �����(��/��/����): ";
	birthDate = inputDate();

	cout << "��� �� ��� ���� �������?(1/0): ";
	bool isAiave = inputInt(0, 1);
	if (!isAiave)
	{
		cout << "������� ����� ���� ������ ����� �����(��/��/����): ";
		dieDate = inputDate();
	}

	cout << "������ ����� ���������� �����: ";
	countChildrens = inputInt(0, INT32_MAX);
	childrens = new string[countChildrens];
	for (int i = 0; i < countChildrens; i++)
	{
		cout << "������� ��� " << i + 1 << " �������: ";
		cin >> childrens[i];
	}
}

void FamilyMember::calculateAge()
{
	int birth_day = (birthDate[0] - '0') * 10 + (birthDate[1] - '0');
	int birth_month = (birthDate[3] - '0') * 10 + (birthDate[4] - '0');
	int birth_year = (birthDate[6] - '0') * 1000 + (birthDate[7] - '0') * 100 +
		(birthDate[8] - '0') * 10 + (birthDate[9] - '0');
	int die_day, die_month, die_year;

	if (!checkDate(dieDate)) {
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