#include "Base.h"

#pragma once
class FamilyMember :
	public Base
{
private:
	string FIO, fatherFIO, matherFIO, spouseFIO, birthDate, dieDate;
	string* childrens;
	int countChildrens;
	int age;

	void calculateAge();
public:
	FamilyMember();
	FamilyMember(string FIO, string fatherFIO, string matherFIO, string spouseFIO, string* childrens,
		int countChildrens, string birthDate, string dieDate = "-1");
	FamilyMember(const FamilyMember& familyMember);
	~FamilyMember();

	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getFIO() { return FIO; }
	void setFIO(string FIO) { this->FIO = FIO; }

	string getFatherFIO() { return fatherFIO; }
	void seFatherFIO(string fatherFIO) { this->fatherFIO = fatherFIO; }

	string getMatherFIO() { return matherFIO; }
	void setMatherFIO(string matherFIO) { this->matherFIO = matherFIO; }

	string getSpouseFIO() { return spouseFIO; }
	void setSpouseFIO(string spouseFIO) { this->spouseFIO = spouseFIO; }

	string getBirthDate() { return birthDate; }
	void setBirthDate(string FIObirthDate) { this->birthDate = birthDate; calculateAge(); }

	string getDieDate() { return dieDate; }
	void setDieDate(string dieDate) { this->dieDate = dieDate; calculateAge(); }

	string* getChildrens() { return childrens; }
	int getCountChildrens() { return countChildrens; }
	void setChildrens(string* childrens, int countChildrens);

	int getAge() { return age; }
};

