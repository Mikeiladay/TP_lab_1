#pragma once
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

	virtual void printToConsole() = 0;
};

