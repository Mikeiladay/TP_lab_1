#include "Keeper.h"

Keeper::Keeper() : data(nullptr), size(0)
{
	cout << "Вызван конструктор Keeper" << endl;
}

Keeper::Keeper(Base** data, int size)
{
	this->data = new Base * [size];
	this->size = size;
	for (int i = 0; i < size; i++)
		this->data[i] = data[i];
	cout << "Вызван конструктор Keeper" << endl;
}

Keeper::Keeper(const Keeper& keeper)
{
	data = new Base * [keeper.size];
	size = keeper.size;
	for (int i = 0; i < size; i++)
		this->data[i] = keeper.data[i];
	cout << "Вызван конструктор копирования Keeper" << endl;
}

Keeper::~Keeper()
{
	size = 0;
	delete[] data;
	data = nullptr;
	cout << "Вызван деструктор Keeper" << endl;
}

void Keeper::add(Base* base)
{
	Base** tmp = data;
	size++;
	data = new Base * [size];
	for (int i = 0; i < size - 1; i++)
		data[i] = tmp[i];
	data[size - 1] = base;
}

void Keeper::del(int index)
{
	if (index < 0 || index >= size)
		throw index;

	Base** tmp = new Base * [size - 1];
	int k = 0;
	for (int i = 0; i < size; i++)
		if (i != index)
			tmp[k++] = data[i];
	size--;
	data = tmp;
}

Base* Keeper::operator[](int index)
{
	if (index < 0 || index >= size)
		throw index;
	return data[index];
}

void Keeper::inputFromFile()
{

	ifstream input("save.txt");
	if (input.is_open())
	{
		string tmpS;
		int countRecord;
		if (!getline(input, tmpS))
		{
			input.close();
			string err = "Файл не может быть прочитан до конца";
			throw err;
		}
		if (isInt(tmpS))
			countRecord = stoi(tmpS);
		else
		{
			input.close();
			string err = "Не распознано количество членов семьи";
			throw err;
		}
		try
		{
			for (int i = 0; i < countRecord; i++)
			{
				Base* obj = new FamilyMember();
				obj->inputFromFile(input, tmpS);
				this->add(obj);
			}
		}
		catch (string err)
		{
			input.close();
			throw err;
		}
		input.close();
	}
	else
	{
		string err = "Файл с данными не обнаружен";
		throw err;
	}
}

void Keeper::printToFile()
{
	ofstream output("save.txt");
	output << size << endl;
	for (int i = 0; i < size; i++)
		data[i]->printToFile(output);
	output.close();
}

void Keeper::printToConsole()
{
	if (size == 0)
		cout << "Фамильное древо пусто" << endl;
	else
	{
		cout << "Фамильное древо: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". ";
			data[i]->printToConsole();
		}
	}
}