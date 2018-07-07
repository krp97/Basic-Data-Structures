#pragma once
#include "NodeDL.h"
class DoublyLinkedList
{
private:

	NodeDL * head;
	NodeDL * tail;

public:

	DoublyLinkedList();

	void pushFront(int value);				// Dodawanie na poczatku
	void pushBack(int value);				// Dodawanie na koncu
	void pushAt(int value, int index);		// Dodawanie przed indeksem 

	void popFront();			// Usuwanie poczatku
	void popBack();				// Usuwanie konca
	void popAt(int index);		// Usuwanie elementu przed indeksem

	int find(int value);		// Wyszukiwanie wartosci

	void display();				// Wyswietlanie

	int getCount();				// Zwrocenie ilosci wezlow

	~DoublyLinkedList();
};

