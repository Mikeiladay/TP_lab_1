#pragma once
#include "checkInput.h"
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Base
{
public:
	Base() { cout << "������ ����������� Base" << endl; }
	Base(const Base& base) { cout << "������ ����������� ����������� Base" << endl; }
	~Base() { cout << "������ ���������� Base" << endl; }

	virtual void inputFromFile(std::ifstream& file, std::string& tmpS) = 0;
	virtual void printToConsole() = 0;
	virtual void printToFile(ostream& out) = 0;
	virtual void change() = 0;
};

