#include "stdafx.h"
#include "DArray.h"
#include <iostream>


DArray::DArray(int size)
{
	this->size = size;
	this->dArray = nullptr;
}

void DArray::pushFront(int value)
{
	size++;
	int *tempArray = new int[size];		// zaalokowanie	tablicy o nowym rozmiarze

	*tempArray = value;					
	memcpy(tempArray + 1, dArray, (size-1)*sizeof(int));	// skopiowanie zawartosci z poprzedniej tablicy do nowej

	delete[] dArray;					// zwolnienie pamieci zajmowanej przez poprzednia tablice
	dArray = tempArray;					// przypisanie adresu do aktualnej tablicy
}

void DArray::pushBack(int value)
{
	size++;
	int *tempArray = new int[size];		// zaalokowanie tablicy o nowym rozmiarze

	*(tempArray + (size-1)) = value;	// przypisanie wartosci do ostatniego elementu w nowej tablicy
	memcpy(tempArray, dArray, (size - 1) * sizeof(int));	// przekopiowanie zawartosci z poprzedniej tablicy

	delete[] dArray;					// zwolnienie pamieci zajmowanej przez poprzednia tablice
	dArray = tempArray;					// przypisanie adresu do aktualnej tablicy
}

void DArray::pushAt(int value, int index)
{
	if (index < size && index >= 0)		// restrykcje podanych danych					
	{
		if (dArray == nullptr)			// tablica jest pusta
		{
			size++;
			dArray = new int[size];			

			*dArray = value;

			return;
		}
		else if (index == 0)			// jesli podany jest index: 0 lub (size + 1) to nastepuje pushFront lub pushBack 
			pushFront(value);
		else if (index == size)
			pushBack(value);
		else
		{
			size++;
			int *tempArray = new int[size];	// zalokowanie tablicy o nowym rozmiarze

			*(tempArray + index) = value;	// przypisanie wartosci do komorki o zadanym indeksie

			memcpy(tempArray, dArray, index * sizeof(int));		// przekopiowanie zawartosci z poprzedniej tablicy do zadanego indeksu
			memcpy(tempArray + index + 1, dArray + index, (size - index) * sizeof(int));	// przekopiowanie zawartosci od zadanego indeksu

			delete[] dArray;				// zwolnienie pamieci zajmowanej przez poprzednia tablice
			dArray = tempArray;				// zaktualizowanie wskaznika na tablice

			return;
		}
	}
}
void DArray::popFront()
{
	if (size > 0)
	{
		size--;
		int *tempArray = new int[size];		// zalokowanie tablicy o nowym rozmiarze

		memcpy(tempArray, dArray + 1, size * sizeof(int));	// przekopiowanie zawartosci z poprzedniej tablicy bez pierwszego elementu

		delete[] dArray;				// zwolnienie pamieci zajmowanej przez poprzednia tablice
		dArray = tempArray;				// zaktualizowanie wskaznika na tablice

		return;
	}
}
void DArray::popBack()
{
	if (size > 0)
	{
		size--;
		int *tempArray = new int[size];		// zalokowanie nowej tablicy o nowym rozmiarze

		memcpy(tempArray, dArray, size * sizeof(int));	// przekopiowanie zawartosci z poprzedniej tablicy oprocz ostatniego elementu

		delete[] dArray;					// zwolnienie pamieci zajmowanej przez poprzednia tablice
		dArray = tempArray;					// zaktualizowanie wskaznika na tablice

		return;
	}
}
void DArray::popAt(int index)
{
	if (index == 0)
		popFront();
	else if (index == size - 1)
		popBack();
	else if (index < size && index > 0)
	{
		size--;
		int *tempArray = new int[size];					// alokacja tablicy o nowym rozmiarze

		memcpy(tempArray, dArray, index * sizeof(int));						 // linie 110,111: przekopiowanie zawartosci z poprzedniej tablicy
		memcpy(tempArray + index + 1, dArray, (size - index) * sizeof(int)); // z pominieciem elementu o zadanym indeksie
		
		delete[] dArray;	// zwolnienie pamieci zajmowanej przez poprzednia tablice
		dArray = tempArray;	// zaktualizowanie wskaznika na tablice
	}
}
void DArray::display()
{
	int *p = dArray;
	int counter = 0;
	while (counter < size)
	{
		std::cout << *p << "|";
		p++;
		counter++;
	}
}
int DArray::lookUpIndex(int index)		// zwrocenie wartosci znajdujacej sie pod danym indeksem w tablicy
{
	if (size == 0)
		std::cout << "Tablica jest pusta. \n";
	else if (index <size && index > 0)
	{
		return *((this->dArray) + index);
	}
	else
	{
		std::cout << "Podano niepoprawny indeks. \n";
	}
}
int DArray::lookUpValue(int value)		// zwrocenie indeksu pierwszego wystapienia zadanej wartosci
{
	if(size == 0)
		return NULL;
	else
	{
		int counter = 0;
		while (counter < size)
		{
			if (*((this->dArray) + counter) == value)
				return counter;
		}
	}
}
DArray::~DArray()
{

}
