#pragma once
class DArray
{
public:

	int* dArray;			
	int size;

	void pushFront(int value);			// Dodawanie na poczatku
	void pushBack(int value);			// Dodawanie na koncu
	void pushAt(int value, int index);	// Dodawanie przed indeksem 

	void popFront();					// Usuwanie poczatku
	void popBack();						// Usuwanie konca
	void popAt(int index);				// Usuwanie elementu przed indeksem

	void display();						// Wyswietlenie
	
	int lookUpIndex(int index);			// Wyszukanie wartosci
	int lookUpValue(int value);			// Zwrocenie wartosci pod indeksem

	DArray(int size);
	~DArray();
};

