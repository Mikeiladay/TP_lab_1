#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Base
{
public:
	Base() { cout << "Вызван конструктор Base" << endl; }
	Base(const Base& base) { cout << "Вызван конструктор копирования Base" << endl; }
	~Base() { cout << "Вызван деструктор Base" << endl; }

	virtual void printToConsole() = 0;
};

