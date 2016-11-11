// g++ -Wall -c Item.cpp -o Item.o

#include <iostream>
#include "Item.h"

Item::Item(string nome, int id)
{
	this->nome = nome;
	this->id = id;
}

string Item::getNome()
{
	return nome;
}

int Item::getId()
{
	return id;
}
