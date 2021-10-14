#include "Keeper.h"

Keeper::Keeper() : data(nullptr), size(0)
	{ cout << "Вызван конструктор Keeper" << endl; }

Keeper::Keeper(Base** data, int size) 
{ 
	this->data = new Base*[size];
	this->size = size;
	for (int i = 0; i < size; i++)
		this->data[i] = data[i];
	cout << "Вызван конструктор Keeper" << endl;
}

Keeper::Keeper(const Keeper& keeper) 
{ 
	data = new Base*[keeper.size];
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
	data = new Base*[size];
	for (int i = 0; i < size - 1; i++)
		data[i] = tmp[i];
	data[size - 1] = base;
}

void Keeper::del(int index)
{
	if (index < 0 || index >= size)
		throw index;

	Base** tmp = new Base*[size - 1];
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